using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace Ambiesoft
{
    public partial class InvisibleForm : Form
    {
        string _src;
        string _dest;
        public int _ret;
        public InvisibleForm(string src, string dest)
        {
            InitializeComponent();

            _src = src;
            _dest = dest;
        }

        delegate void VVDelegate();
        void afterLoad()
        {
            _ret = CppUtils.CopyFile(this.Owner, _src, _dest);
        }
        private void InvisibleForm_Load(object sender, EventArgs e)
        {
            BeginInvoke(new VVDelegate(afterLoad));
        }
    }
}
