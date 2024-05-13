using MongoDB.Bson;
using MongoDB.Bson.Serialization.Attributes;
using MongoDB.Driver;
using System.Security.Cryptography.X509Certificates;
using System.Windows.Forms;
using static System.Windows.Forms.VisualStyles.VisualStyleElement;
using ParkingManagementApp;
using System.Drawing;
using System.Collections.Generic;
using System.Text.RegularExpressions;

namespace ParkingManagementApp
{
    public partial class FindForm : Form
    {
        // ���� �ּҴ� Mongo DB�� ������ �������� �����ϴ� �ּ��Դϴ�. ���� ���� �ʵ��� ���ֽñ� �ٶ��ϴ�.
        public static IMongoClient client = new MongoClient("mongodb+srv://Team:08pkg7e73KqULAiI@parking.oql9wxv.mongodb.net/?retryWrites=true&w=majority");
        public static IMongoDatabase db = client.GetDatabase("vehicle_db"); // DB �ҷ�����. vehicle_db�� ������ ��Ī�� ���� DB�� ������ 
        public static IMongoCollection<regVehicles> collection = db.GetCollection<regVehicles>("vehicles"); // colletion �ҷ�����. vehicles�� ������ ��Ī�� ���� collection�� ������
        public static IMongoCollection<regSpace> collection_space = db.GetCollection<regSpace>("parkingSpace"); // colletion �ҷ�����. parkingSpace�� ������ ��Ī�� ���� collection�� ������
        //LocationCheck.PanelView screen = new LocationCheck.PanelView();

        public MainForm mainform;
        private RegisterForm registerForm;

        public FindForm(MainForm frm)
        {
            mainform = frm;
            InitializeComponent();
        }

        // �ùٸ� �ѱ� �޴��� ��ȣ���� �˻��ϴ� �Լ�
        static bool IsValidKoreanCarNumber(string carNumber)
        {
            string pattern = @"^([0-9]{2,3})[��-�R]([0-9]{4})$";
            return Regex.IsMatch(carNumber, pattern);
        }
        // �ùٸ� �ѱ� �޴��� ��ȣ���� �˻��ϴ� �Լ�
        static bool IsValidKoreanPhoneNumber(string phoneNumber)
        {
            string pattern = @"^01([0|1|6|7|8|9])-([0-9]{3,4})-([0-9]{4})$";
            return Regex.IsMatch(phoneNumber, pattern);
        }

        private void findButton_Click(object sender, EventArgs e)
        {
            string CarNumber = Car_Info.Text; // �Էµ� ���� ��ȣ ����
            string ModelName = Model_Info.Text; // �Էµ� ���� �� ����
            string PhoneNumber = Phone_Info.Text; // �Էµ� ��ȭ ��ȣ ����
            string UserPayment; // �̿� �ݾ�s
            bool UserInfoCheck = false; // ������ ������ �ùٸ��� üũ

            if (Car_Info.Text == "" || Phone_Info.Text == "" || Model_Info.Text == "")
            {
                MessageBox.Show("�Էµ��� ���� ������ �ֽ��ϴ�!", "�˸�");

            }
            else if (IsValidKoreanCarNumber(Car_Info.Text) == false)
            {
                MessageBox.Show("�ùٸ��� ���� ������ȣ �����Դϴ�.\r00��0000(�Ǵ� 000��0000)�������� ������ȣ�� �Է��� �ּ���", "�˸�");
            }
            else if (IsValidKoreanPhoneNumber(Phone_Info.Text) == false)
            {
                MessageBox.Show("�ùٸ��� ���� ��ȭ��ȣ �����Դϴ�.\r01X-XXXX-XXXX�������� ��ȭ��ȣ�� �Է��� �ּ���", "�˸�");
            }
            else
            {
                List<regVehicles> list = collection.AsQueryable().ToList(); // regVehicles�� ��ȸ�ϱ� ���� ����Ʈ
                int idx = 0;
                PayForm payform;
                for (int i = list.Count - 1; i >= 0; i--)
                {
                    regVehicles vehicle = list[i];
                    if (CarNumber == vehicle.VehicleNum && ModelName == vehicle.ModelName && PhoneNumber == vehicle.UserPhoneNumber)
                    {
                        idx = i; // ȸ�� ���� �ε��� ����
                        UserInfoCheck = true;
                        DateTime StartTime = vehicle.ParkingTime; // ��� �ð�
                        DateTime EndTime = DateTime.Now; // ���� �ð�
                        TimeSpan elapsedTime = EndTime - StartTime; // ���� �ð� - ��� �ð�
                        if((int)elapsedTime.TotalMinutes < 0)
                        {
                            UserPayment = "0";
                        }
                        else if ((int)elapsedTime.TotalMinutes < 30) // �⺻ �ð� �̿�
                        {
                            UserPayment = "1500";
                        }
                        else // �⺻ �ð����� ���� �̿�
                        {
                            UserPayment = ((((int)elapsedTime.TotalMinutes - 30) / 10 + 1) * 500 + 1500).ToString(); // ��� ��� (���⺻ 1500, 10�� �߰� 500)
                        }
                        payform = new PayForm((int)elapsedTime.TotalMinutes, vehicle.ParkingLocation, UserPayment); // �������� ���� ����
                        payform.ShowDialog();

                        if(payform.PayCheck == true)
                        {
                            string vehicleNumToRemove = CarNumber; // ������ ���� ��ȣ
                            FilterDefinition<regVehicles> filter = Builders<regVehicles>.Filter.Eq(x => x.VehicleNum, vehicleNumToRemove); // �� ��ȣ�� ���� ���(���� ��ȣ)

                            collection.DeleteMany(filter); // ���� �Ϸ�� ������ ����
                        }
                        Close();
                    }
                }
                if (UserInfoCheck == false)
                {
                    MessageBox.Show("ȸ�� ������ �߸� �Է� �Ǿ����ϴ�.", "�˸�", MessageBoxButtons.OK, MessageBoxIcon.Warning);
                }
            }
        }

        private void btnExit_Click(object sender, EventArgs e)
        {
            Application.Exit();
        }

        private void FindForm_Load(object sender, EventArgs e)
        {

        }

        private void carNumber_TextChanged(object sender, EventArgs e)
        {

        }

        private void Phone_number_TextChanged(object sender, EventArgs e)
        {

        }
        private void pMain_Enter(object sender, EventArgs e)
        {

        }
        private void flowLayoutPanel1_Paint(object sender, PaintEventArgs e)
        {

        }
        private void groupBox2_Enter(object sender, EventArgs e)
        {

        }
        private void tableLayoutPanel1_Paint(object sender, PaintEventArgs e)
        {

        }

        private void Back_Button_Click(object sender, EventArgs e)
        {
            Close();
        }

        private void Car_Number_TextChanged(object sender, EventArgs e)
        {

        }

        private void FindForm_FormClosed(object sender, FormClosedEventArgs e)
        {
            mainform.Visible = true;
        }
        public void readData() // DB���� ������ ���� �а� ���� ����
        {

        }
        private void textBox1_TextChanged(object sender, EventArgs e)
        {

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
            [BsonElement("UserPhoneNumber")] //���� �� ��ȭ��ȣ
            public string UserPhoneNumber { get; set; }
            [BsonElement("ParkingTime")]
            public DateTime ParkingTime { get; set; }

            // �� �κ��� ���� �ٸ� Class�� ���� �ְ� ����. ��ü �߰��� ���� �ʵ��� ����!
            public regVehicles(string vehicleNum, string modelName, string parkingLocation, string userPhoneNumber, DateTime parkingTime)
            {
                VehicleNum = vehicleNum;
                ModelName = modelName;
                ParkingLocation = parkingLocation;
                UserPhoneNumber = userPhoneNumber;
                ParkingTime = parkingTime;
            }
        }
    }
}