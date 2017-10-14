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
            this.SuspendLayout();
            // 
            // btnNull
            // 
            this.btnNull.Location = new System.Drawing.Point(35, 25);
            this.btnNull.Name = "btnNull";
            this.btnNull.Size = new System.Drawing.Size(75, 23);
            this.btnNull.TabIndex = 0;
            this.btnNull.Text = "null";
            this.btnNull.UseVisualStyleBackColor = true;
            this.btnNull.Click += new System.EventHandler(this.btnNull_Click);
            // 
            // btnPractical
            // 
            this.btnPractical.Location = new System.Drawing.Point(35, 70);
            this.btnPractical.Name = "btnPractical";
            this.btnPractical.Size = new System.Drawing.Size(75, 23);
            this.btnPractical.TabIndex = 1;
            this.btnPractical.Text = "Practical";
            this.btnPractical.UseVisualStyleBackColor = true;
            this.btnPractical.Click += new System.EventHandler(this.btnPractical_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(636, 256);
            this.Controls.Add(this.btnPractical);
            this.Controls.Add(this.btnNull);
            this.Name = "Form1";
            this.Text = "Form1";
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Button btnNull;
        private System.Windows.Forms.Button btnPractical;
    }
}

