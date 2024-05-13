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
            Time_Info.Text = TimeInput.ToString() + "분";
            Location_Info.Text = LocationInput;
            Pay_Info.Text = PayInput;
            PayCheck = false;
        }

        public int Get_Time()
        {
            return this.TimeInput; // 받은 값을 반환하는 메서드를 제공합니다.
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
            MessageBox.Show("결제가 완료 되었습니다..", "알림", MessageBoxButtons.OK, MessageBoxIcon.Warning);
            Close();
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

            // 이 부분을 통해 다른 Class와 값을 주고 받음. 개체 추가시 잊지 않도록 주의!
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
                MessageBox.Show("결제가 취소 되었습니다.", "알림", MessageBoxButtons.OK, MessageBoxIcon.Warning);
            }
        }
    }
}

