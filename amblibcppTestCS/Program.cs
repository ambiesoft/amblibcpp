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
            Ambiesoft.AmblibCppStub.init();
            return null;
        }


        /// <summary>
        /// The main entry point for the application.
        /// </summary>
        [STAThread]
        static void Main()
        {
            System.AppDomain.CurrentDomain.AssemblyResolve += CustomResolve;
            Ambiesoft.AmblibCppStub.init();

            Ambiesoft.CppUtils.donothing();
            Application.EnableVisualStyles();
            Application.SetCompatibleTextRenderingDefault(false);
            Application.Run(new Form1());
        }
    }
}
