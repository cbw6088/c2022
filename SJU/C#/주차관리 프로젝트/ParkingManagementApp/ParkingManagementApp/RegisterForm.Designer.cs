namespace ParkingManagementApp
{
    partial class RegisterForm
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
            carNumber = new TextBox();
            label2 = new Label();
            label3 = new Label();
            carModel = new ComboBox();
            registerButton = new Button();
            label4 = new Label();
            groupBox1 = new GroupBox();
            phoneNumber = new TextBox();
            label7 = new Label();
            groupBox2 = new GroupBox();
            freeParkingSpace1F = new Label();
            parkingSpace1F = new Label();
            freeParkingSpace2F = new Label();
            parkingSpace2F = new Label();
            freeParkingSpace3F = new Label();
            parkingSpace3F = new Label();
            freeParkingSpace = new Label();
            label6 = new Label();
            parkingSpace = new Label();
            groupBox3 = new GroupBox();
            label5 = new Label();
            label16 = new Label();
            label15 = new Label();
            label14 = new Label();
            button1 = new Button();
            panel1 = new Panel();
            label9 = new Label();
            groupBox1.SuspendLayout();
            groupBox2.SuspendLayout();
            groupBox3.SuspendLayout();
            panel1.SuspendLayout();
            SuspendLayout();
            // 
            // carNumber
            // 
            carNumber.Location = new Point(122, 59);
            carNumber.Name = "carNumber";
            carNumber.PlaceholderText = "예) 01가1234";
            carNumber.Size = new Size(205, 27);
            carNumber.TabIndex = 1;
            carNumber.TabStop = false;
            // 
            // label2
            // 
            label2.AutoSize = true;
            label2.Location = new Point(36, 59);
            label2.Name = "label2";
            label2.Size = new Size(74, 20);
            label2.TabIndex = 2;
            label2.Text = "차량 번호";
            // 
            // label3
            // 
            label3.AutoSize = true;
            label3.Location = new Point(36, 102);
            label3.Name = "label3";
            label3.Size = new Size(74, 20);
            label3.TabIndex = 3;
            label3.Text = "차량 종류";
            // 
            // carModel
            // 
            carModel.BackColor = SystemColors.Window;
            carModel.FormattingEnabled = true;
            carModel.Items.AddRange(new object[] { "KIA 모닝", "KIA K3", "KIA K5", "KIA K8", "KIA K9", "현대 아반떼", "현대 소나타", "현대 그랜저", "르노 SM6", "르노 XM3", "제네시스 G80", "제네시스 G90", "기타 (경차)", "기타 (중형차)", "기타 (대형차)" });
            carModel.Location = new Point(122, 102);
            carModel.Name = "carModel";
            carModel.Size = new Size(205, 28);
            carModel.TabIndex = 4;
            carModel.TabStop = false;
            carModel.SelectedIndexChanged += carModel_SelectedIndexChanged;
            // 
            // registerButton
            // 
            registerButton.Location = new Point(75, 200);
            registerButton.Name = "registerButton";
            registerButton.Size = new Size(212, 63);
            registerButton.TabIndex = 5;
            registerButton.Text = "등록하기";
            registerButton.UseVisualStyleBackColor = true;
            registerButton.Click += registerButton_Click;
            // 
            // label4
            // 
            label4.AutoSize = true;
            label4.Location = new Point(42, 55);
            label4.Name = "label4";
            label4.Size = new Size(89, 20);
            label4.TabIndex = 6;
            label4.Text = "총 주차공간";
            // 
            // groupBox1
            // 
            groupBox1.Controls.Add(phoneNumber);
            groupBox1.Controls.Add(label7);
            groupBox1.Controls.Add(carNumber);
            groupBox1.Controls.Add(registerButton);
            groupBox1.Controls.Add(label3);
            groupBox1.Controls.Add(carModel);
            groupBox1.Controls.Add(label2);
            groupBox1.Location = new Point(12, 52);
            groupBox1.Name = "groupBox1";
            groupBox1.Size = new Size(363, 296);
            groupBox1.TabIndex = 7;
            groupBox1.TabStop = false;
            groupBox1.Text = "차량 등록하기";
            groupBox1.Enter += groupBox1_Enter;
            // 
            // phoneNumber
            // 
            phoneNumber.Location = new Point(122, 146);
            phoneNumber.Name = "phoneNumber";
            phoneNumber.PlaceholderText = "예) 010-1234-5678";
            phoneNumber.Size = new Size(205, 27);
            phoneNumber.TabIndex = 6;
            phoneNumber.TabStop = false;
            // 
            // label7
            // 
            label7.AutoSize = true;
            label7.Location = new Point(36, 146);
            label7.Name = "label7";
            label7.Size = new Size(74, 20);
            label7.TabIndex = 7;
            label7.Text = "전화 번호";
            // 
            // groupBox2
            // 
            groupBox2.Controls.Add(freeParkingSpace1F);
            groupBox2.Controls.Add(parkingSpace1F);
            groupBox2.Controls.Add(freeParkingSpace2F);
            groupBox2.Controls.Add(parkingSpace2F);
            groupBox2.Controls.Add(freeParkingSpace3F);
            groupBox2.Controls.Add(parkingSpace3F);
            groupBox2.Controls.Add(freeParkingSpace);
            groupBox2.Controls.Add(label6);
            groupBox2.Controls.Add(parkingSpace);
            groupBox2.Controls.Add(label4);
            groupBox2.Location = new Point(405, 52);
            groupBox2.Name = "groupBox2";
            groupBox2.Size = new Size(293, 162);
            groupBox2.TabIndex = 8;
            groupBox2.TabStop = false;
            groupBox2.Text = "주차 타워 정보";
            // 
            // freeParkingSpace1F
            // 
            freeParkingSpace1F.AutoSize = true;
            freeParkingSpace1F.Font = new Font("맑은 고딕", 9F, FontStyle.Bold, GraphicsUnit.Point);
            freeParkingSpace1F.Location = new Point(172, 137);
            freeParkingSpace1F.Name = "freeParkingSpace1F";
            freeParkingSpace1F.Size = new Size(36, 20);
            freeParkingSpace1F.TabIndex = 16;
            freeParkingSpace1F.Text = "000";
            // 
            // parkingSpace1F
            // 
            parkingSpace1F.AutoSize = true;
            parkingSpace1F.Location = new Point(88, 137);
            parkingSpace1F.Name = "parkingSpace1F";
            parkingSpace1F.Size = new Size(78, 20);
            parkingSpace1F.TabIndex = 15;
            parkingSpace1F.Text = "1층 : 000 |";
            // 
            // freeParkingSpace2F
            // 
            freeParkingSpace2F.AutoSize = true;
            freeParkingSpace2F.Font = new Font("맑은 고딕", 9F, FontStyle.Bold, GraphicsUnit.Point);
            freeParkingSpace2F.Location = new Point(172, 110);
            freeParkingSpace2F.Name = "freeParkingSpace2F";
            freeParkingSpace2F.Size = new Size(36, 20);
            freeParkingSpace2F.TabIndex = 14;
            freeParkingSpace2F.Text = "000";
            // 
            // parkingSpace2F
            // 
            parkingSpace2F.AutoSize = true;
            parkingSpace2F.Location = new Point(88, 110);
            parkingSpace2F.Name = "parkingSpace2F";
            parkingSpace2F.Size = new Size(78, 20);
            parkingSpace2F.TabIndex = 13;
            parkingSpace2F.Text = "2층 : 000 |";
            // 
            // freeParkingSpace3F
            // 
            freeParkingSpace3F.AutoSize = true;
            freeParkingSpace3F.Font = new Font("맑은 고딕", 9F, FontStyle.Bold, GraphicsUnit.Point);
            freeParkingSpace3F.Location = new Point(172, 85);
            freeParkingSpace3F.Name = "freeParkingSpace3F";
            freeParkingSpace3F.Size = new Size(36, 20);
            freeParkingSpace3F.TabIndex = 12;
            freeParkingSpace3F.Text = "000";
            // 
            // parkingSpace3F
            // 
            parkingSpace3F.AutoSize = true;
            parkingSpace3F.Location = new Point(88, 85);
            parkingSpace3F.Name = "parkingSpace3F";
            parkingSpace3F.Size = new Size(78, 20);
            parkingSpace3F.TabIndex = 10;
            parkingSpace3F.Text = "3층 : 000 |";
            // 
            // freeParkingSpace
            // 
            freeParkingSpace.AutoSize = true;
            freeParkingSpace.Font = new Font("맑은 고딕", 14F, FontStyle.Bold, GraphicsUnit.Point);
            freeParkingSpace.Location = new Point(183, 23);
            freeParkingSpace.Name = "freeParkingSpace";
            freeParkingSpace.Size = new Size(56, 32);
            freeParkingSpace.TabIndex = 9;
            freeParkingSpace.Text = "000";
            // 
            // label6
            // 
            label6.AutoSize = true;
            label6.Location = new Point(161, 55);
            label6.Name = "label6";
            label6.Size = new Size(104, 20);
            label6.TabIndex = 8;
            label6.Text = "여유 주차공간";
            // 
            // parkingSpace
            // 
            parkingSpace.AutoSize = true;
            parkingSpace.Font = new Font("맑은 고딕", 14F, FontStyle.Bold, GraphicsUnit.Point);
            parkingSpace.Location = new Point(62, 23);
            parkingSpace.Name = "parkingSpace";
            parkingSpace.Size = new Size(56, 32);
            parkingSpace.TabIndex = 7;
            parkingSpace.Text = "000";
            // 
            // groupBox3
            // 
            groupBox3.Controls.Add(label5);
            groupBox3.Controls.Add(label16);
            groupBox3.Controls.Add(label15);
            groupBox3.Controls.Add(label14);
            groupBox3.Location = new Point(402, 220);
            groupBox3.Name = "groupBox3";
            groupBox3.Size = new Size(296, 128);
            groupBox3.TabIndex = 9;
            groupBox3.TabStop = false;
            groupBox3.Text = "주의사항";
            // 
            // label5
            // 
            label5.AutoSize = true;
            label5.Location = new Point(23, 94);
            label5.Name = "label5";
            label5.Size = new Size(187, 20);
            label5.TabIndex = 3;
            label5.Text = "안내사항을 참고해 주세요.";
            // 
            // label16
            // 
            label16.AutoSize = true;
            label16.Location = new Point(23, 47);
            label16.Name = "label16";
            label16.Size = new Size(157, 20);
            label16.TabIndex = 2;
            label16.Text = "주차하실 수 없습니다.";
            // 
            // label15
            // 
            label15.AutoSize = true;
            label15.Location = new Point(6, 23);
            label15.Name = "label15";
            label15.Size = new Size(208, 20);
            label15.TabIndex = 1;
            label15.Text = "1. 트럭, 승합차 등 대형차량은";
            // 
            // label14
            // 
            label14.AutoSize = true;
            label14.Location = new Point(6, 71);
            label14.Name = "label14";
            label14.Size = new Size(180, 20);
            label14.TabIndex = 0;
            label14.Text = "2. 주차요금과 운영시간은";
            // 
            // button1
            // 
            button1.Location = new Point(3, 2);
            button1.Name = "button1";
            button1.Size = new Size(60, 35);
            button1.TabIndex = 10;
            button1.Text = "뒤로";
            button1.UseVisualStyleBackColor = true;
            button1.Click += button1_Click;
            // 
            // panel1
            // 
            panel1.BackColor = SystemColors.ButtonShadow;
            panel1.Controls.Add(label9);
            panel1.Controls.Add(button1);
            panel1.Location = new Point(0, 0);
            panel1.Name = "panel1";
            panel1.Size = new Size(716, 40);
            panel1.TabIndex = 11;
            // 
            // label9
            // 
            label9.AutoSize = true;
            label9.Font = new Font("Microsoft Sans Serif", 16.2F, FontStyle.Bold, GraphicsUnit.Point);
            label9.ForeColor = Color.White;
            label9.Location = new Point(305, 4);
            label9.Name = "label9";
            label9.Size = new Size(106, 32);
            label9.TabIndex = 11;
            label9.Text = "차량 등록";
            // 
            // RegisterForm
            // 
            AutoScaleDimensions = new SizeF(9F, 20F);
            AutoScaleMode = AutoScaleMode.Font;
            BackColor = Color.White;
            ClientSize = new Size(712, 363);
            Controls.Add(panel1);
            Controls.Add(groupBox3);
            Controls.Add(groupBox2);
            Controls.Add(groupBox1);
            Name = "RegisterForm";
            Text = "차량 등록";
            FormClosed += RegisterForm_FormClosed;
            Load += RegisterForm_Load;
            groupBox1.ResumeLayout(false);
            groupBox1.PerformLayout();
            groupBox2.ResumeLayout(false);
            groupBox2.PerformLayout();
            groupBox3.ResumeLayout(false);
            groupBox3.PerformLayout();
            panel1.ResumeLayout(false);
            panel1.PerformLayout();
            ResumeLayout(false);
        }

        #endregion
        private TextBox carNumber;
        private Label label2;
        private Label label3;
        private ComboBox carModel;
        private Button registerButton;
        private Label label4;
        private GroupBox groupBox1;
        private TextBox phoneNumber;
        private Label label7;
        private GroupBox groupBox2;
        private Label freeParkingSpace3F;
        private Label parkingSpace3F;
        private Label freeParkingSpace;
        private Label label6;
        private Label parkingSpace;
        private Label freeParkingSpace2F;
        private Label parkingSpace2F;
        private Label parkingSpace1F;
        private Label freeParkingSpace1F;
        private GroupBox groupBox3;
        private Label label16;
        private Label label15;
        private Label label14;
        private Button button1;
        private Label label5;
        private Panel panel1;
        private Label label9;
    }
}