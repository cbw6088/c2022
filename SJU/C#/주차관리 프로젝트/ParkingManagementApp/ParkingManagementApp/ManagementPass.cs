using MongoDB.Driver;
using System.Security.Cryptography;

namespace ParkingManagementApp
{
    public partial class ManagementPass : Form
    {
        // 다음 주소는 Mongo DB의 관리자 계정으로 연결하는 주소입니다. 유출 되지 않도록 해주시기 바랍니다.
        public static IMongoClient client = new MongoClient("mongodb+srv://Team:08pkg7e73KqULAiI@parking.oql9wxv.mongodb.net/?retryWrites=true&w=majority");
        public static IMongoDatabase db = client.GetDatabase("vehicle_db"); // DB 불러오기. vehicle_db와 동일한 명칭을 가진 DB를 가져옴 
        public static IMongoCollection<regManager> collection_manager = db.GetCollection<regManager>("managerData"); // managerData 불러오기. vehicles와 동일한 명칭을 가진 collection을 가져옴
        public MainForm mainform;

        public ManagementPass(MainForm frm)
        {
            InitializeComponent();
            mainform = frm;
        }

        private void ManagementPass_Load(object sender, EventArgs e)
        {

        }

        private void loginButton_Click(object sender, EventArgs e)
        {
            if (managerNumber.Text == "" || managerPassword.Text == "")
            {
                MessageBox.Show("입력되지 않은 정보가 있습니다!", "알림");
            }
            else
            {
                // 관리자 번호가 같은 데이터를 찾아낸다
                var filter = Builders<regManager>.Filter.Eq("ManagerNum", managerNumber.Text);
                try
                {
                    var managerData = collection_manager.Find(filter).Limit(1).Single();

                    string savedPasswordHash = managerData.ManagerPassword;
                    // bytes 추출
                    byte[] hashBytes = Convert.FromBase64String(savedPasswordHash);
                    // Salt 생성
                    byte[] salt = new byte[16];
                    Array.Copy(hashBytes, 0, salt, 0, 16);
                    // 입력된 비밀번호를 Hash계산
                    var pbkdf2 = new Rfc2898DeriveBytes(managerPassword.Text, salt, 100000); // 10000에서 숫자 올라가면 계산에 시간이 오래 걸립니다.
                    byte[] hash = pbkdf2.GetBytes(20);
                    // 결과값 비교
                    int hasAccepted = 1;
                    for (int i = 0; i < 20; i++)
                        if (hashBytes[i + 16] != hash[i])
                            hasAccepted = 0;

                    if (hasAccepted != 0)
                    {
                        // 비밀번호 통과
                        this.Visible = false;
                        Management window1 = new Management(mainform, this);
                        window1.ShowDialog();
                    }
                    else
                    {
                        MessageBox.Show("비밀번호가 일치하지 않습니다.", "알림");
                    }
                }
                catch
                {
                    MessageBox.Show("입력된 번호로 등록된 관리자가 없습니다.", "알림");
                }
            }
        }

        private void MngPass_FormClosed(object sender, FormClosedEventArgs e)
        {
            mainform.Visible = true;
        }

        private void Back_Button_Click(object sender, EventArgs e)
        {
            Close();
        }
    }
}
