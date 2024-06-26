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
        // 다음 주소는 Mongo DB의 관리자 계정으로 연결하는 주소입니다. 유출 되지 않도록 해주시기 바랍니다.
        public static IMongoClient client = new MongoClient("mongodb+srv://Team:08pkg7e73KqULAiI@parking.oql9wxv.mongodb.net/?retryWrites=true&w=majority");
        public static IMongoDatabase db = client.GetDatabase("vehicle_db"); // DB 불러오기. vehicle_db와 동일한 명칭을 가진 DB를 가져옴 
        public static IMongoCollection<regVehicles> collection = db.GetCollection<regVehicles>("vehicles"); // colletion 불러오기. vehicles와 동일한 명칭을 가진 collection을 가져옴
        public static IMongoCollection<regSpace> collection_space = db.GetCollection<regSpace>("parkingSpace"); // colletion 불러오기. parkingSpace와 동일한 명칭을 가진 collection을 가져옴
        //LocationCheck.PanelView screen = new LocationCheck.PanelView();

        public MainForm mainform;
        private RegisterForm registerForm;

        public FindForm(MainForm frm)
        {
            mainform = frm;
            InitializeComponent();
        }

        // 올바른 한국 휴대폰 번호인지 검사하는 함수
        static bool IsValidKoreanCarNumber(string carNumber)
        {
            string pattern = @"^([0-9]{2,3})[가-힣]([0-9]{4})$";
            return Regex.IsMatch(carNumber, pattern);
        }
        // 올바른 한국 휴대폰 번호인지 검사하는 함수
        static bool IsValidKoreanPhoneNumber(string phoneNumber)
        {
            string pattern = @"^01([0|1|6|7|8|9])-([0-9]{3,4})-([0-9]{4})$";
            return Regex.IsMatch(phoneNumber, pattern);
        }

        private void findButton_Click(object sender, EventArgs e)
        {
            string CarNumber = Car_Info.Text; // 입력된 차량 번호 저장
            string ModelName = Model_Info.Text; // 입력된 차량 모델 저장
            string PhoneNumber = Phone_Info.Text; // 입력된 전화 번호 저장
            string UserPayment; // 이용 금액s
            bool UserInfoCheck = false; // 유저의 정보가 올바른지 체크

            if (Car_Info.Text == "" || Phone_Info.Text == "" || Model_Info.Text == "")
            {
                MessageBox.Show("입력되지 않은 정보가 있습니다!", "알림");

            }
            else if (IsValidKoreanCarNumber(Car_Info.Text) == false)
            {
                MessageBox.Show("올바르지 않은 차량번호 형식입니다.\r00가0000(또는 000가0000)형식으로 차량번호를 입력해 주세요", "알림");
            }
            else if (IsValidKoreanPhoneNumber(Phone_Info.Text) == false)
            {
                MessageBox.Show("올바르지 않은 전화번호 형식입니다.\r01X-XXXX-XXXX형식으로 전화번호를 입력해 주세요", "알림");
            }
            else
            {
                List<regVehicles> list = collection.AsQueryable().ToList(); // regVehicles를 순회하기 위한 리스트
                int idx = 0;
                PayForm payform;
                for (int i = list.Count - 1; i >= 0; i--)
                {
                    regVehicles vehicle = list[i];
                    if (CarNumber == vehicle.VehicleNum && ModelName == vehicle.ModelName && PhoneNumber == vehicle.UserPhoneNumber)
                    {
                        idx = i; // 회원 정보 인덱스 저장
                        UserInfoCheck = true;
                        DateTime StartTime = vehicle.ParkingTime; // 등록 시간
                        DateTime EndTime = DateTime.Now; // 현재 시간
                        TimeSpan elapsedTime = EndTime - StartTime; // 현재 시간 - 등록 시간
                        if((int)elapsedTime.TotalMinutes < 0)
                        {
                            UserPayment = "0";
                        }
                        else if ((int)elapsedTime.TotalMinutes < 30) // 기본 시간 이용
                        {
                            UserPayment = "1500";
                        }
                        else // 기본 시간보다 오래 이용
                        {
                            UserPayment = ((((int)elapsedTime.TotalMinutes - 30) / 10 + 1) * 500 + 1500).ToString(); // 요금 계산 (ㄴ기본 1500, 10분 추가 500)
                        }
                        payform = new PayForm((int)elapsedTime.TotalMinutes, vehicle.ParkingLocation, UserPayment); // 결제폼에 정보 전달
                        payform.ShowDialog();

                        if(payform.PayCheck == true)
                        {
                            string vehicleNumToRemove = CarNumber; // 제거할 차량 번호
                            FilterDefinition<regVehicles> filter = Builders<regVehicles>.Filter.Eq(x => x.VehicleNum, vehicleNumToRemove); // 차 번호가 같은 경우(고유 번호)

                            collection.DeleteMany(filter); // 결제 완료된 정보는 제거
                        }
                        Close();
                    }
                }
                if (UserInfoCheck == false)
                {
                    MessageBox.Show("회원 정보가 잘못 입력 되었습니다.", "알림", MessageBoxButtons.OK, MessageBoxIcon.Warning);
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
        public void readData() // DB에서 주차된 정보 읽고 정보 갱신
        {

        }
        private void textBox1_TextChanged(object sender, EventArgs e)
        {

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
    }
}