using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using System.Windows.Forms;

using Ambiesoft;
using System.IO;

namespace AmbLibcppTestCS
{
    static class Program
    {
        //private static System.Reflection.Assembly CustomResolve(
        //    object sender,
        //    System.ResolveEventArgs args)
        //{
        //    if (args.Name.StartsWith("Ambiesoft.AmbLibcpp.x86"))
        //    {
        //        string filename = Path.Combine(AppDomain.CurrentDomain.SetupInformation.ApplicationBase,
        //            "platform",
        //            string.Format("Ambiesoft.AmbLibcpp.{0}.dll",
        //                Environment.Is64BitProcess ? "x64" : "x86"));

        //        return System.Reflection.Assembly.LoadFile(filename);
        //    }
        //    return null;
        //}

        /// <summary>
        /// The main entry point for the application.
        /// </summary>
        [STAThread]
        static void Main()
        {
            // MessageBox.Show(Environment.Is64BitProcess.ToString());

            //CppUtils.testMessageBox("AAA");
            //string folder = CppUtils.GetSelectedFolder(null, "TEST");
            Application.EnableVisualStyles();
            Application.SetCompatibleTextRenderingDefault(false);
            Application.Run(new Form1());
        }
    }
}
