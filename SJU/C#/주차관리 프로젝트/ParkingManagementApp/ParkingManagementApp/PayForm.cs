using MongoDB.Bson;
using MongoDB.Bson.Serialization.Attributes;
using MongoDB.Driver;
using System.Security.Cryptography.X509Certificates;
using System.Windows.Forms;
using static System.Windows.Forms.VisualStyles.VisualStyleElement;

namespace ParkingManagementApp
{
    public partial class PayForm : Form
    {
        private int TimeInput;
        private string LocationInput;
        private string PayInput;
        public bool PayCheck;
        public FindForm findform;
        public MainForm mainForm;

        public PayForm(int TimeInput, string LocationInput, string PayInput)
        {
            InitializeComponent();
            this.TimeInput = TimeInput;
            this.LocationInput = LocationInput;
            this.PayInput = PayInput;
            Time_Info.Text = TimeInput.ToString() + "��";
            Location_Info.Text = LocationInput;
            Pay_Info.Text = PayInput;
            PayCheck = false;
        }

        public int Get_Time()
        {
            return this.TimeInput; // ���� ���� ��ȯ�ϴ� �޼��带 �����մϴ�.
        }

        public string Get_Location()
        {
            return this.LocationInput;
        }

        public string Get_Pay()
        {
            return this.PayInput;
        }

        private void Number_Info_TextChanged(object sender, EventArgs e)
        {
            //Time_Info.Text = this.TimeInput;
        }

        private void Location_Info_TextChanged(object sender, EventArgs e)
        {
            //Location_Info.Text = this.LocationInput;
        }

        private void Pay_Info_TextChanged(object sender, EventArgs e)
        {
            //Pay_Info.Text = this.PayInput;
        }

        private void Pay_Button_Click(object sender, EventArgs e)
        {
            PayCheck = true;
            MessageBox.Show("������ �Ϸ� �Ǿ����ϴ�..", "�˸�", MessageBoxButtons.OK, MessageBoxIcon.Warning);
            Close();
        }

        public class regVehicles // DB�� Model����
        {
            // [Bson] ������ �κ��� �Ʒ��� ������ ���εǾ� MongoDB���� ���Ǳ� ������ �� �־��־����
            [BsonId] // ���� ID
            public ObjectId Id { get; set; }
            [BsonElement("VehicleNum")] // ���� ��ȣ
            public string VehicleNum { get; set; }
            [BsonElement("ModelName")] // ����
            public string ModelName { get; set; }
            [BsonElement("ParkingLocation")] //���� ��ġ
            public string ParkingLocation { get; set; }

            // �߰��� �Ӽ� (������ ���� ��ȭ��ȣ : ��Ⱓ ������ ã�� �ʴ� ��� ���)
            [BsonElement("UserPhoneNumber")] //���� �� ��ȭ��ȣ
            public string UserPhoneNumber { get; set; }

            // �� �κ��� ���� �ٸ� Class�� ���� �ְ� ����. ��ü �߰��� ���� �ʵ��� ����!
            public regVehicles(string vehicleNum, string modelName, string parkingLocation, string userPhoneNumber)
            {
                VehicleNum = vehicleNum;
                ModelName = modelName;
                ParkingLocation = parkingLocation;
                UserPhoneNumber = userPhoneNumber;
            }
        }

        private void Back_Button_Click(object sender, EventArgs e)
        {
            PayCheck = false;
            Close();
        }

        private void payform_Closed(object sender, FormClosedEventArgs e)
        {
            if (PayCheck == false)
            {
                MessageBox.Show("������ ��� �Ǿ����ϴ�.", "�˸�", MessageBoxButtons.OK, MessageBoxIcon.Warning);
            }
        }
    }
}

