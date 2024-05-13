namespace ParkingManagementApp
{
    partial class GuidanceNote
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
            panel1 = new Panel();
            label8 = new Label();
            label15 = new Label();
            label14 = new Label();
            button1 = new Button();
            groupBox2 = new GroupBox();
            tableLayoutPanel2 = new TableLayoutPanel();
            label10 = new Label();
            label11 = new Label();
            label12 = new Label();
            label13 = new Label();
            groupBox1 = new GroupBox();
            label6 = new Label();
            tableLayoutPanel1 = new TableLayoutPanel();
            label3 = new Label();
            label1 = new Label();
            label2 = new Label();
            label4 = new Label();
            panel2 = new Panel();
            label9 = new Label();
            tableLayoutPanel3 = new TableLayoutPanel();
            label5 = new Label();
            label7 = new Label();
            panel1.SuspendLayout();
            groupBox2.SuspendLayout();
            tableLayoutPanel2.SuspendLayout();
            groupBox1.SuspendLayout();
            tableLayoutPanel1.SuspendLayout();
            panel2.SuspendLayout();
            tableLayoutPanel3.SuspendLayout();
            SuspendLayout();
            // 
            // panel1
            // 
            panel1.BackgroundImageLayout = ImageLayout.None;
            panel1.Controls.Add(label8);
            panel1.Controls.Add(label15);
            panel1.Controls.Add(label14);
            panel1.Location = new Point(14, 423);
            panel1.Name = "panel1";
            panel1.Size = new Size(757, 135);
            panel1.TabIndex = 9;
            // 
            // label8
            // 
            label8.AutoSize = true;
            label8.Location = new Point(3, 93);
            label8.Name = "label8";
            label8.Size = new Size(424, 25);
            label8.TabIndex = 1;
            label8.Text = "▶ 영수증 지참 시 한 시간 무료 이용이 가능합니다.";
            // 
            // label15
            // 
            label15.AutoSize = true;
            label15.Location = new Point(3, 53);
            label15.Name = "label15";
            label15.Size = new Size(640, 25);
            label15.TabIndex = 0;
            label15.Text = "▶ 운전자 부주의로 인한 차량도난 및 훼손 등에 대하여 책임을 지지 않습니다.\r\n";
            // 
            // label14
            // 
            label14.AutoSize = true;
            label14.Location = new Point(3, 17);
            label14.Name = "label14";
            label14.Size = new Size(457, 25);
            label14.TabIndex = 0;
            label14.Text = "▶ 주차장 제한속도는 시속 10km이내로 서행 하십시오.\r\n";
            // 
            // button1
            // 
            button1.Location = new Point(3, 5);
            button1.Name = "button1";
            button1.Size = new Size(67, 43);
            button1.TabIndex = 8;
            button1.Text = "뒤로";
            button1.UseVisualStyleBackColor = true;
            button1.Click += button1_Click;
            // 
            // groupBox2
            // 
            groupBox2.Controls.Add(tableLayoutPanel2);
            groupBox2.Font = new Font("Microsoft Sans Serif", 12F, FontStyle.Bold, GraphicsUnit.Point);
            groupBox2.Location = new Point(14, 253);
            groupBox2.Name = "groupBox2";
            groupBox2.Size = new Size(757, 163);
            groupBox2.TabIndex = 6;
            groupBox2.TabStop = false;
            groupBox2.Text = "운영 시간";
            // 
            // tableLayoutPanel2
            // 
            tableLayoutPanel2.CellBorderStyle = TableLayoutPanelCellBorderStyle.Single;
            tableLayoutPanel2.ColumnCount = 2;
            tableLayoutPanel2.ColumnStyles.Add(new ColumnStyle(SizeType.Percent, 31.65217F));
            tableLayoutPanel2.ColumnStyles.Add(new ColumnStyle(SizeType.Percent, 68.34782F));
            tableLayoutPanel2.Controls.Add(label10, 0, 0);
            tableLayoutPanel2.Controls.Add(label11, 0, 1);
            tableLayoutPanel2.Controls.Add(label12, 1, 0);
            tableLayoutPanel2.Controls.Add(label13, 1, 1);
            tableLayoutPanel2.Location = new Point(59, 33);
            tableLayoutPanel2.Name = "tableLayoutPanel2";
            tableLayoutPanel2.RowCount = 2;
            tableLayoutPanel2.RowStyles.Add(new RowStyle(SizeType.Percent, 50F));
            tableLayoutPanel2.RowStyles.Add(new RowStyle(SizeType.Percent, 50F));
            tableLayoutPanel2.Size = new Size(640, 113);
            tableLayoutPanel2.TabIndex = 0;
            tableLayoutPanel2.Paint += tableLayoutPanel2_Paint;
            // 
            // label10
            // 
            label10.Anchor = AnchorStyles.None;
            label10.AutoSize = true;
            label10.Font = new Font("맑은 고딕", 10.2F, FontStyle.Regular, GraphicsUnit.Point);
            label10.Location = new Point(70, 13);
            label10.Name = "label10";
            label10.Size = new Size(62, 30);
            label10.TabIndex = 0;
            label10.Text = "평 일";
            // 
            // label11
            // 
            label11.Anchor = AnchorStyles.None;
            label11.AutoSize = true;
            label11.Font = new Font("맑은 고딕", 10.2F, FontStyle.Regular, GraphicsUnit.Point);
            label11.Location = new Point(14, 69);
            label11.Name = "label11";
            label11.Size = new Size(174, 30);
            label11.TabIndex = 0;
            label11.Text = "일요일 및 공휴일";
            label11.Click += label11_Click;
            // 
            // label12
            // 
            label12.Anchor = AnchorStyles.None;
            label12.AutoSize = true;
            label12.Font = new Font("맑은 고딕", 10.2F, FontStyle.Regular, GraphicsUnit.Point);
            label12.Location = new Point(347, 13);
            label12.Name = "label12";
            label12.Size = new Size(148, 30);
            label12.TabIndex = 0;
            label12.Text = "08:00 ~ 22:00";
            label12.Click += label12_Click;
            // 
            // label13
            // 
            label13.Anchor = AnchorStyles.None;
            label13.AutoSize = true;
            label13.Font = new Font("맑은 고딕", 10.2F, FontStyle.Regular, GraphicsUnit.Point);
            label13.Location = new Point(347, 69);
            label13.Name = "label13";
            label13.Size = new Size(148, 30);
            label13.TabIndex = 0;
            label13.Text = "10:00 ~ 22:00";
            // 
            // groupBox1
            // 
            groupBox1.Controls.Add(label6);
            groupBox1.Controls.Add(tableLayoutPanel1);
            groupBox1.Font = new Font("Microsoft Sans Serif", 12F, FontStyle.Bold, GraphicsUnit.Point);
            groupBox1.Location = new Point(13, 57);
            groupBox1.Name = "groupBox1";
            groupBox1.Size = new Size(757, 177);
            groupBox1.TabIndex = 5;
            groupBox1.TabStop = false;
            groupBox1.Text = "요금표";
            // 
            // label6
            // 
            label6.AutoSize = true;
            label6.Location = new Point(371, 65);
            label6.Name = "label6";
            label6.Size = new Size(0, 29);
            label6.TabIndex = 9;
            // 
            // tableLayoutPanel1
            // 
            tableLayoutPanel1.CellBorderStyle = TableLayoutPanelCellBorderStyle.Single;
            tableLayoutPanel1.ColumnCount = 2;
            tableLayoutPanel1.ColumnStyles.Add(new ColumnStyle(SizeType.Percent, 50.73171F));
            tableLayoutPanel1.ColumnStyles.Add(new ColumnStyle(SizeType.Percent, 49.26829F));
            tableLayoutPanel1.Controls.Add(label3, 1, 0);
            tableLayoutPanel1.Controls.Add(label1, 0, 0);
            tableLayoutPanel1.Controls.Add(label2, 1, 1);
            tableLayoutPanel1.Controls.Add(label4, 0, 1);
            tableLayoutPanel1.Location = new Point(59, 32);
            tableLayoutPanel1.Name = "tableLayoutPanel1";
            tableLayoutPanel1.RowCount = 2;
            tableLayoutPanel1.RowStyles.Add(new RowStyle(SizeType.Percent, 50F));
            tableLayoutPanel1.RowStyles.Add(new RowStyle(SizeType.Percent, 50F));
            tableLayoutPanel1.RowStyles.Add(new RowStyle(SizeType.Absolute, 33F));
            tableLayoutPanel1.Size = new Size(641, 113);
            tableLayoutPanel1.TabIndex = 5;
            // 
            // label3
            // 
            label3.Anchor = AnchorStyles.None;
            label3.AutoSize = true;
            label3.Font = new Font("맑은 고딕", 10.2F, FontStyle.Regular, GraphicsUnit.Point);
            label3.Location = new Point(426, 13);
            label3.Name = "label3";
            label3.Size = new Size(112, 30);
            label3.TabIndex = 10;
            label3.Text = "추가(10분)";
            // 
            // label1
            // 
            label1.Anchor = AnchorStyles.None;
            label1.AutoSize = true;
            label1.Font = new Font("맑은 고딕", 10.2F, FontStyle.Regular, GraphicsUnit.Point);
            label1.Location = new Point(106, 13);
            label1.Name = "label1";
            label1.Size = new Size(112, 30);
            label1.TabIndex = 1;
            label1.Text = "기본(30분)";
            // 
            // label2
            // 
            label2.Anchor = AnchorStyles.None;
            label2.AutoSize = true;
            label2.Font = new Font("맑은 고딕", 10.2F, FontStyle.Regular, GraphicsUnit.Point);
            label2.Location = new Point(447, 69);
            label2.Name = "label2";
            label2.Size = new Size(70, 30);
            label2.TabIndex = 2;
            label2.Text = "500원";
            // 
            // label4
            // 
            label4.Anchor = AnchorStyles.None;
            label4.AutoSize = true;
            label4.Font = new Font("맑은 고딕", 10.2F, FontStyle.Regular, GraphicsUnit.Point);
            label4.Location = new Point(119, 69);
            label4.Name = "label4";
            label4.Size = new Size(87, 30);
            label4.TabIndex = 4;
            label4.Text = "1,500원";
            // 
            // panel2
            // 
            panel2.BackColor = SystemColors.ButtonShadow;
            panel2.Controls.Add(label9);
            panel2.Controls.Add(button1);
            panel2.Location = new Point(0, 0);
            panel2.Name = "panel2";
            panel2.Size = new Size(811, 50);
            panel2.TabIndex = 10;
            // 
            // label9
            // 
            label9.AutoSize = true;
            label9.Font = new Font("Microsoft Sans Serif", 16.2F, FontStyle.Bold, GraphicsUnit.Point);
            label9.ForeColor = Color.White;
            label9.Location = new Point(343, 5);
            label9.Name = "label9";
            label9.Size = new Size(113, 38);
            label9.TabIndex = 11;
            label9.Text = "안내사항";
            // 
            // tableLayoutPanel3
            // 
            tableLayoutPanel3.CellBorderStyle = TableLayoutPanelCellBorderStyle.Single;
            tableLayoutPanel3.ColumnCount = 2;
            tableLayoutPanel3.ColumnStyles.Add(new ColumnStyle(SizeType.Percent, 50.73171F));
            tableLayoutPanel3.ColumnStyles.Add(new ColumnStyle(SizeType.Percent, 49.26829F));
            tableLayoutPanel3.Controls.Add(label5, 0, 0);
            tableLayoutPanel3.Location = new Point(0, 0);
            tableLayoutPanel3.Name = "tableLayoutPanel3";
            tableLayoutPanel3.RowCount = 1;
            tableLayoutPanel3.RowStyles.Add(new RowStyle(SizeType.Absolute, 20F));
            tableLayoutPanel3.Size = new Size(200, 100);
            tableLayoutPanel3.TabIndex = 0;
            // 
            // label5
            // 
            label5.Anchor = AnchorStyles.None;
            label5.AutoSize = true;
            label5.Font = new Font("맑은 고딕", 10.2F, FontStyle.Regular, GraphicsUnit.Point);
            label5.Location = new Point(8, 20);
            label5.Margin = new Padding(2, 0, 2, 0);
            label5.Name = "label5";
            label5.Size = new Size(85, 60);
            label5.TabIndex = 1;
            label5.Text = "기본(30분)";
            // 
            // label7
            // 
            label7.Anchor = AnchorStyles.None;
            label7.AutoSize = true;
            label7.Font = new Font("맑은 고딕", 10.2F, FontStyle.Regular, GraphicsUnit.Point);
            label7.Location = new Point(126, 40);
            label7.Margin = new Padding(2, 0, 2, 0);
            label7.Name = "label7";
            label7.Size = new Size(47, 19);
            label7.TabIndex = 4;
            label7.Text = "500원";
            // 
            // GuidanceNote
            // 
            AutoScaleDimensions = new SizeF(10F, 25F);
            AutoScaleMode = AutoScaleMode.Font;
            BackColor = Color.White;
            ClientSize = new Size(784, 563);
            Controls.Add(panel2);
            Controls.Add(panel1);
            Controls.Add(groupBox2);
            Controls.Add(groupBox1);
            Name = "GuidanceNote";
            Text = "GuidanceNote";
            FormClosed += GuidanceNote_FormClosed;
            panel1.ResumeLayout(false);
            panel1.PerformLayout();
            groupBox2.ResumeLayout(false);
            tableLayoutPanel2.ResumeLayout(false);
            tableLayoutPanel2.PerformLayout();
            groupBox1.ResumeLayout(false);
            groupBox1.PerformLayout();
            tableLayoutPanel1.ResumeLayout(false);
            tableLayoutPanel1.PerformLayout();
            panel2.ResumeLayout(false);
            panel2.PerformLayout();
            tableLayoutPanel3.ResumeLayout(false);
            tableLayoutPanel3.PerformLayout();
            ResumeLayout(false);
        }

        #endregion

        private Panel panel1;
        private Label label15;
        private Label label14;
        private Button button1;
        private GroupBox groupBox2;
        private TableLayoutPanel tableLayoutPanel2;
        private Label label10;
        private Label label11;
        private Label label12;
        private Label label13;
        private GroupBox groupBox1;
        private Panel panel2;
        private Label label9;
        private Label label8;
        private Label label6;
        private TableLayoutPanel tableLayoutPanel1;
        private Label label1;
        private Label label4;
        private Label label2;
        private TableLayoutPanel tableLayoutPanel3;
        private Label label5;
        private Label label7;
        private Label label3;
    }
}