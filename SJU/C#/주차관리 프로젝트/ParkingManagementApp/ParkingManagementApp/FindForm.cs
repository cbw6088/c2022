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
        // ´ÙÀ½ ÁÖ¼Ò´Â Mongo DBÀÇ °ü¸®ÀÚ °èÁ¤À¸·Î ¿¬°áÇÏ´Â ÁÖ¼ÒÀÔ´Ï´Ù. À¯Ãâ µÇÁö ¾Êµµ·Ï ÇØÁÖ½Ã±â ¹Ù¶ø´Ï´Ù.
        public static IMongoClient client = new MongoClient("mongodb+srv://Team:08pkg7e73KqULAiI@parking.oql9wxv.mongodb.net/?retryWrites=true&w=majority");
        public static IMongoDatabase db = client.GetDatabase("vehicle_db"); // DB ºÒ·¯¿À±â. vehicle_db¿Í µ¿ÀÏÇÑ ¸íÄªÀ» °¡Áø DB¸¦ °¡Á®¿È 
        public static IMongoCollection<regVehicles> collection = db.GetCollection<regVehicles>("vehicles"); // colletion ºÒ·¯¿À±â. vehicles¿Í µ¿ÀÏÇÑ ¸íÄªÀ» °¡Áø collectionÀ» °¡Á®¿È
        public static IMongoCollection<regSpace> collection_space = db.GetCollection<regSpace>("parkingSpace"); // colletion ºÒ·¯¿À±â. parkingSpace¿Í µ¿ÀÏÇÑ ¸íÄªÀ» °¡Áø collectionÀ» °¡Á®¿È
        //LocationCheck.PanelView screen = new LocationCheck.PanelView();

        public MainForm mainform;
        private RegisterForm registerForm;

        public FindForm(MainForm frm)
        {
            mainform = frm;
            InitializeComponent();
        }

        // ¿Ã¹Ù¸¥ ÇÑ±¹ ÈÞ´ëÆù ¹øÈ£ÀÎÁö °Ë»çÇÏ´Â ÇÔ¼ö
        static bool IsValidKoreanCarNumber(string carNumber)
        {
            string pattern = @"^([0-9]{2,3})[°¡-ÆR]([0-9]{4})$";
            return Regex.IsMatch(carNumber, pattern);
        }
        // ¿Ã¹Ù¸¥ ÇÑ±¹ ÈÞ´ëÆù ¹øÈ£ÀÎÁö °Ë»çÇÏ´Â ÇÔ¼ö
        static bool IsValidKoreanPhoneNumber(string phoneNumber)
        {
            string pattern = @"^01([0|1|6|7|8|9])-([0-9]{3,4})-([0-9]{4})$";
            return Regex.IsMatch(phoneNumber, pattern);
        }

        private void findButton_Click(object sender, EventArgs e)
        {
            string CarNumber = Car_Info.Text; // ÀÔ·ÂµÈ Â÷·® ¹øÈ£ ÀúÀå
            string ModelName = Model_Info.Text; // ÀÔ·ÂµÈ Â÷·® ¸ðµ¨ ÀúÀå
            string PhoneNumber = Phone_Info.Text; // ÀÔ·ÂµÈ ÀüÈ­ ¹øÈ£ ÀúÀå
            string UserPayment; // ÀÌ¿ë ±Ý¾×s
            bool UserInfoCheck = false; // À¯ÀúÀÇ Á¤º¸°¡ ¿Ã¹Ù¸¥Áö Ã¼Å©

            if (Car_Info.Text == "" || Phone_Info.Text == "" || Model_Info.Text == "")
            {
                MessageBox.Show("ÀÔ·ÂµÇÁö ¾ÊÀº Á¤º¸°¡ ÀÖ½À´Ï´Ù!", "¾Ë¸²");

            }
            else if (IsValidKoreanCarNumber(Car_Info.Text) == false)
            {
                MessageBox.Show("¿Ã¹Ù¸£Áö ¾ÊÀº Â÷·®¹øÈ£ Çü½ÄÀÔ´Ï´Ù.\r00°¡0000(¶Ç´Â 000°¡0000)Çü½ÄÀ¸·Î Â÷·®¹øÈ£¸¦ ÀÔ·ÂÇØ ÁÖ¼¼¿ä", "¾Ë¸²");
            }
            else if (IsValidKoreanPhoneNumber(Phone_Info.Text) == false)
            {
                MessageBox.Show("¿Ã¹Ù¸£Áö ¾ÊÀº ÀüÈ­¹øÈ£ Çü½ÄÀÔ´Ï´Ù.\r01X-XXXX-XXXXÇü½ÄÀ¸·Î ÀüÈ­¹øÈ£¸¦ ÀÔ·ÂÇØ ÁÖ¼¼¿ä", "¾Ë¸²");
            }
            else
            {
                List<regVehicles> list = collection.AsQueryable().ToList(); // regVehicles¸¦ ¼øÈ¸ÇÏ±â À§ÇÑ ¸®½ºÆ®
                int idx = 0;
                PayForm payform;
                for (int i = list.Count - 1; i >= 0; i--)
                {
                    regVehicles vehicle = list[i];
                    if (CarNumber == vehicle.VehicleNum && ModelName == vehicle.ModelName && PhoneNumber == vehicle.UserPhoneNumber)
                    {
                        idx = i; // È¸¿ø Á¤º¸ ÀÎµ¦½º ÀúÀå
                        UserInfoCheck = true;
                        DateTime StartTime = vehicle.ParkingTime; // µî·Ï ½Ã°£
                        DateTime EndTime = DateTime.Now; // ÇöÀç ½Ã°£
                        TimeSpan elapsedTime = EndTime - StartTime; // ÇöÀç ½Ã°£ - µî·Ï ½Ã°£
                        if((int)elapsedTime.TotalMinutes < 0)
                        {
                            UserPayment = "0";
                        }
                        else if ((int)elapsedTime.TotalMinutes < 30) // ±âº» ½Ã°£ ÀÌ¿ë
                        {
                            UserPayment = "1500";
                        }
                        else // ±âº» ½Ã°£º¸´Ù ¿À·¡ ÀÌ¿ë
                        {
                            UserPayment = ((((int)elapsedTime.TotalMinutes - 30) / 10 + 1) * 500 + 1500).ToString(); // ¿ä±Ý °è»ê (¤¤±âº» 1500, 10ºÐ Ãß°¡ 500)
                        }
                        payform = new PayForm((int)elapsedTime.TotalMinutes, vehicle.ParkingLocation, UserPayment); // °áÁ¦Æû¿¡ Á¤º¸ Àü´Þ
                        payform.ShowDialog();

                        if(payform.PayCheck == true)
                        {
                            string vehicleNumToRemove = CarNumber; // Á¦°ÅÇÒ Â÷·® ¹øÈ£
                            FilterDefinition<regVehicles> filter = Builders<regVehicles>.Filter.Eq(x => x.VehicleNum, vehicleNumToRemove); // Â÷ ¹øÈ£°¡ °°Àº °æ¿ì(°íÀ¯ ¹øÈ£)

                            collection.DeleteMany(filter); // °áÁ¦ ¿Ï·áµÈ Á¤º¸´Â Á¦°Å
                        }
                        Close();
                    }
                }
                if (UserInfoCheck == false)
                {
                    MessageBox.Show("È¸¿ø Á¤º¸°¡ Àß¸ø ÀÔ·Â µÇ¾ú½À´Ï´Ù.", "¾Ë¸²", MessageBoxButtons.OK, MessageBoxIcon.Warning);
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
        public void readData() // DB¿¡¼­ ÁÖÂ÷µÈ Á¤º¸ ÀÐ°í Á¤º¸ °»½Å
        {

        }
        private void textBox1_TextChanged(object sender, EventArgs e)
        {

        }

        public class regVehicles // DBÀÇ Model¼³Á¤
        {
            // [Bson] ÇüÅÂÀÇ ºÎºÐÀº ¾Æ·¡ÀÇ º¯¼ö¿Í ¸ÅÇÎµÇ¾î MongoDB¿¡¼­ »ç¿ëµÇ±â ¶§¹®¿¡ ²À ³Ö¾îÁÖ¾î¾ßÇÔ
            [BsonId] // °íÀ¯ ID
            public ObjectId Id { get; set; }
            [BsonElement("VehicleNum")] // Â÷·® ¹øÈ£
            public string VehicleNum { get; set; }
            [BsonElement("ModelName")] // Â÷Á¾
            public string ModelName { get; set; }
            [BsonElement("ParkingLocation")] //ÁÖÂ÷ À§Ä¡
            public string ParkingLocation { get; set; }
            [BsonElement("UserPhoneNumber")] //ÁÖÂ÷ °í°´ ÀüÈ­¹øÈ£
            public string UserPhoneNumber { get; set; }
            [BsonElement("ParkingTime")]
            public DateTime ParkingTime { get; set; }

            // ÀÌ ºÎºÐÀ» ÅëÇØ ´Ù¸¥ Class¿Í °ªÀ» ÁÖ°í ¹ÞÀ½. °³Ã¼ Ãß°¡½Ã ÀØÁö ¾Êµµ·Ï ÁÖÀÇ!
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