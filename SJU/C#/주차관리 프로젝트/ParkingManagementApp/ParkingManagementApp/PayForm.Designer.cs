namespace ParkingManagementApp
{
    partial class PayForm : Form
    {
        private void InitializeComponent()
        {
            Pay_Button = new Button();
            Time = new Label();
            User_Panel = new GroupBox();
            Pay_Info = new TextBox();
            Location_Info = new TextBox();
            Time_Info = new TextBox();
            Payment = new Label();
            Car_Location = new Label();
            panel1 = new Panel();
            Back_Button = new Button();
            label9 = new Label();
            User_Panel.SuspendLayout();
            panel1.SuspendLayout();
            SuspendLayout();
            // 
            // Pay_Button
            // 
            Pay_Button.Location = new Point(12, 216);
            Pay_Button.Name = "Pay_Button";
            Pay_Button.Size = new Size(231, 33);
            Pay_Button.TabIndex = 0;
            Pay_Button.Text = "결제 하기";
            Pay_Button.UseVisualStyleBackColor = true;
            Pay_Button.Click += Pay_Button_Click;
            // 
            // Time
            // 
            Time.AutoSize = true;
            Time.Location = new Point(6, 39);
            Time.Name = "Time";
            Time.Size = new Size(59, 15);
            Time.TabIndex = 2;
            Time.Text = "이용 시간";
            // 
            // User_Panel
            // 
            User_Panel.Controls.Add(Pay_Info);
            User_Panel.Controls.Add(Location_Info);
            User_Panel.Controls.Add(Time_Info);
            User_Panel.Controls.Add(Payment);
            User_Panel.Controls.Add(Car_Location);
            User_Panel.Controls.Add(Time);
            User_Panel.Location = new Point(12, 58);
            User_Panel.Name = "User_Panel";
            User_Panel.Size = new Size(231, 152);
            User_Panel.TabIndex = 3;
            User_Panel.TabStop = false;
            User_Panel.Text = "이용 정보";
            // 
            // Pay_Info
            // 
            Pay_Info.Location = new Point(95, 106);
            Pay_Info.Name = "Pay_Info";
            Pay_Info.Size = new Size(122, 23);
            Pay_Info.TabIndex = 20;
            Pay_Info.TextChanged += Pay_Info_TextChanged;
            // 
            // Location_Info
            // 
            Location_Info.Location = new Point(95, 71);
            Location_Info.Name = "Location_Info";
            Location_Info.Size = new Size(122, 23);
            Location_Info.TabIndex = 19;
            Location_Info.TextChanged += Location_Info_TextChanged;
            // 
            // Time_Info
            // 
            Time_Info.Location = new Point(95, 32);
            Time_Info.Name = "Time_Info";
            Time_Info.Size = new Size(122, 23);
            Time_Info.TabIndex = 18;
            Time_Info.TextChanged += Number_Info_TextChanged;
            // 
            // Payment
            // 
            Payment.AutoSize = true;
            Payment.Location = new Point(6, 109);
            Payment.Name = "Payment";
            Payment.Size = new Size(59, 15);
            Payment.TabIndex = 4;
            Payment.Text = "결제 금액";
            // 
            // Car_Location
            // 
            Car_Location.AutoSize = true;
            Car_Location.Location = new Point(6, 74);
            Car_Location.Name = "Car_Location";
            Car_Location.Size = new Size(59, 15);
            Car_Location.TabIndex = 3;
            Car_Location.Text = "차량 위치";
            // 
            // panel1
            // 
            panel1.BackColor = SystemColors.ButtonShadow;
            panel1.Controls.Add(Back_Button);
            panel1.Controls.Add(label9);
            panel1.ForeColor = SystemColors.ControlLight;
            panel1.Location = new Point(0, 0);
            panel1.Name = "panel1";
            panel1.Size = new Size(255, 40);
            panel1.TabIndex = 19;
            // 
            // Back_Button
            // 
            Back_Button.ForeColor = SystemColors.ControlText;
            Back_Button.Location = new Point(3, 3);
            Back_Button.Name = "Back_Button";
            Back_Button.Size = new Size(60, 35);
            Back_Button.TabIndex = 20;
            Back_Button.Text = "뒤로";
            Back_Button.UseVisualStyleBackColor = true;
            Back_Button.Click += Back_Button_Click;
            // 
            // label9
            // 
            label9.AutoSize = true;
            label9.Font = new Font("Microsoft Sans Serif", 16.2F, FontStyle.Bold, GraphicsUnit.Point);
            label9.ForeColor = Color.White;
            label9.Location = new Point(95, 3);
            label9.Name = "label9";
            label9.Size = new Size(74, 26);
            label9.TabIndex = 20;
            label9.Text = "결    제";
            label9.TextAlign = ContentAlignment.MiddleCenter;
            // 
            // PayForm
            // 
            ClientSize = new Size(253, 261);
            Controls.Add(panel1);
            Controls.Add(User_Panel);
            Controls.Add(Pay_Button);
            Name = "PayForm";
            Text = "결제창";
            FormClosed += payform_Closed;
            User_Panel.ResumeLayout(false);
            User_Panel.PerformLayout();
            panel1.ResumeLayout(false);
            panel1.PerformLayout();
            ResumeLayout(false);
        }

        private Button Pay_Button;
        private Label Time;
        private GroupBox User_Panel;
        private Label Payment;
        private Label Car_Location;
        private TextBox Pay_Info;
        private TextBox Location_Info;
        private TextBox Time_Info;
        private Panel panel1;
        private Label label9;
        private Button Back_Button;
    }
}