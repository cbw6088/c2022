namespace ParkingManagementApp
{
    partial class ManagementPass
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
            label1 = new Label();
            loginButton = new Button();
            managerNumber = new TextBox();
            label2 = new Label();
            managerPassword = new TextBox();
            panel1 = new Panel();
            label9 = new Label();
            Back_Button = new Button();
            panel1.SuspendLayout();
            SuspendLayout();
            // 
            // label1
            // 
            label1.AutoSize = true;
            label1.Location = new Point(13, 82);
            label1.Margin = new Padding(4, 0, 4, 0);
            label1.Name = "label1";
            label1.Size = new Size(89, 20);
            label1.TabIndex = 0;
            label1.Text = "관리자 번호";
            // 
            // loginButton
            // 
            loginButton.Location = new Point(19, 166);
            loginButton.Margin = new Padding(4);
            loginButton.Name = "loginButton";
            loginButton.Size = new Size(262, 48);
            loginButton.TabIndex = 1;
            loginButton.Text = "로그인";
            loginButton.UseVisualStyleBackColor = true;
            loginButton.Click += loginButton_Click;
            // 
            // managerNumber
            // 
            managerNumber.Location = new Point(111, 75);
            managerNumber.Margin = new Padding(4);
            managerNumber.Name = "managerNumber";
            managerNumber.Size = new Size(164, 27);
            managerNumber.TabIndex = 2;
            // 
            // label2
            // 
            label2.AutoSize = true;
            label2.Location = new Point(13, 117);
            label2.Margin = new Padding(4, 0, 4, 0);
            label2.Name = "label2";
            label2.Size = new Size(89, 20);
            label2.TabIndex = 3;
            label2.Text = "관리자 암호";
            // 
            // managerPassword
            // 
            managerPassword.Location = new Point(110, 114);
            managerPassword.Margin = new Padding(4);
            managerPassword.Name = "managerPassword";
            managerPassword.PasswordChar = '*';
            managerPassword.Size = new Size(165, 27);
            managerPassword.TabIndex = 4;
            // 
            // panel1
            // 
            panel1.BackColor = SystemColors.ButtonShadow;
            panel1.Controls.Add(Back_Button);
            panel1.Controls.Add(label9);
            panel1.Location = new Point(0, 0);
            panel1.Name = "panel1";
            panel1.Size = new Size(312, 40);
            panel1.TabIndex = 5;
            // 
            // label9
            // 
            label9.AutoSize = true;
            label9.Font = new Font("Microsoft Sans Serif", 13.8F, FontStyle.Bold, GraphicsUnit.Point);
            label9.ForeColor = Color.White;
            label9.Location = new Point(90, 5);
            label9.Name = "label9";
            label9.Size = new Size(146, 29);
            label9.TabIndex = 20;
            label9.Text = "관리자 로그인";
            label9.TextAlign = ContentAlignment.TopCenter;
            // 
            // Back_Button
            // 
            Back_Button.Location = new Point(3, 2);
            Back_Button.Name = "Back_Button";
            Back_Button.Size = new Size(60, 35);
            Back_Button.TabIndex = 17;
            Back_Button.Text = "뒤로";
            Back_Button.UseVisualStyleBackColor = true;
            Back_Button.Click += Back_Button_Click;
            // 
            // ManagementPass
            // 
            AutoScaleDimensions = new SizeF(9F, 20F);
            AutoScaleMode = AutoScaleMode.Font;
            ClientSize = new Size(294, 239);
            Controls.Add(panel1);
            Controls.Add(managerPassword);
            Controls.Add(label2);
            Controls.Add(managerNumber);
            Controls.Add(loginButton);
            Controls.Add(label1);
            Margin = new Padding(4);
            Name = "ManagementPass";
            Text = "관리자 로그인";
            FormClosed += MngPass_FormClosed;
            Load += ManagementPass_Load;
            panel1.ResumeLayout(false);
            panel1.PerformLayout();
            ResumeLayout(false);
            PerformLayout();
        }

        #endregion

        private Label label1;
        private Button loginButton;
        private TextBox managerNumber;
        private Label label2;
        private TextBox managerPassword;
        private TextBox textBox1;
        private Panel panel1;
        private Label label9;
        private Button Back_Button;
    }
}