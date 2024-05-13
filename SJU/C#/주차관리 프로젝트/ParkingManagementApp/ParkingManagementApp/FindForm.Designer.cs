namespace ParkingManagementApp
{
    partial class FindForm : Form
    {
        /// <summary>
        ///  Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        ///  Clean up any resources being used.
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
        ///  Required method for Designer support - do not modify
        ///  the contents of this method with the code editor.
        /// </summary>
        /// 

        private void InitializeComponent()
        {
            Car_Info = new TextBox();
            Car_Number = new Label();
            pMain = new GroupBox();
            Model_Info = new ComboBox();
            Car_Model = new Label();
            Phone_Info = new TextBox();
            Find_Button = new Button();
            Phone_Number = new Label();
            Payment_Info = new GroupBox();
            Pay10 = new Label();
            Pay30 = new Label();
            Min10 = new Label();
            label3 = new Label();
            tableLayoutPanel1 = new TableLayoutPanel();
            tableLayoutPanel2 = new TableLayoutPanel();
            label4 = new Label();
            Infomation = new GroupBox();
            Info3 = new Label();
            Info2 = new Label();
            Info1 = new Label();
            Back_Button = new Button();
            panel1 = new Panel();
            label9 = new Label();
            pMain.SuspendLayout();
            Payment_Info.SuspendLayout();
            Infomation.SuspendLayout();
            panel1.SuspendLayout();
            SuspendLayout();
            // 
            // Car_Info
            // 
            Car_Info.Location = new Point(112, 54);
            Car_Info.Name = "Car_Info";
            Car_Info.PlaceholderText = "예) 01가1234";
            Car_Info.Size = new Size(203, 27);
            Car_Info.TabIndex = 1;
            Car_Info.TabStop = false;
            Car_Info.TextChanged += Car_Number_TextChanged;
            // 
            // Car_Number
            // 
            Car_Number.AutoSize = true;
            Car_Number.Location = new Point(26, 54);
            Car_Number.Name = "Car_Number";
            Car_Number.Size = new Size(74, 20);
            Car_Number.TabIndex = 2;
            Car_Number.Text = "차량 번호";
            // 
            // pMain
            // 
            pMain.Controls.Add(Model_Info);
            pMain.Controls.Add(Car_Model);
            pMain.Controls.Add(Phone_Info);
            pMain.Controls.Add(Find_Button);
            pMain.Controls.Add(Phone_Number);
            pMain.Controls.Add(Car_Info);
            pMain.Controls.Add(Car_Number);
            pMain.Location = new Point(12, 52);
            pMain.Name = "pMain";
            pMain.Size = new Size(355, 296);
            pMain.TabIndex = 7;
            pMain.TabStop = false;
            pMain.Text = "주차 조회하기";
            pMain.Enter += pMain_Enter;
            // 
            // Model_Info
            // 
            Model_Info.BackColor = SystemColors.Window;
            Model_Info.FormattingEnabled = true;
            Model_Info.Items.AddRange(new object[] { "KIA 모닝", "KIA K3", "KIA K5", "KIA K8", "KIA K9", "현대 아반떼", "현대 소나타", "현대 그랜저", "르노 SM6", "르노 XM3", "제네시스 G80", "제네시스 G90", "기타 (경차)", "기타 (중형차)", "기타 (대형차)" });
            Model_Info.Location = new Point(112, 102);
            Model_Info.Name = "Model_Info";
            Model_Info.Size = new Size(205, 28);
            Model_Info.TabIndex = 13;
            Model_Info.TabStop = false;
            // 
            // Car_Model
            // 
            Car_Model.AutoSize = true;
            Car_Model.Location = new Point(26, 102);
            Car_Model.Name = "Car_Model";
            Car_Model.Size = new Size(74, 20);
            Car_Model.TabIndex = 12;
            Car_Model.Text = "차량 종류";
            // 
            // Phone_Info
            // 
            Phone_Info.Location = new Point(112, 150);
            Phone_Info.Name = "Phone_Info";
            Phone_Info.PlaceholderText = "예) 010-1234-5678";
            Phone_Info.Size = new Size(203, 27);
            Phone_Info.TabIndex = 9;
            Phone_Info.TabStop = false;
            Phone_Info.TextChanged += Phone_number_TextChanged;
            // 
            // Find_Button
            // 
            Find_Button.Location = new Point(67, 210);
            Find_Button.Margin = new Padding(4);
            Find_Button.Name = "Find_Button";
            Find_Button.Size = new Size(212, 63);
            Find_Button.TabIndex = 0;
            Find_Button.Text = "차량 찾기";
            Find_Button.Click += findButton_Click;
            // 
            // Phone_Number
            // 
            Phone_Number.AutoSize = true;
            Phone_Number.Location = new Point(26, 153);
            Phone_Number.Name = "Phone_Number";
            Phone_Number.Size = new Size(74, 20);
            Phone_Number.TabIndex = 10;
            Phone_Number.Text = "전화 번호";
            // 
            // Payment_Info
            // 
            Payment_Info.Controls.Add(Pay10);
            Payment_Info.Controls.Add(Pay30);
            Payment_Info.Controls.Add(Min10);
            Payment_Info.Controls.Add(label3);
            Payment_Info.Controls.Add(tableLayoutPanel1);
            Payment_Info.Location = new Point(394, 63);
            Payment_Info.Margin = new Padding(4);
            Payment_Info.Name = "Payment_Info";
            Payment_Info.Padding = new Padding(4);
            Payment_Info.Size = new Size(307, 145);
            Payment_Info.TabIndex = 11;
            Payment_Info.TabStop = false;
            Payment_Info.Text = "요금표";
            // 
            // Pay10
            // 
            Pay10.AutoSize = true;
            Pay10.Location = new Point(199, 96);
            Pay10.Margin = new Padding(4, 0, 4, 0);
            Pay10.Name = "Pay10";
            Pay10.Size = new Size(48, 20);
            Pay10.TabIndex = 14;
            Pay10.Text = "500원";
            // 
            // Pay30
            // 
            Pay30.AutoSize = true;
            Pay30.Location = new Point(50, 96);
            Pay30.Margin = new Padding(4, 0, 4, 0);
            Pay30.Name = "Pay30";
            Pay30.Size = new Size(59, 20);
            Pay30.TabIndex = 13;
            Pay30.Text = "1,500원";
            // 
            // Min10
            // 
            Min10.AutoSize = true;
            Min10.Location = new Point(183, 52);
            Min10.Margin = new Padding(4, 0, 4, 0);
            Min10.Name = "Min10";
            Min10.Size = new Size(80, 20);
            Min10.TabIndex = 12;
            Min10.Text = "추가(10분)";
            // 
            // label3
            // 
            label3.AutoSize = true;
            label3.Location = new Point(41, 52);
            label3.Margin = new Padding(4, 0, 4, 0);
            label3.Name = "label3";
            label3.Size = new Size(80, 20);
            label3.TabIndex = 11;
            label3.Text = "기본(30분)";
 
            // 
            // tableLayoutPanel1
            // 
            tableLayoutPanel1.CellBorderStyle = TableLayoutPanelCellBorderStyle.Single;
            tableLayoutPanel1.ColumnCount = 2;
            tableLayoutPanel1.ColumnStyles.Add(new ColumnStyle(SizeType.Percent, 50F));
            tableLayoutPanel1.ColumnStyles.Add(new ColumnStyle(SizeType.Percent, 50F));
            tableLayoutPanel1.ColumnStyles.Add(new ColumnStyle(SizeType.Absolute, 26F));
            tableLayoutPanel1.ColumnStyles.Add(new ColumnStyle(SizeType.Absolute, 26F));
            tableLayoutPanel1.ColumnStyles.Add(new ColumnStyle(SizeType.Absolute, 26F));
            tableLayoutPanel1.Location = new Point(12, 39);
            tableLayoutPanel1.Margin = new Padding(4);
            tableLayoutPanel1.Name = "tableLayoutPanel1";
            tableLayoutPanel1.RowCount = 2;
            tableLayoutPanel1.RowStyles.Add(new RowStyle(SizeType.Percent, 50F));
            tableLayoutPanel1.RowStyles.Add(new RowStyle(SizeType.Percent, 50F));
            tableLayoutPanel1.Size = new Size(284, 91);
            tableLayoutPanel1.TabIndex = 0;
            tableLayoutPanel1.Paint += tableLayoutPanel1_Paint;
            // 
            // tableLayoutPanel2
            // 
            tableLayoutPanel2.CellBorderStyle = TableLayoutPanelCellBorderStyle.Single;
            tableLayoutPanel2.ColumnCount = 2;
            tableLayoutPanel2.ColumnStyles.Add(new ColumnStyle(SizeType.Percent, 50F));
            tableLayoutPanel2.ColumnStyles.Add(new ColumnStyle(SizeType.Percent, 50F));
            tableLayoutPanel2.ColumnStyles.Add(new ColumnStyle(SizeType.Absolute, 20F));
            tableLayoutPanel2.ColumnStyles.Add(new ColumnStyle(SizeType.Absolute, 20F));
            tableLayoutPanel2.ColumnStyles.Add(new ColumnStyle(SizeType.Absolute, 20F));
            tableLayoutPanel2.Location = new Point(0, 0);
            tableLayoutPanel2.Name = "tableLayoutPanel2";
            tableLayoutPanel2.RowCount = 2;
            tableLayoutPanel2.Size = new Size(200, 100);
            tableLayoutPanel2.TabIndex = 0;
            // 
            // label4
            // 
            label4.AutoSize = true;
            label4.Location = new Point(4, 1);
            label4.Name = "label4";
            label4.Size = new Size(65, 15);
            label4.TabIndex = 11;
            label4.Text = "기본(30분)";
            // 
            // Infomation
            // 
            Infomation.Controls.Add(Info3);
            Infomation.Controls.Add(Info2);
            Infomation.Controls.Add(Info1);
            Infomation.Location = new Point(394, 225);
            Infomation.Margin = new Padding(4);
            Infomation.Name = "Infomation";
            Infomation.Padding = new Padding(4);
            Infomation.Size = new Size(307, 123);
            Infomation.TabIndex = 15;
            Infomation.TabStop = false;
            Infomation.Text = "결제 주의사항";
            Infomation.Enter += groupBox2_Enter;
            // 
            // Info3
            // 
            Info3.AutoSize = true;
            Info3.Font = new Font("맑은 고딕", 8F, FontStyle.Regular, GraphicsUnit.Point);
            Info3.Location = new Point(12, 90);
            Info3.Margin = new Padding(4, 0, 4, 0);
            Info3.Name = "Info3";
            Info3.Size = new Size(286, 19);
            Info3.TabIndex = 13;
            Info3.Text = "2. 자세한 안내는 안내사항을 참고 바랍니다.";
            // 
            // Info2
            // 
            Info2.AutoSize = true;
            Info2.Font = new Font("맑은 고딕", 8F, FontStyle.Regular, GraphicsUnit.Point);
            Info2.Location = new Point(25, 61);
            Info2.Margin = new Padding(4, 0, 4, 0);
            Info2.Name = "Info2";
            Info2.Size = new Size(223, 19);
            Info2.TabIndex = 12;
            Info2.Text = "주차 공간을 비워주시기 바랍니다.";
            // 
            // Info1
            // 
            Info1.AutoSize = true;
            Info1.Font = new Font("맑은 고딕", 8F, FontStyle.Regular, GraphicsUnit.Point);
            Info1.Location = new Point(12, 37);
            Info1.Margin = new Padding(4, 0, 4, 0);
            Info1.Name = "Info1";
            Info1.Size = new Size(260, 19);
            Info1.TabIndex = 11;
            Info1.Text = "1. 결제 후 다음 차량을 위하여 신속하게";
            // 
            // Back_Button
            // 
            Back_Button.Location = new Point(3, 3);
            Back_Button.Name = "Back_Button";
            Back_Button.Size = new Size(60, 35);
            Back_Button.TabIndex = 16;
            Back_Button.Text = "뒤로";
            Back_Button.UseVisualStyleBackColor = true;
            Back_Button.Click += Back_Button_Click;
            // 
            // panel1
            // 
            panel1.BackColor = SystemColors.ButtonShadow;
            panel1.Controls.Add(label9);
            panel1.Controls.Add(Back_Button);
            panel1.Location = new Point(0, 0);
            panel1.Name = "panel1";
            panel1.Size = new Size(716, 40);
            panel1.TabIndex = 17;
            // 
            // label9
            // 
            label9.AutoSize = true;
            label9.Font = new Font("Microsoft Sans Serif", 16.2F, FontStyle.Bold, GraphicsUnit.Point);
            label9.ForeColor = Color.White;
            label9.Location = new Point(305, 4);
            label9.Name = "label9";
            label9.Size = new Size(106, 32);
            label9.TabIndex = 19;
            label9.Text = "주차 조회";
            // 
            // FindForm
            // 
            AutoScaleDimensions = new SizeF(9F, 20F);
            AutoScaleMode = AutoScaleMode.Font;
            BackColor = SystemColors.Control;
            ClientSize = new Size(712, 363);
            Controls.Add(panel1);
            Controls.Add(Infomation);
            Controls.Add(Payment_Info);
            Controls.Add(pMain);
            Name = "FindForm";
            Text = "주차 조회";
            FormClosed += FindForm_FormClosed;
            Load += FindForm_Load;
            pMain.ResumeLayout(false);
            pMain.PerformLayout();
            Payment_Info.ResumeLayout(false);
            Payment_Info.PerformLayout();
            Infomation.ResumeLayout(false);
            Infomation.PerformLayout();
            panel1.ResumeLayout(false);
            panel1.PerformLayout();
            ResumeLayout(false);
        }

        #endregion
        private TextBox Car_Info;
        private Label Car_Number;
        private GroupBox pMain;
        private TextBox Phone_Info;
        private Label Phone_Number;
        private Button Find_Button;
        private GroupBox Payment_Info;
        private TableLayoutPanel tableLayoutPanel1;
        private Label Min10;
        private Label label3;
        private TableLayoutPanel tableLayoutPanel2;
        private Label label4;
        private Label Pay10;
        private Label Pay30;
        private GroupBox Infomation;
        private Label Info1;
        private Label Info3;
        private Label Info2;
        private Button Back_Button;
        private Label Car_Model;
        private ComboBox Model_Info;
        private Panel panel1;
        private Label label9;
    }
}