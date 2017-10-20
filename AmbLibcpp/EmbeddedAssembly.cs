using System;
using System.Collections.Generic;
using System.Text;
using System.IO;
using System.Reflection;
using System.Security.Cryptography;

class TempAssemblyInfo
{
    public bool _autoDelete;
    long _size;
    DateTime _dtLW;
    public Assembly _assem;
    public string _filename;
    public TempAssemblyInfo(Assembly assem)
    {
        _assem = assem;
    }
    public TempAssemblyInfo(Assembly assem, long size, DateTime dt, string filename)
    {
        _autoDelete = true;
        _assem = assem;
        _size = size;
        _dtLW = dt;
        _filename = filename;
    }
}
/// <summary>
/// A class for loading Embedded Assembly
/// </summary>
public class EmbeddedAssembly
{
    // Version 1.3

    static Dictionary<string, TempAssemblyInfo> dic = null;

    /// <summary>
    /// Load Assembly, DLL from Embedded Resources into memory.
    /// </summary>
    /// <param name="embeddedResource">Embedded Resource string. Example: WindowsFormsApplication1.SomeTools.dll</param>
    /// <param name="fileName">File Name. Example: SomeTools.dll</param>
    public static Assembly Load(string embeddedResource, string fileName)
    {
        if (dic == null)
            dic = new Dictionary<string, TempAssemblyInfo>();

        byte[] ba = null;
        Assembly asm = null;
        Assembly curAsm = Assembly.GetExecutingAssembly();

        using (Stream stm = curAsm.GetManifestResourceStream(embeddedResource))
        {
            // Either the file is not existed or it is not mark as embedded resource
            if (stm == null)
                throw new Exception(embeddedResource + " is not found in Embedded Resources.");

            // Get byte[] from the file from embedded resource
            ba = new byte[(int)stm.Length];
            stm.Read(ba, 0, (int)stm.Length);
            try
            {
                asm = Assembly.Load(ba);

                // Add the assembly/dll into dictionary
                dic.Add(asm.FullName, new TempAssemblyInfo(asm));
                return asm; ;
            }
            catch
            {
                // Purposely do nothing
                // Unmanaged dll or assembly cannot be loaded directly from byte[]
                // Let the process fall through for next part
            }
        }

        // bool fileOk = false;
        string tempFile = "";

        using (SHA1CryptoServiceProvider sha1 = new SHA1CryptoServiceProvider())
        {
            // Get the hash value from embedded DLL/assembly
            string fileHash = BitConverter.ToString(sha1.ComputeHash(ba)).Replace("-", string.Empty);
            
            // Define the temporary storage location of the DLL/assembly
            tempFile = Path.GetTempFileName();// Path.GetTempPath() + fileName;

            //// Determines whether the DLL/assembly is existed or not
            //if (File.Exists(tempFile))
            //{
            //    // Get the hash value of the existed file
            //    byte[] bb = File.ReadAllBytes(tempFile);
            //    string fileHash2 = BitConverter.ToString(sha1.ComputeHash(bb)).Replace("-", string.Empty);

            //    // Compare the existed DLL/assembly with the Embedded DLL/assembly
            //    if (fileHash == fileHash2)
            //    {
            //        // Same file
            //        fileOk = true;
            //    }
            //    else
            //    {
            //        // Not same
            //        fileOk = false;
            //    }
            //}
            //else
            //{
            //    // The DLL/assembly is not existed yet
            //    fileOk = false;
            //}
        }

        // Create the file on disk
        System.IO.File.WriteAllBytes(tempFile, ba);

        
        // Load it into memory
        asm = Assembly.LoadFile(tempFile);

        // Add the loaded DLL/assembly into dictionary
        dic.Add(asm.FullName, new TempAssemblyInfo(asm, 100, DateTime.Now, tempFile));
        return asm;
    }
    /// <summary>
    /// Called at process exit, Delete extracted assembly.
    /// When a app using old assembly, other app using new assembly can not create
    /// a file. So I create a arbitrary name assembly.
    /// Here the assembly I created will be removed.
    /// </summary>
    public static void Unload()
    {
        foreach (TempAssemblyInfo tai in dic.Values)
        {
            try
            {
                if (tai._autoDelete)
                    File.Delete(tai._filename);
            }
            catch
            {

            }
        }
    }
    /// <summary>
    /// Retrieve specific loaded DLL/assembly from memory
    /// </summary>
    /// <param name="assemblyFullName"></param>
    /// <returns></returns>
    public static Assembly Get(string assemblyFullName)
    {
        if (dic == null || dic.Count == 0)
            return null;

        if (dic.ContainsKey(assemblyFullName))
            return dic[assemblyFullName]._assem;

        return null;

        // Don't throw Exception if the dictionary does not contain the requested assembly.
        // This is because the event of AssemblyResolve will be raised for every
        // Embedded Resources (such as pictures) of the projects.
        // Those resources wil not be loaded by this class and will not exist in dictionary.
    }
}