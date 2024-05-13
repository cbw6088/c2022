using MongoDB.Bson;
using MongoDB.Bson.Serialization.Attributes;
using MongoDB.Driver;
using System.Text.RegularExpressions;
using System.Windows.Forms;

namespace ParkingManagementApp
{
    public partial class RegisterForm : Form
    {

        // 다음 주소는 Mongo DB의 관리자 계정으로 연결하는 주소입니다. 유출 되지 않도록 해주시기 바랍니다.
        public static IMongoClient client = new MongoClient("mongodb+srv://Team:08pkg7e73KqULAiI@parking.oql9wxv.mongodb.net/?retryWrites=true&w=majority");
        public static IMongoDatabase db = client.GetDatabase("vehicle_db"); // DB 불러오기. vehicle_db와 동일한 명칭을 가진 DB를 가져옴 
        public static IMongoCollection<regVehicles> collection_vihicles = db.GetCollection<regVehicles>("vehicles"); // colletion 불러오기. vehicles와 동일한 명칭을 가진 collection을 가져옴
        public static IMongoCollection<regSpace> collection_space = db.GetCollection<regSpace>("parkingSpace"); // colletion 불러오기. parkingSpace와 동일한 명칭을 가진 collection을 가져옴

        public long freeSpace = 0;  // 여유 주차공간
        public int freeSpace3F = 100; // 3층의 여유 주차공간
        public int freeSpace2F = 100; // 2층의 여유 주차공간
        public int freeSpace1F = 100; // 1층의 여유 주차공간

        public MainForm mainform;

        public RegisterForm(MainForm frm)
        {
            mainform = frm;
            InitializeComponent();

            // BD에서 모든 값을 리스트의 형태로 읽어오고 주차 공간에 대한 DB Collection이 없다면 추가
            List<regSpace> list = collection_space.AsQueryable().ToList();
            if (list == null || list.Count <= 0)
            {
                regSpace space = new regSpace(100, 100, 100); // 주차공간을 층마다 100 자리 배정
                collection_space.InsertOne(space); // DB에 삽입
            }

            readData();
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

        private void registerButton_Click(object sender, EventArgs e)
        {
            DateTime currentTime = DateTime.Now;
            bool isOnHours = false;


            // 등록하기 버튼 클릭 시간이 운영시간 내 인지 확인
            if (currentTime.DayOfWeek >= DayOfWeek.Monday && currentTime.DayOfWeek <= DayOfWeek.Friday)
            {
                if (currentTime.Hour >= 8 && currentTime.Hour <= 21)
                {
                    isOnHours = true;
                }
            }
            else
            {
                if (currentTime.Hour >= 10 && currentTime.Hour <= 21)
                {
                    isOnHours = true;
                }
            }


            if (!isOnHours)
            {
                MessageBox.Show("운영시간이 아닙니다!", "알림");
            }
            else if (carNumber.Text == "" || phoneNumber.Text == "" || carModel.Text == "")
            {
                MessageBox.Show("입력되지 않은 정보가 있습니다!", "알림");

            }
            else if (IsValidKoreanCarNumber(carNumber.Text) == false)
            {
                MessageBox.Show("올바르지 않은 차량번호 형식입니다.\r00가0000(또는 000가0000)형식으로 차량번호를 입력해 주세요", "알림");
            }
            else if (IsValidKoreanPhoneNumber(phoneNumber.Text) == false)
            {
                MessageBox.Show("올바르지 않은 전화번호 형식입니다.\r01X-XXXX-XXXX형식으로 전화번호를 입력해 주세요", "알림");
            }
            else if (freeSpace == 0) // 여유 주차공간이 없는 경우
            {
                // 여유 주차공간이 없음을 알리고 차량 등록 진행하지 않음
                MessageBox.Show("여유 주차공간이 없습니다.", "알림");
            }
            else // 여유 주차공간이 있는 경우
            {
                // 차량 등록 진행
                if (MessageBox.Show("차량 번호 : " + carNumber.Text + "\r차량 종류 : " + carModel.Text + "\r위의 내용으로 차량 등록을 진행합니다.", "차량 등록", MessageBoxButtons.YesNo) == DialogResult.Yes)
                {

                    string Floor = ""; // 주차할 층수를 저장

                    // 1층부터 차례대로 주차 (1층이 꽉 차면 2층, 2층이 꽉 차면 3층에 주차)
                    if (freeSpace1F == 0)
                    {
                        if (freeSpace2F == 0)
                        {
                            // 1,2층의 주차공간이 꽉 찬 경우
                            Floor = "3F";
                        }
                        else
                        {
                            // 1층의 주차공간만 꽉 찬 경우
                            Floor = "2F";
                        }
                    }
                    else
                    {
                        // 1층의 주차공간이 남은 경우
                        Floor = "1F";
                    }


                    // new regVehicles() 안에는 DB에 등록할 차량 정보 삽입
                    // DB에 DateTime.Now는 utc 시간으로 저장되므로, 한국시간인 UTC+9로 저장하도록 설정
                    regVehicles vehicle = new regVehicles(carNumber.Text, carModel.Text, Floor, phoneNumber.Text, DateTime.Now.AddHours(9));
                    // DB에 차량 정보 삽입
                    collection_vihicles.InsertOne(vehicle);

                    // 완료 메세지 띄우고 차량 등록 폼 닫기
                    MessageBox.Show("차량 등록이 완료되었습니다.\r주차된 장소는 " + Floor + "입니다\r확인 버튼을 누르시면 메인 화면으로 돌아갑니다.", "차량 등록 완료");
                    Close();
                }
                else
                {
                    MessageBox.Show("차량 등록을 취소하셨습니다.", "차량 등록 취소");
                }
            }
        }

        public void readData() // DB에서 주차된 정보 읽고 정보 갱신
        {
            // 주차장 자리 수 DB에서 읽어오기
            List<regSpace> listSpace = collection_space.AsQueryable().ToList();
            var F1Space = listSpace[0].F1Parked;
            var F2Space = listSpace[0].F2Parked;
            var F3Space = listSpace[0].F3Parked;

            parkingSpace.Text = (F1Space + F2Space + F3Space).ToString();
            parkingSpace1F.Text = "1층 : " + (F1Space).ToString() + " |";
            parkingSpace2F.Text = "2층 : " + (F2Space).ToString() + " |";
            parkingSpace3F.Text = "3층 : " + (F3Space).ToString() + " |";


            // DB에서 모든 값을 리스트의 형태로 읽어옴
            List<regVehicles> list = collection_vihicles.AsQueryable().ToList();

            if (list != null && list.Count > 0) // DB에 항목이 존재하는 경우
            {
                // 사용중인 자리수 DB에서 계산 
                var filter = Builders<regVehicles>.Filter.Eq("ParkingLocation", "1F");
                var F1usedSpace = collection_vihicles.Find(filter).Count();
                filter = Builders<regVehicles>.Filter.Eq("ParkingLocation", "2F");
                var F2usedSpace = collection_vihicles.Find(filter).Count();
                filter = Builders<regVehicles>.Filter.Eq("ParkingLocation", "3F");
                var F3usedSpace = collection_vihicles.Find(filter).Count();

                // 여석 계산
                var F1FreeSpace = F1Space - F1usedSpace;
                var F2FreeSpace = F2Space - F2usedSpace;
                var F3FreeSpace = F3Space - F3usedSpace;

                // 여유 주차공간 값 갱신 및 반영
                freeSpace = F1FreeSpace + F2FreeSpace + F3FreeSpace;
                freeParkingSpace.Text = freeSpace.ToString();
                // 갱신값 반영
                freeParkingSpace1F.Text = F1FreeSpace.ToString();
                freeParkingSpace2F.Text = F2FreeSpace.ToString();
                freeParkingSpace3F.Text = F3FreeSpace.ToString();

            }
            else // DB가 비어있을 경우
            {
                freeParkingSpace.Text = parkingSpace.Text;
                freeParkingSpace1F.Text = parkingSpace1F.Text;
                freeParkingSpace2F.Text = parkingSpace2F.Text;
                freeParkingSpace3F.Text = parkingSpace3F.Text;
            }
        }

        private void button1_Click(object sender, EventArgs e)
        {
            Close();
        }

        private void groupBox1_Enter(object sender, EventArgs e)
        {

        }

        private void RegisterForm_Load(object sender, EventArgs e)
        {

        }

        private void RegisterForm_FormClosed(object sender, FormClosedEventArgs e)
        {
            mainform.Visible = true;
        }

        private void carModel_SelectedIndexChanged(object sender, EventArgs e)
        {

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

    // 추가한 속성 (주차한 고객의 전화번호 : 장기간 차량을 찾지 않는 경우 대비)
    [BsonElement("UserPhoneNumber")] //주차 고객 전화번호
    public string UserPhoneNumber { get; set; }
    // 23-06-01 추가
    // 주차한 시각
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

public class regSpace
{
    [BsonId] // 고유 ID
    public ObjectId Id { get; set; }
    [BsonElement("1F")] // 1층 차량 수
    public int F1Parked { get; set; }
    [BsonElement("2F")] // 2층 차량 수
    public int F2Parked { get; set; }
    [BsonElement("3F")] // 3층 차량 수
    public int F3Parked { get; set; }

    // 이 부분을 통해 다른 Class와 값을 주고 받음. 개체 추가시 잊지 않도록 주의!
    public regSpace(int F1parked, int F2parked, int F3parked)
    {
        F1Parked = F1parked;
        F2Parked = F2parked;
        F3Parked = F3parked;
    }
}