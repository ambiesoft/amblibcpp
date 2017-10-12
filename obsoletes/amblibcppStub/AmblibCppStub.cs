using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Ambiesoft
{
    public class AmblibCppStub
    {
        private static System.Reflection.Assembly CustomResolve(
        object sender,
        System.ResolveEventArgs args)
        {
            if (args.Name.StartsWith("library"))
            {
                string fileName = System.IO.Path.GetFullPath(
                    "platform\\"
                    + System.Environment.GetEnvironmentVariable("PROCESSOR_ARCHITECTURE")
                    + "\\library.dll");
                System.Console.WriteLine(fileName);
                if (System.IO.File.Exists(fileName))
                {
                    return System.Reflection.Assembly.LoadFile(fileName);
                }
            }
            return null;
        }

        static AmblibCppStub()
        {
            System.AppDomain.CurrentDomain.AssemblyResolve += CustomResolve;
        }

        public static void init()
        {

        }
    }
}
