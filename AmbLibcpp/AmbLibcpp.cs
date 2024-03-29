﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Reflection;
using System.Text;
using System.Windows.Forms;
namespace Ambiesoft
{
    public enum CPPUTIL_MOVEWINDOWTYPE
    {
        TOPLEFT,
        TOPRIGHT,
        BOTTOMLEFT,
        BOTTOMRIGHT,
    };

    class Loader
    {
        static Loader()
        {
            AppDomain.CurrentDomain.AssemblyResolve += new ResolveEventHandler(CurrentDomain_AssemblyResolve);
        }
        static System.Reflection.Assembly CurrentDomain_AssemblyResolve(object sender, ResolveEventArgs args)
        {
            //Ambiesoft.Natives.x64.Ambiesoft.AmbLibcpp.platform.x64.dll
            string name = args.Name.Split(',')[0];
            if (name.StartsWith("Ambiesoft.AmbLibcpp.platform"))
            {
                string filename = string.Format("Ambiesoft.AmbLibcpp.platform.{0}.dll",
                    Environment.Is64BitProcess ? "x64" : "x86");

                string embeddedPath = string.Format("{0}.{1}.{2}.{3}",
                    typeof(CppUtils).Namespace,
                    "Natives",
                    Environment.Is64BitProcess ? "x64" : "x86",
                    filename);

                return EmbeddedAssembly.Load(embeddedPath, filename);
            }
            return null;
        }

        static bool prepared_ = false;
        static internal void Prepare()
        {
            if (prepared_)
                return;

            prepared_ = true;
        }
    }
    public class CppUtils
    {
        static CppUtils()
        {
            Loader.Prepare();
        }


        public static bool moveWindowSpecific(Form f, CPPUTIL_MOVEWINDOWTYPE type)
        {
            return platform.CppUtils.moveWindowSpecific(f, (platform.CPPUTIL_MOVEWINDOWTYPE)type);
        }
        public static string humanReadableByteCount(UInt64 len)
        {
            return platform.CppUtils.humanReadableByteCount(len);
        }

        public static int CopyFile(IWin32Window win, string src, string dest)
        {
            return platform.CppUtils.CopyFile(win, src, dest);
        }
        public static int CopyFile(string src, string dest)
        {
            return CopyFile(null, src, dest);
        }

        // NOT WORK (not become modal)
        private static int ModalCopyFile(Form form, string src, string dest)
        {
            using (InvisibleForm invForm = new InvisibleForm(src, dest))
            {
                invForm.Owner = form;
                invForm.ShowDialog();
                return invForm._ret;
            }
        }
        public static int MoveFile(IWin32Window win, string src, string dest)
        {
            return platform.CppUtils.MoveFile(win, src, dest);
        }
        public static int MoveFile(string src, string dest)
        {
            return MoveFile(null, src, dest);
        }

        public static int DeleteFile(IWin32Window win, string file)
        {
            return platform.CppUtils.DeleteFile(win, file);
        }
        public static int DeleteFile(string file)
        {
            return DeleteFile(null, file);
        }

        public static int CopyFiles(IWin32Window win, string[] froms, string[] tos)
        {
            return platform.CppUtils.CopyFiles(win, froms, tos);
        }
        public static int CopyFiles(string[] froms, string[] tos)
        {
            return CopyFiles(null, froms, tos);
        }

        public static int MoveFiles(IWin32Window win, string[] froms, string[] tos)
        {
            return platform.CppUtils.MoveFiles(win, froms, tos);
        }
        public static int MoveFiles(string[] froms, string[] tos)
        {
            return MoveFiles(null, froms, tos);
        }

        public static int DeleteFiles(IWin32Window win, string[] files)
        {
            return platform.CppUtils.DeleteFiles(win, files);
        }
        public static int DeleteFiles(string[] files)
        {
            return DeleteFiles(null, files);
        }

        public static bool MoveFileAtomic(List<KeyValuePair<string, string>> srcdests)
        {
            return platform.CppUtils.MoveFileAtomic(srcdests);
        }

        public static bool WriteAlternate(string filename, string alterpath, byte[] data)
        {
            return platform.CppUtils.WriteAlternate(filename, alterpath, data);
        }
        public static bool ReadAlternate(string filename, string alterpath, ref byte[] data)
        {
            return platform.CppUtils.ReadAlternate(filename, alterpath, ref data);
        }

        public static string getMimeTypeFromExtention(string ext)
        {
            return platform.CppUtils.getMimeTypeFromExtention(ext);
        }

        public static void testMessageBox(string message)
        {
            platform.CppUtils.testMessageBox(message);
        }

        public static DialogResult CenteredMessageBox(
            IWin32Window owner,
            string text,
            string caption,
            MessageBoxButtons buttons,
            MessageBoxIcon icon,
            MessageBoxDefaultButton defaultButton)
        {
            return platform.CppUtils.CenteredMessageBox(
                owner,
                text,
                caption,
                buttons,
                icon,
                defaultButton);
        }
        public static DialogResult CenteredMessageBox(
            IWin32Window owner,
            string text,
            string caption,
            MessageBoxButtons buttons,
            MessageBoxIcon icon)
        {
            return CenteredMessageBox(
                owner,
                text,
                caption,
                buttons,
                icon,
                MessageBoxDefaultButton.Button1);
        }
        public static DialogResult CenteredMessageBox(
            IWin32Window owner,
            string text,
            string caption,
            MessageBoxButtons buttons)
        {
            return CenteredMessageBox(
                owner,
                text,
                caption,
                buttons,
                MessageBoxIcon.None);
        }
        public static DialogResult CenteredMessageBox(
            IWin32Window owner,
            string text,
            string caption)
        {
            return CenteredMessageBox(
                owner,
                text,
                caption,
                MessageBoxButtons.OK);
        }
        public static DialogResult CenteredMessageBox(
            IWin32Window owner,
            string text)
        {
            return CenteredMessageBox(
                owner,
                text,
                String.Empty);
        }


        // no owner
        public static DialogResult CenteredMessageBox(
            string text,
            string caption,
            MessageBoxButtons buttons,
            MessageBoxIcon icon,
            MessageBoxDefaultButton defaultButton)
        {
            return CenteredMessageBox(
                null,
                text,
                caption,
                buttons,
                icon,
                defaultButton);
        }
        public static DialogResult CenteredMessageBox(
            string text,
            string caption,
            MessageBoxButtons buttons,
            MessageBoxIcon icon)
        {
            return CenteredMessageBox(
                null,
                text,
                caption,
                buttons,
                icon,
                MessageBoxDefaultButton.Button1);
        }
        public static DialogResult CenteredMessageBox(
            string text,
            string caption,
            MessageBoxButtons buttons)
        {
            return CenteredMessageBox(
                null,
                text,
                caption,
                buttons,
                MessageBoxIcon.None);
        }
        public static DialogResult CenteredMessageBox(
            string text,
            string caption)
        {
            return CenteredMessageBox(
                null,
                text,
                caption,
                MessageBoxButtons.OK);
        }
        public static DialogResult CenteredMessageBox(
            string text)
        {
            return CenteredMessageBox(
                null,
                text,
                String.Empty);
        }



        public static DialogResult Info(IWin32Window owner, string text)
        {
            return CenteredMessageBox(
                owner,
                text,
                Application.ProductName,
                MessageBoxButtons.OK,
                MessageBoxIcon.Information);
        }
        public static DialogResult Info(string text)
        {
            return Info(null, text);
        }



        public static DialogResult Alert(IWin32Window owner, string text)
        {
            return CenteredMessageBox(
                owner,
                text,
                Application.ProductName,
                MessageBoxButtons.OK,
                MessageBoxIcon.Warning);
        }
        public static DialogResult Alert(string text)
        {
            return Alert(null, text);
        }
        
        public static DialogResult Alert(IWin32Window owner, Exception ex)
        {
            return Alert(owner, ex.Message);
        }
        public static DialogResult Alert(Exception ex)
        {
            return Alert(null, ex);
        }











        public static DialogResult Fatal(IWin32Window owner, string text)
        {
            return CenteredMessageBox(
                owner,
                text,
                Application.ProductName,
                MessageBoxButtons.OK,
                MessageBoxIcon.Error);
        }
        public static DialogResult Fatal(string text)
        {
            return Fatal(null, text);
        }

        public static DialogResult Fatal(IWin32Window owner, Exception ex)
        {
            return Fatal(owner, ex.Message);
        }
        public static DialogResult Fatal(Exception ex)
        {
            return Fatal(null, ex);
        }










        public static DialogResult YesOrNo(IWin32Window owner, string text, MessageBoxDefaultButton defbutton)
        {
            return CenteredMessageBox(
                       owner,
                       text,
                       Application.ProductName,
                       MessageBoxButtons.YesNo,
                       MessageBoxIcon.Question,
                       defbutton);
        }
        public static DialogResult YesOrNo(string text)
        {
            return YesOrNo(null, text, MessageBoxDefaultButton.Button1);
        }
        public static DialogResult YesOrNo(string text,MessageBoxDefaultButton defbutton)
        {
            return YesOrNo(null, text, defbutton);
        }

        public static string GetSelectedFolder(IWin32Window win, string title)
        {
            return platform.CppUtils.GetSelectedFolder(win, title);
        }
        public static string GetSelectedFolder(IWin32Window win, string title, string folder)
        {
            return platform.CppUtils.GetSelectedFolder(win, title, folder);
        }

        public static void OpenFolder(IWin32Window win, string path)
        {
            platform.CppUtils.OpenFolder(win,path);
        }
        public static string GetShortFileName(string longname)
        {
            return platform.CppUtils.GetShortFileName(longname);
        }

        public static string GetNativeVersionString(string filename)
        {
            return platform.CppUtils.GetNativeVersionString(filename);
        }
        public static string GetNativeVersionString(string filename, int keta)
        {
            return platform.CppUtils.GetNativeVersionString(filename, keta);
        }

        public static bool AmbSetProcessDPIAware()
        {
            return platform.CppUtils.AmbSetProcessDPIAware();
        }

        public static bool CreateDesktopShortcut(IWin32Window win, string title, string exe)
        {
            return platform.CppUtils.CreateDesktopShortcut(win, title, exe);
        }
        public static bool OpenCommon(IWin32Window win, string exe, string command)
        {
            return platform.CppUtils.OpenCommon(win, exe, command);
        }
        public static string getWindowDebugString(IntPtr ptrwin)
        {
            return platform.CppUtils.getWindowDebugString(ptrwin);
        }
        public static string getWindowDebugString(IWin32Window win)
        {
            return platform.CppUtils.getWindowDebugString(win);
        }
        public static bool IsCtrlPressed()
        {
            return platform.CppUtils.IsCtrlPressed();
        }
        public static bool MakeRichEditFontPersist(System.Windows.Forms.RichTextBox richTextBox)
        {
            return platform.CppUtils.MakeRichEditFontPersist(richTextBox);
        }
    }

    public class CenteringDialog : IDisposable
    {
        static CenteringDialog()
        {
            Loader.Prepare();
        }

        platform.CenteringDialog mem;
        bool disposed;
        public CenteringDialog(IWin32Window owner)
        {
            mem = new platform.CenteringDialog(owner);
        }
        public void Dispose()
        {
            // Dispose of unmanaged resources.
            Dispose(true);
            // Suppress finalization.
            GC.SuppressFinalize(this);
        }
        // Protected implementation of Dispose pattern.
        protected virtual void Dispose(bool disposing)
        {
            if (disposed)
                return;

            if (disposing)
            {
                mem.Dispose();
                // Free any other managed objects here.
                //
            }

            // Free any unmanaged objects here.
            //
            disposed = true;
        }
    };

}
