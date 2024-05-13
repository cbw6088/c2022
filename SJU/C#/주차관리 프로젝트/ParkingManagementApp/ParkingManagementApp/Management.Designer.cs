namespace ParkingManagementApp
{
    partial class Management
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
        private void InitializeComponent()
        {
            buttonRegister = new Button();
            buttonUpdate = new Button();
            buttonDelete = new Button();
            txtNumber = new TextBox();
            label1 = new Label();
            dataGridView = new DataGridView();
            label2 = new Label();
            label3 = new Label();
            txtModel = new TextBox();
            txtId = new TextBox();
            label4 = new Label();
            txtLocation = new TextBox();
            label5 = new Label();
            txtPhoneNumber = new TextBox();
            label6 = new Label();
            txtTime = new TextBox();
            label9 = new Label();
            managerNumber = new TextBox();
            label10 = new Label();
            managerPassword = new TextBox();
            buttonManagerRegister = new Button();
            groupBox1 = new GroupBox();
            label7 = new Label();
            buttonBill = new Button();
            txtBill = new TextBox();
            groupBox2 = new GroupBox();
            ((System.ComponentModel.ISupportInitialize)dataGridView).BeginInit();
            groupBox1.SuspendLayout();
            groupBox2.SuspendLayout();
            SuspendLayout();
            // 
            // buttonRegister
            // 
            buttonRegister.Location = new Point(14, 386);
            buttonRegister.Margin = new Padding(4, 5, 4, 5);
            buttonRegister.Name = "buttonRegister";
            buttonRegister.Size = new Size(154, 36);
            buttonRegister.TabIndex = 0;
            buttonRegister.Text = "등록";
            buttonRegister.UseVisualStyleBackColor = true;
            buttonRegister.Click += buttonRegister_Click;
            // 
            // buttonUpdate
            // 
            buttonUpdate.Location = new Point(177, 386);
            buttonUpdate.Margin = new Padding(4, 5, 4, 5);
            buttonUpdate.Name = "buttonUpdate";
            buttonUpdate.Size = new Size(159, 36);
            buttonUpdate.TabIndex = 1;
            buttonUpdate.Text = "수정";
            buttonUpdate.UseVisualStyleBackColor = true;
            buttonUpdate.Click += buttonUpdate_Click;
            // 
            // buttonDelete
            // 
            buttonDelete.Location = new Point(177, 434);
            buttonDelete.Margin = new Padding(4, 5, 4, 5);
            buttonDelete.Name = "buttonDelete";
            buttonDelete.Size = new Size(159, 36);
            buttonDelete.TabIndex = 2;
            buttonDelete.Text = "삭제";
            buttonDelete.UseVisualStyleBackColor = true;
            buttonDelete.Click += buttonDelete_Click;
            // 
            // txtNumber
            // 
            txtNumber.Location = new Point(113, 84);
            txtNumber.Margin = new Padding(4, 5, 4, 5);
            txtNumber.Name = "txtNumber";
            txtNumber.Size = new Size(221, 31);
            txtNumber.TabIndex = 3;
            // 
            // label1
            // 
            label1.AutoSize = true;
            label1.Location = new Point(14, 46);
            label1.Margin = new Padding(4, 0, 4, 0);
            label1.Name = "label1";
            label1.Size = new Size(72, 25);
            label1.TabIndex = 4;
            label1.Text = "등록 ID";
            // 
            // dataGridView
            // 
            dataGridView.ColumnHeadersHeightSizeMode = DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            dataGridView.Location = new Point(374, 15);
            dataGridView.Margin = new Padding(4, 5, 4, 5);
            dataGridView.Name = "dataGridView";
            dataGridView.RowHeadersWidth = 62;
            dataGridView.RowTemplate.Height = 25;
            dataGridView.Size = new Size(977, 715);
            dataGridView.TabIndex = 5;
            dataGridView.CellClick += dataGridView_CellClick;
            // 
            // label2
            // 
            label2.AutoSize = true;
            label2.Location = new Point(7, 91);
            label2.Margin = new Padding(4, 0, 4, 0);
            label2.Name = "label2";
            label2.Size = new Size(90, 25);
            label2.TabIndex = 6;
            label2.Text = "차량 번호";
            // 
            // label3
            // 
            label3.AutoSize = true;
            label3.Location = new Point(19, 141);
            label3.Margin = new Padding(4, 0, 4, 0);
            label3.Name = "label3";
            label3.Size = new Size(66, 25);
            label3.TabIndex = 8;
            label3.Text = "모델명";
            // 
            // txtModel
            // 
            txtModel.Location = new Point(113, 134);
            txtModel.Margin = new Padding(4, 5, 4, 5);
            txtModel.Name = "txtModel";
            txtModel.Size = new Size(221, 31);
            txtModel.TabIndex = 7;
            // 
            // txtId
            // 
            txtId.BackColor = SystemColors.ControlDark;
            txtId.BorderStyle = BorderStyle.None;
            txtId.Font = new Font("맑은 고딕", 8F, FontStyle.Regular, GraphicsUnit.Point);
            txtId.Location = new Point(113, 46);
            txtId.Margin = new Padding(4, 5, 4, 5);
            txtId.Name = "txtId";
            txtId.ReadOnly = true;
            txtId.Size = new Size(223, 22);
            txtId.TabIndex = 9;
            // 
            // label4
            // 
            label4.AutoSize = true;
            label4.Location = new Point(11, 191);
            label4.Margin = new Padding(4, 0, 4, 0);
            label4.Name = "label4";
            label4.Size = new Size(90, 25);
            label4.TabIndex = 11;
            label4.Text = "차량 위치";
            // 
            // txtLocation
            // 
            txtLocation.Location = new Point(113, 184);
            txtLocation.Margin = new Padding(4, 5, 4, 5);
            txtLocation.Name = "txtLocation";
            txtLocation.Size = new Size(221, 31);
            txtLocation.TabIndex = 10;
            // 
            // label5
            // 
            label5.AutoSize = true;
            label5.Location = new Point(11, 241);
            label5.Margin = new Padding(4, 0, 4, 0);
            label5.Name = "label5";
            label5.Size = new Size(90, 25);
            label5.TabIndex = 13;
            label5.Text = "전화 번호";
            // 
            // txtPhoneNumber
            // 
            txtPhoneNumber.Location = new Point(113, 234);
            txtPhoneNumber.Margin = new Padding(4, 5, 4, 5);
            txtPhoneNumber.Name = "txtPhoneNumber";
            txtPhoneNumber.Size = new Size(221, 31);
            txtPhoneNumber.TabIndex = 12;
            // 
            // label6
            // 
            label6.AutoSize = true;
            label6.Location = new Point(11, 294);
            label6.Margin = new Padding(4, 0, 4, 0);
            label6.Name = "label6";
            label6.Size = new Size(90, 25);
            label6.TabIndex = 15;
            label6.Text = "주차 시간";
            // 
            // txtTime
            // 
            txtTime.Location = new Point(113, 284);
            txtTime.Margin = new Padding(4, 5, 4, 5);
            txtTime.Name = "txtTime";
            txtTime.Size = new Size(221, 31);
            txtTime.TabIndex = 14;
            txtTime.TextChanged += txtTime_TextChanged;
            // 
            // label9
            // 
            label9.AutoSize = true;
            label9.Location = new Point(2, 60);
            label9.Margin = new Padding(4, 0, 4, 0);
            label9.Name = "label9";
            label9.Size = new Size(108, 25);
            label9.TabIndex = 18;
            label9.Text = "관리자 번호";
            // 
            // managerNumber
            // 
            managerNumber.Location = new Point(110, 56);
            managerNumber.Margin = new Padding(4, 5, 4, 5);
            managerNumber.Name = "managerNumber";
            managerNumber.Size = new Size(221, 31);
            managerNumber.TabIndex = 19;
            // 
            // label10
            // 
            label10.AutoSize = true;
            label10.Location = new Point(2, 109);
            label10.Margin = new Padding(4, 0, 4, 0);
            label10.Name = "label10";
            label10.Size = new Size(108, 25);
            label10.TabIndex = 20;
            label10.Text = "관리자 암호";
            // 
            // managerPassword
            // 
            managerPassword.Location = new Point(111, 106);
            managerPassword.Margin = new Padding(4, 5, 4, 5);
            managerPassword.Name = "managerPassword";
            managerPassword.Size = new Size(221, 31);
            managerPassword.TabIndex = 21;
            // 
            // buttonManagerRegister
            // 
            buttonManagerRegister.Location = new Point(11, 168);
            buttonManagerRegister.Margin = new Padding(4, 5, 4, 5);
            buttonManagerRegister.Name = "buttonManagerRegister";
            buttonManagerRegister.Size = new Size(321, 39);
            buttonManagerRegister.TabIndex = 22;
            buttonManagerRegister.Text = "등록";
            buttonManagerRegister.UseVisualStyleBackColor = true;
            buttonManagerRegister.Click += buttonManagerRegister_Click;
            // 
            // groupBox1
            // 
            groupBox1.Controls.Add(label7);
            groupBox1.Controls.Add(buttonBill);
            groupBox1.Controls.Add(txtBill);
            groupBox1.Controls.Add(txtId);
            groupBox1.Controls.Add(buttonRegister);
            groupBox1.Controls.Add(buttonUpdate);
            groupBox1.Controls.Add(buttonDelete);
            groupBox1.Controls.Add(txtNumber);
            groupBox1.Controls.Add(label1);
            groupBox1.Controls.Add(label2);
            groupBox1.Controls.Add(txtModel);
            groupBox1.Controls.Add(label6);
            groupBox1.Controls.Add(label3);
            groupBox1.Controls.Add(txtTime);
            groupBox1.Controls.Add(txtLocation);
            groupBox1.Controls.Add(label5);
            groupBox1.Controls.Add(label4);
            groupBox1.Controls.Add(txtPhoneNumber);
            groupBox1.Location = new Point(13, 15);
            groupBox1.Margin = new Padding(3, 4, 3, 4);
            groupBox1.Name = "groupBox1";
            groupBox1.Padding = new Padding(3, 4, 3, 4);
            groupBox1.Size = new Size(343, 494);
            groupBox1.TabIndex = 23;
            groupBox1.TabStop = false;
            groupBox1.Text = "차량 관리";
            // 
            // label7
            // 
            label7.AutoSize = true;
            label7.Location = new Point(3, 336);
            label7.Margin = new Padding(4, 0, 4, 0);
            label7.Name = "label7";
            label7.Size = new Size(108, 25);
            label7.TabIndex = 31;
            label7.Text = "영수증 번호";
            // 
            // buttonBill
            // 
            buttonBill.Location = new Point(14, 434);
            buttonBill.Margin = new Padding(4, 5, 4, 5);
            buttonBill.Name = "buttonBill";
            buttonBill.Size = new Size(154, 36);
            buttonBill.TabIndex = 29;
            buttonBill.Text = "차감";
            buttonBill.UseVisualStyleBackColor = true;
            buttonBill.Click += buttonBill_Click;
            // 
            // txtBill
            // 
            txtBill.Location = new Point(113, 331);
            txtBill.Margin = new Padding(4, 5, 4, 5);
            txtBill.Name = "txtBill";
            txtBill.Size = new Size(221, 31);
            txtBill.TabIndex = 27;
            // 
            // groupBox2
            // 
            groupBox2.Controls.Add(label9);
            groupBox2.Controls.Add(managerNumber);
            groupBox2.Controls.Add(buttonManagerRegister);
            groupBox2.Controls.Add(label10);
            groupBox2.Controls.Add(managerPassword);
            groupBox2.Location = new Point(13, 515);
            groupBox2.Margin = new Padding(3, 4, 3, 4);
            groupBox2.Name = "groupBox2";
            groupBox2.Padding = new Padding(3, 4, 3, 4);
            groupBox2.Size = new Size(343, 215);
            groupBox2.TabIndex = 24;
            groupBox2.TabStop = false;
            groupBox2.Text = "관리자 등록";
            // 
            // Management
            // 
            AutoScaleDimensions = new SizeF(10F, 25F);
            AutoScaleMode = AutoScaleMode.Font;
            ClientSize = new Size(1366, 750);
            Controls.Add(groupBox2);
            Controls.Add(groupBox1);
            Controls.Add(dataGridView);
            Margin = new Padding(4, 5, 4, 5);
            Name = "Management";
            Text = "주차 차량 관리";
            FormClosed += Form1_FormClosed;
            ((System.ComponentModel.ISupportInitialize)dataGridView).EndInit();
            groupBox1.ResumeLayout(false);
            groupBox1.PerformLayout();
            groupBox2.ResumeLayout(false);
            groupBox2.PerformLayout();
            ResumeLayout(false);
        }

        #endregion

        private Button buttonRegister;
        private Button buttonUpdate;
        private Button buttonDelete;
        private TextBox txtNumber;
        private Label label1;
        private DataGridView dataGridView;
        private Label label2;
        private Label label3;
        private TextBox txtModel;
        private TextBox txtId;
        private Label label4;
        private TextBox txtLocation;
        private Label label5;
        private TextBox txtPhoneNumber;
        private Label label6;
        private TextBox txtTime;
        private Label label9;
        private TextBox managerNumber;
        private Label label10;
        private TextBox managerPassword;
        private Button buttonManagerRegister;
        private GroupBox groupBox1;
        private GroupBox groupBox2;
        private TextBox txtBill;
        private Button buttonBill;
        private Label label7;
    }
}