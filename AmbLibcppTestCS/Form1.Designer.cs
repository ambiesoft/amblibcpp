namespace AmbLibcppTestCS
{
    partial class Form1
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.btnNull = new System.Windows.Forms.Button();
            this.btnPractical = new System.Windows.Forms.Button();
            this.btnTestCopy = new System.Windows.Forms.Button();
            this.btnOpenFolder = new System.Windows.Forms.Button();
            this.btnNativeVersion = new System.Windows.Forms.Button();
            this.txtInitialDir = new System.Windows.Forms.TextBox();
            this.btnSelectFolder = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // btnNull
            // 
            this.btnNull.Location = new System.Drawing.Point(35, 27);
            this.btnNull.Name = "btnNull";
            this.btnNull.Size = new System.Drawing.Size(75, 25);
            this.btnNull.TabIndex = 0;
            this.btnNull.Text = "null";
            this.btnNull.UseVisualStyleBackColor = true;
            this.btnNull.Click += new System.EventHandler(this.btnNull_Click);
            // 
            // btnPractical
            // 
            this.btnPractical.Location = new System.Drawing.Point(35, 76);
            this.btnPractical.Name = "btnPractical";
            this.btnPractical.Size = new System.Drawing.Size(75, 25);
            this.btnPractical.TabIndex = 1;
            this.btnPractical.Text = "Practical";
            this.btnPractical.UseVisualStyleBackColor = true;
            this.btnPractical.Click += new System.EventHandler(this.btnPractical_Click);
            // 
            // btnTestCopy
            // 
            this.btnTestCopy.Location = new System.Drawing.Point(35, 164);
            this.btnTestCopy.Name = "btnTestCopy";
            this.btnTestCopy.Size = new System.Drawing.Size(75, 23);
            this.btnTestCopy.TabIndex = 2;
            this.btnTestCopy.Text = "Test Copy";
            this.btnTestCopy.UseVisualStyleBackColor = true;
            this.btnTestCopy.Click += new System.EventHandler(this.btnTestCopy_Click);
            // 
            // btnOpenFolder
            // 
            this.btnOpenFolder.Location = new System.Drawing.Point(35, 220);
            this.btnOpenFolder.Name = "btnOpenFolder";
            this.btnOpenFolder.Size = new System.Drawing.Size(126, 23);
            this.btnOpenFolder.TabIndex = 3;
            this.btnOpenFolder.Text = "Open C-T";
            this.btnOpenFolder.UseVisualStyleBackColor = true;
            this.btnOpenFolder.Click += new System.EventHandler(this.btnOpenFolder_Click);
            // 
            // btnNativeVersion
            // 
            this.btnNativeVersion.Location = new System.Drawing.Point(225, 27);
            this.btnNativeVersion.Name = "btnNativeVersion";
            this.btnNativeVersion.Size = new System.Drawing.Size(75, 23);
            this.btnNativeVersion.TabIndex = 4;
            this.btnNativeVersion.Text = "native vertion";
            this.btnNativeVersion.UseVisualStyleBackColor = true;
            this.btnNativeVersion.Click += new System.EventHandler(this.btnNativeVersion_Click);
            // 
            // txtInitialDir
            // 
            this.txtInitialDir.Location = new System.Drawing.Point(371, 207);
            this.txtInitialDir.Name = "txtInitialDir";
            this.txtInitialDir.Size = new System.Drawing.Size(229, 20);
            this.txtInitialDir.TabIndex = 5;
            // 
            // btnSelectFolder
            // 
            this.btnSelectFolder.Location = new System.Drawing.Point(371, 233);
            this.btnSelectFolder.Name = "btnSelectFolder";
            this.btnSelectFolder.Size = new System.Drawing.Size(229, 23);
            this.btnSelectFolder.TabIndex = 6;
            this.btnSelectFolder.Text = "&Select Folder...";
            this.btnSelectFolder.UseVisualStyleBackColor = true;
            this.btnSelectFolder.Click += new System.EventHandler(this.btnSelectFolder_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(636, 277);
            this.Controls.Add(this.btnSelectFolder);
            this.Controls.Add(this.txtInitialDir);
            this.Controls.Add(this.btnNativeVersion);
            this.Controls.Add(this.btnOpenFolder);
            this.Controls.Add(this.btnTestCopy);
            this.Controls.Add(this.btnPractical);
            this.Controls.Add(this.btnNull);
            this.Name = "Form1";
            this.Text = "Form1";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button btnNull;
        private System.Windows.Forms.Button btnPractical;
        private System.Windows.Forms.Button btnTestCopy;
        private System.Windows.Forms.Button btnOpenFolder;
        private System.Windows.Forms.Button btnNativeVersion;
        private System.Windows.Forms.TextBox txtInitialDir;
        private System.Windows.Forms.Button btnSelectFolder;
    }
}

