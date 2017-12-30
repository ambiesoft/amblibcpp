using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
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

        private void btnTestCopy_Click(object sender, EventArgs e)
        {

        }

        private void btnOpenFolder_Click(object sender, EventArgs e)
        {
            CppUtils.OpenFolder(this, @"C:\T\testfile.txt");
        }
    }
}
