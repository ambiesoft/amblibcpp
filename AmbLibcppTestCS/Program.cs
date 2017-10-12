using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace amblibcppTestCS
{
    static class Program
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

        /// <summary>
        /// The main entry point for the application.
        /// </summary>
        [STAThread]
        static void Main()
        {
            System.AppDomain.CurrentDomain.AssemblyResolve += CustomResolve;

            Application.EnableVisualStyles();
            Application.SetCompatibleTextRenderingDefault(false);
            Application.Run(new Form1());
        }
    }
}
