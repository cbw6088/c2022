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
         * MongoDB 관리자 계정. ID: h991023@naver.com / PW: cxlavmfhwprxm (영어 자판으로 c팀 프로젝트)
         * MongoDB는 NoSQL이기 때문에 데이터의 구조가 같을 필요가 없습니다! (추가 정보: https://mjmjmj98.tistory.com/43)
         */

        // 다음 주소는 Mongo DB의 관리자 계정으로 연결하는 주소입니다. 유출 되지 않도록 해주시기 바랍니다.
        public static IMongoClient client = new MongoClient("mongodb+srv://Team:08pkg7e73KqULAiI@parking.oql9wxv.mongodb.net/?retryWrites=true&w=majority");
        public static IMongoDatabase db = client.GetDatabase("vehicle_db"); // DB 불러오기. vehicle_db와 동일한 명칭을 가진 DB를 가져옴 
        public static IMongoCollection<regVehicles> collection_vihicles = db.GetCollection<regVehicles>("vehicles"); // colletion 불러오기. vehicles와 동일한 명칭을 가진 collection을 가져옴
        public static IMongoCollection<regManager> collection_manager = db.GetCollection<regManager>("managerData"); // managerData 불러오기. vehicles와 동일한 명칭을 가진 collection을 가져옴
        public MainForm mainform;
        public ManagementPass managementPass;

        public Management(MainForm frm, ManagementPass frm2)
        {
            InitializeComponent();
            readData(); // 처음 실행시 dataGridView를 DB의 내용으로 초기화
            mainform = frm;
            managementPass = frm2;
        }

        private void buttonRegister_Click(object sender, EventArgs e) // 자동차 정보 등록
        {
            // new regVehicles() 안에는 DB에 등록할 정보를 가진 변수(혹은 Textbox의 Text 등)를 삽입
            regVehicles vehicle = new regVehicles(txtNumber.Text, txtModel.Text, txtLocation.Text, txtPhoneNumber.Text, Convert.ToDateTime(txtTime.Text));
            collection_vihicles.InsertOne(vehicle); // DB에 삽입
            readData(); // dataGridView 갱신
        }

        private void buttonUpdate_Click(object sender, EventArgs e) // 자동차 정보 갱신
        {
            regVehicles vehicle = new regVehicles(txtNumber.Text, txtModel.Text, txtLocation.Text, txtPhoneNumber.Text, Convert.ToDateTime(txtTime.Text));
            var update = Builders<regVehicles>.Update // DB를 갱신
                                                      // DB 개체의 이름과 변경할 값을 매핑
                .Set("VehicleNum", txtNumber.Text)
                .Set("ModelName", txtModel.Text)
                .Set("ParkingLocation", txtLocation.Text)
                .Set("UserPhoneNumber", txtPhoneNumber.Text)
                .Set("ParkingTime", txtTime.Text);

            collection_vihicles.UpdateOne(vehicle => vehicle.Id == ObjectId.Parse(txtId.Text), update); // Id값이 같은 항목을 찾아 업데이트
            readData();
        }

        private void buttonDelete_Click(object sender, EventArgs e) // 자동차 정보 삭제
        {
            collection_vihicles.DeleteOne(vehicle => vehicle.Id == ObjectId.Parse(txtId.Text)); // Id값이 같은 항목을 찾아 삭제
            readData();
        }

        private void dataGridView_CellClick(object sender, DataGridViewCellEventArgs e) // 표에서 클릭한 항목을 Textbox로 불러옴
        {
            txtId.Text = dataGridView.Rows[e.RowIndex].Cells[0].Value.ToString();
            txtNumber.Text = dataGridView.Rows[e.RowIndex].Cells[1].Value.ToString();
            txtModel.Text = dataGridView.Rows[e.RowIndex].Cells[2].Value.ToString();
            txtLocation.Text = dataGridView.Rows[e.RowIndex].Cells[3].Value.ToString();
            txtPhoneNumber.Text = dataGridView.Rows[e.RowIndex].Cells[4].Value.ToString();
            txtTime.Text = dataGridView.Rows[e.RowIndex].Cells[5].Value.ToString();
        }

        public void readData() // dataGridView 갱신
        {
            // BD에서 모든 값을 리스트의 형태로 읽어옴
            List<regVehicles> list = collection_vihicles.AsQueryable().ToList();
            if (list != null && list.Count > 0) // BD에 항목이 존제 하는지 확인. 없을 경우 예외 처리
            {
                dataGridView.DataSource = list; // dataGridView에 list 표시

                // Textbox의 Text를 첫번째 행의 내용들로 갱신 (위치를 원점으로 되돌림 - 필요없다면 삭제!)
                txtId.Text = dataGridView.Rows[0].Cells[0].Value.ToString();
                txtNumber.Text = dataGridView.Rows[0].Cells[1].Value.ToString();
                txtModel.Text = dataGridView.Rows[0].Cells[2].Value.ToString();
                txtLocation.Text = dataGridView.Rows[0].Cells[3].Value.ToString();
                txtPhoneNumber.Text = dataGridView.Rows[0].Cells[4].Value.ToString();
                txtTime.Text = dataGridView.Rows[0].Cells[5].Value.ToString();

            }
            else
            { // DB가 비어있을 경우
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
                MessageBox.Show("입력되지 않은 정보가 있습니다!", "알림");
            }
            else
            {
                // 관리자 번호가 같은 데이터를 찾아낸다
                var filter = Builders<regManager>.Filter.Eq("ManagerNum", managerNumber.Text);
                var managerData = collection_manager.Find(filter).Limit(1).SingleOrDefault();

                if (managerData == null)
                {
                    // 비밀번호 HASH 암호화
                    var managerPW = managerPassword.Text;

                    // cryptographic PRNG를 이용해 salt 생성
                    byte[] salt;
                    new RNGCryptoServiceProvider().GetBytes(salt = new byte[16]);

                    // 비밀번호로 Rfc2898DeriveBytes를 생성하고 이를 이용해 Hash값을 생성
                    var pbkdf2 = new Rfc2898DeriveBytes(managerPW, salt, 100000);
                    byte[] hash = pbkdf2.GetBytes(20);

                    // Salt와 Hash를 합친 후에 이어 붙힌다: 암호화된 비밀번호
                    byte[] hashBytes = new byte[36];
                    Array.Copy(salt, 0, hashBytes, 0, 16);
                    Array.Copy(hash, 0, hashBytes, 16, 20);
                    string passwordHash = Convert.ToBase64String(hashBytes);

                    // 관리자 정보 등록
                    regManager manager = new regManager(managerNumber.Text, passwordHash);
                    collection_manager.InsertOne(manager); // DB에 삽입

                    MessageBox.Show("등록이 완료되었습니다.", "알림");
                }
                else
                {
                    MessageBox.Show("이미 사용중인 이름입니다.", "알림");
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
                MessageBox.Show("영수증 번호를 올바르게 입력하여 주십이오.", "알림");
            }
            else
            {
                string CarNumber = txtNumber.Text;
                List<regVehicles> list = collection_vihicles.AsQueryable().ToList(); // regVehicles를 순회하기 위한 리스트
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
                MessageBox.Show("60분이 차감되었습니다.", "알림");
            }
        }
    }
    public class regVehicles // DB의 Model설정
    {
        // [Bson] 형태의 부분은 아래의 변수와 매핑되어 MongoDB에서 사용되기 때문에 꼭 넣어주어야함
        [BsonId] // 고유 ID
        public ObjectId Id { get; set; }
        [BsonElement("VehicleNum")] // 차량 번호
        public string VehicleNum { get; set; }
        [BsonElement("ModelName")] // 차종
        public string ModelName { get; set; }
        [BsonElement("ParkingLocation")] //주차 위치
        public string ParkingLocation { get; set; }
        [BsonElement("UserPhoneNumber")] //주차 고객 전화번호
        public string UserPhoneNumber { get; set; }
        [BsonElement("ParkingTime")]
        public DateTime ParkingTime { get; set; }

        // 이 부분을 통해 다른 Class와 값을 주고 받음. 개체 추가시 잊지 않도록 주의!
        public regVehicles(string vehicleNum, string modelName, string parkingLocation, string userPhoneNumber, DateTime parkingTime)
        {
            VehicleNum = vehicleNum;
            ModelName = modelName;
            ParkingLocation = parkingLocation;
            UserPhoneNumber = userPhoneNumber;
            ParkingTime = parkingTime;
        }
    }

    public class regManager // DB의 Model설정
    {
        // [Bson] 형태의 부분은 아래의 변수와 매핑되어 MongoDB에서 사용되기 때문에 꼭 넣어주어야함
        [BsonId] // 고유 ID
        public ObjectId Id { get; set; }
        [BsonElement("ManagerNum")] // 관리자 번호
        public string ManagerNum { get; set; }
        [BsonElement("ManagerPassword")] // 관리자 암호 HASH암호화 하여 복호화 불가능 하도록 했습니다!
        public string ManagerPassword { get; set; }

        // 이 부분을 통해 다른 Class와 값을 주고 받음. 개체 추가시 잊지 않도록 주의!
        public regManager(string managerNum, string managerPassword)
        {
            ManagerNum = managerNum;
            ManagerPassword = managerPassword;
        }
    }
}