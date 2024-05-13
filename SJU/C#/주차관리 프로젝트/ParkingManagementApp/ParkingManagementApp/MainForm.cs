using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace ParkingManagementApp
{
    public partial class MainForm : Form
    {
        public MainForm()
        {
            InitializeComponent();
        }

        private void Form2_Load(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {
            // 차량 등록 폼을 화면에 표시합니다.            
            this.Visible = false;
            RegisterForm window1 = new RegisterForm(this);
            window1.ShowDialog();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            // 차량 찾기 폼을 화면에 표시합니다.
            this.Visible = false;
            FindForm window4 = new FindForm(this);
            window4.ShowDialog();
        }

        private void button3_Click(object sender, EventArgs e)
        {
            // 관리 폼(Form1)을 화면에 표시합니다.
            this.Visible = false;
            ManagementPass window2 = new ManagementPass(this);
            window2.Show();
        }

        private void button4_Click(object sender, EventArgs e)
        {
            // 안내 사항 폼을 화면에 표시합니다.
            this.Visible = false;
            GuidanceNote window3 = new GuidanceNote(this);
            window3.ShowDialog();
        }

        private void MainForm_FormClosed(object sender, FormClosedEventArgs e)
        {
        }
    }
}
