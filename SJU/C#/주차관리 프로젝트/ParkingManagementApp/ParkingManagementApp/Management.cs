using MongoDB.Bson;
using MongoDB.Bson.Serialization.Attributes;
using MongoDB.Driver;
using System.Dynamic;
using System.Security.Cryptography;

namespace ParkingManagementApp
{
    public partial class Management : Form
    {
        /** 
         * MongoDB URL: https://cloud.mongodb.com/
         * MongoDB ������ ����. ID: h991023@naver.com / PW: cxlavmfhwprxm (���� �������� c�� ������Ʈ)
         * MongoDB�� NoSQL�̱� ������ �������� ������ ���� �ʿ䰡 �����ϴ�! (�߰� ����: https://mjmjmj98.tistory.com/43)
         */

        // ���� �ּҴ� Mongo DB�� ������ �������� �����ϴ� �ּ��Դϴ�. ���� ���� �ʵ��� ���ֽñ� �ٶ��ϴ�.
        public static IMongoClient client = new MongoClient("mongodb+srv://Team:08pkg7e73KqULAiI@parking.oql9wxv.mongodb.net/?retryWrites=true&w=majority");
        public static IMongoDatabase db = client.GetDatabase("vehicle_db"); // DB �ҷ�����. vehicle_db�� ������ ��Ī�� ���� DB�� ������ 
        public static IMongoCollection<regVehicles> collection_vihicles = db.GetCollection<regVehicles>("vehicles"); // colletion �ҷ�����. vehicles�� ������ ��Ī�� ���� collection�� ������
        public static IMongoCollection<regManager> collection_manager = db.GetCollection<regManager>("managerData"); // managerData �ҷ�����. vehicles�� ������ ��Ī�� ���� collection�� ������
        public MainForm mainform;
        public ManagementPass managementPass;

        public Management(MainForm frm, ManagementPass frm2)
        {
            InitializeComponent();
            readData(); // ó�� ����� dataGridView�� DB�� �������� �ʱ�ȭ
            mainform = frm;
            managementPass = frm2;
        }

        private void buttonRegister_Click(object sender, EventArgs e) // �ڵ��� ���� ���
        {
            // new regVehicles() �ȿ��� DB�� ����� ������ ���� ����(Ȥ�� Textbox�� Text ��)�� ����
            regVehicles vehicle = new regVehicles(txtNumber.Text, txtModel.Text, txtLocation.Text, txtPhoneNumber.Text, Convert.ToDateTime(txtTime.Text));
            collection_vihicles.InsertOne(vehicle); // DB�� ����
            readData(); // dataGridView ����
        }

        private void buttonUpdate_Click(object sender, EventArgs e) // �ڵ��� ���� ����
        {
            regVehicles vehicle = new regVehicles(txtNumber.Text, txtModel.Text, txtLocation.Text, txtPhoneNumber.Text, Convert.ToDateTime(txtTime.Text));
            var update = Builders<regVehicles>.Update // DB�� ����
                                                      // DB ��ü�� �̸��� ������ ���� ����
                .Set("VehicleNum", txtNumber.Text)
                .Set("ModelName", txtModel.Text)
                .Set("ParkingLocation", txtLocation.Text)
                .Set("UserPhoneNumber", txtPhoneNumber.Text)
                .Set("ParkingTime", txtTime.Text);

            collection_vihicles.UpdateOne(vehicle => vehicle.Id == ObjectId.Parse(txtId.Text), update); // Id���� ���� �׸��� ã�� ������Ʈ
            readData();
        }

        private void buttonDelete_Click(object sender, EventArgs e) // �ڵ��� ���� ����
        {
            collection_vihicles.DeleteOne(vehicle => vehicle.Id == ObjectId.Parse(txtId.Text)); // Id���� ���� �׸��� ã�� ����
            readData();
        }

        private void dataGridView_CellClick(object sender, DataGridViewCellEventArgs e) // ǥ���� Ŭ���� �׸��� Textbox�� �ҷ���
        {
            txtId.Text = dataGridView.Rows[e.RowIndex].Cells[0].Value.ToString();
            txtNumber.Text = dataGridView.Rows[e.RowIndex].Cells[1].Value.ToString();
            txtModel.Text = dataGridView.Rows[e.RowIndex].Cells[2].Value.ToString();
            txtLocation.Text = dataGridView.Rows[e.RowIndex].Cells[3].Value.ToString();
            txtPhoneNumber.Text = dataGridView.Rows[e.RowIndex].Cells[4].Value.ToString();
            txtTime.Text = dataGridView.Rows[e.RowIndex].Cells[5].Value.ToString();
        }

        public void readData() // dataGridView ����
        {
            // BD���� ��� ���� ����Ʈ�� ���·� �о��
            List<regVehicles> list = collection_vihicles.AsQueryable().ToList();
            if (list != null && list.Count > 0) // BD�� �׸��� ���� �ϴ��� Ȯ��. ���� ��� ���� ó��
            {
                dataGridView.DataSource = list; // dataGridView�� list ǥ��

                // Textbox�� Text�� ù��° ���� ������ ���� (��ġ�� �������� �ǵ��� - �ʿ���ٸ� ����!)
                txtId.Text = dataGridView.Rows[0].Cells[0].Value.ToString();
                txtNumber.Text = dataGridView.Rows[0].Cells[1].Value.ToString();
                txtModel.Text = dataGridView.Rows[0].Cells[2].Value.ToString();
                txtLocation.Text = dataGridView.Rows[0].Cells[3].Value.ToString();
                txtPhoneNumber.Text = dataGridView.Rows[0].Cells[4].Value.ToString();
                txtTime.Text = dataGridView.Rows[0].Cells[5].Value.ToString();

            }
            else
            { // DB�� ������� ���
                dataGridView.DataSource = 0;
                txtId.Text = "";
                txtNumber.Text = "";
                txtModel.Text = "";
                txtLocation.Text = "";
                txtPhoneNumber.Text = "";
                txtTime.Text = "";
            }
        }

        public void reloadParkingSpace()
        {

        }

        private void Form1_FormClosed(object sender, FormClosedEventArgs e)
        {
            mainform.Visible = true;
            managementPass.Close();
            this.Close();
        }

        private void buttonManagerRegister_Click(object sender, EventArgs e)
        {
            if (managerNumber.Text == "" || managerPassword.Text == "")
            {
                MessageBox.Show("�Էµ��� ���� ������ �ֽ��ϴ�!", "�˸�");
            }
            else
            {
                // ������ ��ȣ�� ���� �����͸� ã�Ƴ���
                var filter = Builders<regManager>.Filter.Eq("ManagerNum", managerNumber.Text);
                var managerData = collection_manager.Find(filter).Limit(1).SingleOrDefault();

                if (managerData == null)
                {
                    // ��й�ȣ HASH ��ȣȭ
                    var managerPW = managerPassword.Text;

                    // cryptographic PRNG�� �̿��� salt ����
                    byte[] salt;
                    new RNGCryptoServiceProvider().GetBytes(salt = new byte[16]);

                    // ��й�ȣ�� Rfc2898DeriveBytes�� �����ϰ� �̸� �̿��� Hash���� ����
                    var pbkdf2 = new Rfc2898DeriveBytes(managerPW, salt, 100000);
                    byte[] hash = pbkdf2.GetBytes(20);

                    // Salt�� Hash�� ��ģ �Ŀ� �̾� ������: ��ȣȭ�� ��й�ȣ
                    byte[] hashBytes = new byte[36];
                    Array.Copy(salt, 0, hashBytes, 0, 16);
                    Array.Copy(hash, 0, hashBytes, 16, 20);
                    string passwordHash = Convert.ToBase64String(hashBytes);

                    // ������ ���� ���
                    regManager manager = new regManager(managerNumber.Text, passwordHash);
                    collection_manager.InsertOne(manager); // DB�� ����

                    MessageBox.Show("����� �Ϸ�Ǿ����ϴ�.", "�˸�");
                }
                else
                {
                    MessageBox.Show("�̹� ������� �̸��Դϴ�.", "�˸�");
                }
            }
        }

        private void txtTime_TextChanged(object sender, EventArgs e)
        {

        }

        private void buttonBill_Click(object sender, EventArgs e)
        {
            if (txtBill.Text == "")
            {
                MessageBox.Show("������ ��ȣ�� �ùٸ��� �Է��Ͽ� �ֽ��̿�.", "�˸�");
            }
            else
            {
                string CarNumber = txtNumber.Text;
                List<regVehicles> list = collection_vihicles.AsQueryable().ToList(); // regVehicles�� ��ȸ�ϱ� ���� ����Ʈ
                foreach (regVehicles vehicle in list)
                {
                    if (CarNumber == vehicle.VehicleNum)
                    {
                        vehicle.ParkingTime = vehicle.ParkingTime.AddMinutes(60);

                        var filter = Builders<regVehicles>.Filter.Eq("_id", vehicle.Id);
                        var update = Builders<regVehicles>.Update.Set("ParkingTime", vehicle.ParkingTime);

                        collection_vihicles.ReplaceOne(filter, vehicle);
                    }
                }
                MessageBox.Show("60���� �����Ǿ����ϴ�.", "�˸�");
            }
        }
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

    public class regManager // DB�� Model����
    {
        // [Bson] ������ �κ��� �Ʒ��� ������ ���εǾ� MongoDB���� ���Ǳ� ������ �� �־��־����
        [BsonId] // ���� ID
        public ObjectId Id { get; set; }
        [BsonElement("ManagerNum")] // ������ ��ȣ
        public string ManagerNum { get; set; }
        [BsonElement("ManagerPassword")] // ������ ��ȣ HASH��ȣȭ �Ͽ� ��ȣȭ �Ұ��� �ϵ��� �߽��ϴ�!
        public string ManagerPassword { get; set; }

        // �� �κ��� ���� �ٸ� Class�� ���� �ְ� ����. ��ü �߰��� ���� �ʵ��� ����!
        public regManager(string managerNum, string managerPassword)
        {
            ManagerNum = managerNum;
            ManagerPassword = managerPassword;
        }
    }
}