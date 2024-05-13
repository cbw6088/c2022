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
    public partial class GuidanceNote : Form
    {

        public MainForm mainform;

        public GuidanceNote(MainForm frm)
        {
            InitializeComponent();
            mainform = frm;
        }


        private void button1_Click(object sender, EventArgs e)
        {
            Close();
        }

        private void label9_Click(object sender, EventArgs e)
        {

        }

        private void label7_Click(object sender, EventArgs e)
        {

        }

        private void label11_Click(object sender, EventArgs e)
        {

        }

        private void tableLayoutPanel2_Paint(object sender, PaintEventArgs e)
        {

        }

        private void tableLayoutPanel1_Paint(object sender, PaintEventArgs e)
        {

        }

        private void GuidanceNote_FormClosed(object sender, FormClosedEventArgs e)
        {
            mainform.Visible = true;
        }

        private void label12_Click(object sender, EventArgs e)
        {

        }
    }
}
