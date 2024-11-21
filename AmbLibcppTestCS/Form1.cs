using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Diagnostics;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using Ambiesoft;
namespace AmbLibcppTestCS
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void btnNull_Click(object sender, EventArgs e)
        {
            CppUtils.CenteredMessageBox("AAA", ProductName);
        }

        private void btnPractical_Click(object sender, EventArgs e)
        {
            //CppUtils.CenteredMessageBox("Are you sure to center the Messagebox?",
            //    ProductName,
            //    MessageBoxButtons.YesNo,
            //    MessageBoxIcon.Information,
            //    MessageBoxDefaultButton.Button2);
        }

        bool IsSameFileContent(string f1, string f2)
        {
            string s1 = File.ReadAllText(f1);
            string s2 = File.ReadAllText(f2);

            return s1 == s2;
        }

        int rnd_ = 1;
        string MyTickString()
        {
            return ((++rnd_) + Environment.TickCount).ToString();
        }
        private void btnTestCopy_Click(object sender, EventArgs e)
        {
            {
                string newfile = Path.Combine(Path.GetDirectoryName(Application.ExecutablePath),
                    MyTickString());
                Debug.Assert(!File.Exists(newfile));

                string content = MyTickString() + " " + MyTickString();

                File.WriteAllText(newfile, content);
                Debug.Assert(File.Exists(newfile));

                string copied = Path.Combine(Path.GetDirectoryName(Application.ExecutablePath),
                    MyTickString());
                Debug.Assert(!File.Exists(copied));

                CppUtils.CopyFile(newfile, copied);
                Debug.Assert(File.Exists(newfile));
                Debug.Assert(File.Exists(copied));

                string orgContent = File.ReadAllText(newfile);
                string cpContent = File.ReadAllText(copied);
                Debug.Assert(orgContent == cpContent);

                CppUtils.DeleteFile(newfile);
                CppUtils.DeleteFile(copied);
                Debug.Assert(!File.Exists(newfile));
                Debug.Assert(!File.Exists(copied));
            }
            {
                string newfile1 = Path.Combine(Path.GetDirectoryName(Application.ExecutablePath),
                    MyTickString());
                Debug.Assert(!File.Exists(newfile1));
                string newfile2 = Path.Combine(Path.GetDirectoryName(Application.ExecutablePath),
                    MyTickString());
                Debug.Assert(!File.Exists(newfile2));

                string content1 = MyTickString() + " " + MyTickString();
                string content2 = MyTickString() + " " + MyTickString();


                File.WriteAllText(newfile1, content1);
                File.WriteAllText(newfile2, content2);

                Debug.Assert(File.Exists(newfile1));
                Debug.Assert(File.Exists(newfile2));

                string cpDir = Path.Combine(Path.GetDirectoryName(Application.ExecutablePath),
                    MyTickString());
                Debug.Assert(!File.Exists(cpDir));
                Debug.Assert(!Directory.Exists(cpDir));
                Directory.CreateDirectory(cpDir);
                Debug.Assert(Directory.Exists(cpDir));

                string cpFile1 = Path.Combine(cpDir, Path.GetFileName(newfile1));
                string cpFile2 = Path.Combine(cpDir, Path.GetFileName(newfile2));

                string[] newFiles = new string[]
                {
                    newfile1,newfile2
                };
                string[] cpDirs = new string[]
                {
                    cpFile1,cpFile2
                };
                CppUtils.CopyFiles(newFiles, cpDirs);

                Debug.Assert(File.Exists(cpFile1));
                Debug.Assert(File.Exists(cpFile2));

                Debug.Assert(IsSameFileContent(newfile1, cpFile1));
                Debug.Assert(IsSameFileContent(newfile2, cpFile2));
            }
        }

        private void btnOpenFolder_Click(object sender, EventArgs e)
        {
            CppUtils.OpenFolder(this, @"C:\T\testfile.txt");
        }

        private void btnNativeVersion_Click(object sender, EventArgs e)
        {
            CppUtils.Info(CppUtils.GetNativeVersionString(Application.ExecutablePath));
        }

        private void btnSelectFolder_Click(object sender, EventArgs e)
        {
            string folder = CppUtils.GetSelectedFolder(this, "test title", txtInitialDir.Text);
            if (!string.IsNullOrEmpty(folder))
                txtInitialDir.Text = folder;
        }

        private void btnTestMove_Click(object sender, EventArgs e)
        {
            {
                string newfile = Path.Combine(Path.GetDirectoryName(Application.ExecutablePath),
                    MyTickString());
                Debug.Assert(!File.Exists(newfile));

                string content = MyTickString() + " " + MyTickString();

                File.WriteAllText(newfile, content);
                Debug.Assert(File.Exists(newfile));

                string moved = Path.Combine(Path.GetDirectoryName(Application.ExecutablePath),
                    MyTickString());
                Debug.Assert(!File.Exists(moved));

                CppUtils.MoveFile(newfile, moved);
                Debug.Assert(!File.Exists(newfile));
                Debug.Assert(File.Exists(moved));

                string mvContent = File.ReadAllText(moved);
                Debug.Assert(content == mvContent);

                CppUtils.DeleteFile(moved);
                Debug.Assert(!File.Exists(moved));
            }
            {
                string newfile1 = Path.Combine(Path.GetDirectoryName(Application.ExecutablePath),
                    MyTickString());
                Debug.Assert(!File.Exists(newfile1));
                string newfile2 = Path.Combine(Path.GetDirectoryName(Application.ExecutablePath),
                    MyTickString());
                Debug.Assert(!File.Exists(newfile2));

                string content1 = MyTickString() + " " + MyTickString();
                string content2 = MyTickString() + " " + MyTickString();


                File.WriteAllText(newfile1, content1);
                File.WriteAllText(newfile2, content2);

                Debug.Assert(File.Exists(newfile1));
                Debug.Assert(File.Exists(newfile2));

                string mvDir = Path.Combine(Path.GetDirectoryName(Application.ExecutablePath),
                    MyTickString());
                Debug.Assert(!File.Exists(mvDir));
                Debug.Assert(!Directory.Exists(mvDir));
                Directory.CreateDirectory(mvDir);
                Debug.Assert(Directory.Exists(mvDir));

                string mvFile1 = Path.Combine(mvDir, Path.GetFileName(newfile1));
                string mvFile2 = Path.Combine(mvDir, Path.GetFileName(newfile2));

                string[] newFiles = new string[]
                {
                    newfile1,newfile2
                };
                string[] mvDirs = new string[]
                {
                    mvFile1,mvFile2
                };
                CppUtils.MoveFiles(newFiles, mvDirs);

                Debug.Assert(!File.Exists(newfile1));
                Debug.Assert(!File.Exists(newfile2));
                Debug.Assert(File.Exists(mvFile1));
                Debug.Assert(File.Exists(mvFile2));

                string mvCont1 = File.ReadAllText(mvFile1);
                string mvCont2 = File.ReadAllText(mvFile2);
                Debug.Assert(content1 == mvCont1);
                Debug.Assert(content2 == mvCont2);
            }

        }

        private void btnOpenSelectedFile_Click(object sender, EventArgs e)
        {
            CppUtils.OpenFolder(this,
                Application.ExecutablePath);
        }
    }
}
