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
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(636, 277);
            this.Controls.Add(this.btnTestCopy);
            this.Controls.Add(this.btnPractical);
            this.Controls.Add(this.btnNull);
            this.Name = "Form1";
            this.Text = "Form1";
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Button btnNull;
        private System.Windows.Forms.Button btnPractical;
        private System.Windows.Forms.Button btnTestCopy;
    }
}

