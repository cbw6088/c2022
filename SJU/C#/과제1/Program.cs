/* VisualStudioCode를 사용하여 구현 */
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Threading.Tasks;

namespace assignment_1;

/*컴퓨터 클래스(부모)*/
public class Computer
{
    private static int comIdCounter = 0;
    public string is_avail;   
    private string ComType;
    protected int won;
    public int comID;
    protected string[] Use;

    public Computer()
    {
        comID = ++comIdCounter; // Computer ID 개수 증가
    }
}

/* 노트북 클래스 (자식) -> 컴퓨터 클래스 (부모) */
public class NoteBook : Computer
{
    private static int noteIdCounter = 0;
    private int noteId;

    /* 노트북에 필요한 최초 정보 초기화 */
    public NoteBook()
    {
        this.is_avail = "Y"; // 사용 가능 여부 초기화 (기본값은 "Y"로 사용 가능 상태)
        this.Use = new string[2]; // Use 배열 초기화
        this.Use[0] = "Internet"; // Use 배열의 첫 번째 요소 설정
        this.Use[1] = "Scientific"; // Use 배열의 두 번째 요소 설정

        noteId = ++noteIdCounter; // 노트북 아이디 저장
        this.won = 10000; // 노트북의 가격 설정
    }

    /* 노트북의 가격을 반환하는 메서드 */
    public int get_won()
    {
        return this.won;
    }

    /* Avail의 여부를 수정하는 메서드 */
    public int get_isAvail(string str)
    {
        if (str == "Y") // 'Y'는 'N'으로 변경하여 사용 중 상태로 설정
        {
            this.is_avail = "N";
            return noteId; // 노트북 아이디 반환
        }
        else // 'N'은 'Y'로 변경하여 사용 가능 상태로 설정
        {
            this.is_avail = "Y";
            return -1;
        }
    }

    /* 'S' 입력 시 나타나는 정보 중 일부를 출력하는 메서드 */
    public void getComInfo(StreamWriter writer)
    {
        writer.Write($"type: Notebook, ComId: {this.comID}, NoteId: {this.noteId}, Used for: {this.Use[0]}, {this.Use[1]}, Avail: {this.is_avail}");
    }
}


/* 데스크탑 클래스 (자식) -> 컴퓨터 클래스 (부모) */
public class DeskTop : Computer
{
    private static int deskIdCounter = 0;
    private int deskId;

    /* 데스크탑에 필요한 최초 정보 초기화 */
    public DeskTop()
    {
        this.is_avail = "Y"; // 사용 가능 여부 초기화 (기본값은 "Y"로 사용 가능 상태)
        this.Use = new string[3]; // Use 배열 초기화
        this.Use[0] = "Internet"; // Use 배열의 첫 번째 요소 설정
        this.Use[1] = "Scientific"; // Use 배열의 두 번째 요소 설정
        this.Use[2] = "Game"; // Use 배열의 세 번째 요소 설정

        deskId = ++deskIdCounter; // 데스크탑 아이디 저장
        this.won = 13000; // 데스크탑의 가격 설정
    }

    /* 데스크탑의 가격을 반환하는 메서드 */
    public int get_won()
    {
        return this.won;
    }
    
    /* Avail의 여부를 수정하는 메서드 */
    public int get_isAvail(string str)
    {
        if (str == "Y") // 'Y'는 'N'으로 변경하여 사용 중 상태로 설정
        {
            this.is_avail = "N";
            return deskId; // 데스크탑 아이디 반환
        }
        else // 'N'은 'Y'로 변경하여 사용 가능 상태로 설정
        {
            this.is_avail = "Y";
            return -1;
        }
    }

    /* 'S' 입력 시 나타나는 정보 중 일부를 출력하는 메서드 */
    public void getComInfo(StreamWriter writer)
    {
        writer.Write($"type: Desktop, ComId: {this.comID}, DeskId: {this.deskId}, Used for: {this.Use[0]}, {this.Use[1]}, {this.Use[2]}, Avail: {this.is_avail}");
    }
}

/*넷북 클래스(자식) -> 컴퓨터 클래스(부모)*/
public class NetBook : Computer
{
    private static int netIdCounter = 0;
    private int netId;

    /* 넷북에 필요한 최초 정보 초기화 */
    public NetBook()
    {
        this.is_avail = "Y"; // 사용 가능 여부 초기화 (기본값은 "Y"로 사용 가능 상태)
        this.Use = new string[1]; // Use 배열 초기화
        this.Use[0] = "Internet"; // Use 배열의 첫 번째 요소 설정

        netId = ++netIdCounter; // 넷북 아이디 저장
        this.won = 7000; // 넷북의 가격 설정
    }

    /* 넷북의 가격을 반환하는 메서드 */
    public int get_won()
    {
        return this.won;
    }

    /* Avail의 여부를 수정하는 메서드 */
    public int get_isAvail(string str)
    {
        if (str == "Y") // 'Y'는 'N'으로 변경하여 사용 중 상태로 설정
        {
            this.is_avail = "N";
            return netId; // 넷북 아이디 반환
        }
        else // 'N'은 'Y'로 변경하여 사용 가능 상태로 설정
        {
            this.is_avail = "Y";
            return -1;
        }
    }

    /* 'S' 입력 시 나타나는 정보 중 일부를 출력하는 메서드 */
    public void getComInfo(StreamWriter writer)
    {
        writer.Write($"type: Netbook, ComId: {this.comID}, NetId: {this.netId}, Used for: {this.Use[0]}, Avail: {this.is_avail}");
    }
}

/*유저 클래스(부모)*/
public class User
{
    private static int userIdCounter = 0;   
    protected int UserID;
    protected string UserType;
    protected string UserName;
    protected string[] Use;
    public string is_rent;

    public User()
    {
        UserID = ++userIdCounter; // 유저 아이디 증가
    }
}

/*학생 클래스(자식) -> 유저 클래스(부모)*/
public class Student : User
{
    private static int studIdCounter = 0;   
    protected int studID;

    /* 학생에 필요한 최초 정보 초기화 */
    public Student(string UserName, string UserType)
    {
        this.is_rent = "N"; // 학생의 렌트 여부를 초기값으로 설정 (기본값은 "N"으로 미렌트 상태)
        studID = ++studIdCounter; // 학생 ID를 증가시키며 할당
        this.Use = new string[2]; // Use 배열 초기화
        this.UserName = UserName; // 사용자 이름 설정
        this.UserType = UserType; // 사용자 유형 설정
        this.Use[0] = "Internet"; // Use 배열의 첫 번째 요소 설정
        this.Use[1] = "Scientific"; // Use 배열의 두 번째 요소 설정
    }

    /* 'S' 입력 시 나타나는 정보 일부 출력 */
    public void getUserInfo(StreamWriter writer)
    {
        writer.Write($"type: Student, Name: {this.UserName}, UserId: {this.UserID}, StudId: {this.studID}, Used for: {this.Use[0]}, {this.Use[1]}, Rent: {this.is_rent}");
    }

    /* 렌트 여부 수정 */
    public void setRent()
    {
        if (this.is_rent == "N")
            this.is_rent = "Y";
        else if (this.is_rent == "Y")
            this.is_rent = "N";
    }
}


/*직장인 클래스(자식) -> 유저 클래스(부모)*/
public class Worker : User
{
    private static int workIdCounter = 0;   
    protected int workID;

    /* 직장인에 필요한 최초 정보 초기화 */
    public Worker(string UserName, string UserType)
    {
        this.is_rent = "N"; // 직장인의 렌트 여부를 초기값으로 설정 (기본값은 "N"으로 미렌트 상태)
        workID = ++workIdCounter; // 직장 ID를 증가시키며 할당
        this.Use = new string[1]; // Use 배열 초기화
        this.UserName = UserName; // 사용자 이름 설정
        this.UserType = UserType; // 사용자 유형 설정
        this.Use[0] = "Internet"; // Use 배열의 첫 번째 요소 설정
    }

    /* 'S' 입력 시 나타나는 정보 일부 출력 */
     public void getUserInfo(StreamWriter writer)
    {
        writer.Write($"type: Worker, Name: {this.UserName}, UserId: {this.UserID}, WorkId: {this.workID}, Used for: {this.Use[0]}, Rent: {this.is_rent}");
    }

    /* 렌트 여부 수정 */
    public void setRent()
    {
        if (this.is_rent == "N")
            this.is_rent = "Y";
        else if (this.is_rent == "Y")
            this.is_rent = "N";
    }
}

/*게이머 클래스(자식) -> 유저 클래스(부모)*/
public class Gamer : User
{
    private static int gameIdCounter = 0;   
    protected int gameID;

    /* 게이머에 필요한 최초 정보 초기화 */
    public Gamer(string UserName, string UserType)
    {
        this.is_rent = "N"; // 게이머의 렌트 여부를 초기값으로 설정 (기본값은 "N"으로 미렌트 상태)
        gameID = ++gameIdCounter; // 게임 ID를 증가시키며 할당
        this.Use = new string[2]; // Use 배열 초기화
        this.UserName = UserName; // 사용자 이름 설정
        this.UserType = UserType; // 사용자 유형 설정
        this.Use[0] = "Internet"; // Use 배열의 첫 번째 요소 설정
        this.Use[1] = "Game"; // Use 배열의 두 번째 요소 설정
    }

    /* 'S' 입력 시 나타나는 정보 일부 출력 */
     public void getUserInfo(StreamWriter writer)
    {
        writer.Write($"type: Gamer, Name: {this.UserName}, UserId: {this.UserID}, gameId: {this.gameID}, Used for: {this.Use[0]}, {this.Use[1]}, Rent: {this.is_rent}");
    }

    /* 렌트 여부 수정 */
    public void setRent()
    {
        if (this.is_rent == "N")
            this.is_rent = "Y";
        else if (this.is_rent == "Y")
            this.is_rent = "N";
    }
}

/*컴퓨터 매니저 클래스*/
public class ComputerManager
{
    private Computer[] arrComp;
    private User[] arrUser;
    public int totalCost;
    public int[,] usertime;

    /*최초 대여 가능한 컴퓨터 정보 + 대여할 user 정보 삽입*/
    public ComputerManager(User[] users, Computer[] computers)
    {
        this.totalCost = 0;
        this.arrComp = computers;
        this.arrUser = users;
        this.usertime = new int[users.Length + 1, 6];
    }

    /* 컴퓨터에 대한 정보 및 출력 메소드 */
    public void get_ComList(StreamWriter writer) // 리스트 
    {
        int numOfCom = 1; // 컴퓨터 번호 카운터
        int numOfUser = 1; // 사용자 번호 카운터
        writer.WriteLine($"Total Cost: {this.totalCost}"); // 총 비용 출력
        writer.WriteLine($"Computer List:"); // 컴퓨터 목록 출력

        // 컴퓨터 목록 출력
        for (int i = 0; i < arrComp.Length; i++)
        {
            writer.Write($" ({numOfCom++})"); // 컴퓨터 번호 출력

            // 컴퓨터의 종류에 따라 해당 정보 출력
            if (arrComp[i] is NoteBook)
                ((NoteBook)arrComp[i]).getComInfo(writer); // 노트북 정보 출력
            else if (arrComp[i] is DeskTop)
                ((DeskTop)arrComp[i]).getComInfo(writer); // 데스크탑 정보 출력
            else if (arrComp[i] is NetBook)
                ((NetBook)arrComp[i]).getComInfo(writer); // 넷북 정보 출력

            // 컴퓨터가 대여 중인 경우 해당 사용자 정보 출력
            if (this.arrComp[i].is_avail == "N")
            {
                for (int j = 1; j <= arrUser.Length; j++)
                {
                    if (this.arrComp[i].comID == usertime[j, 0])
                    {
                        writer.Write($"(UserId: {j}, DR: {usertime[j, 1]}, DL: {usertime[j, 2]}, DU: {usertime[j, 3]})");
                        break;
                    }
                }
            }
            writer.WriteLine(); // 줄 바꿈
        }
        writer.WriteLine($"User List:");
        for (int i = 0; i < arrUser.Length; i++)
        {
            writer.Write($" ({numOfUser++})"); // 사용자 번호 출력

            // 사용자의 종류에 따라 해당 정보 출력
            if (arrUser[i] is Student)
            {
                ((Student)arrUser[i]).getUserInfo(writer); // 학생 정보 출력

                // 학생이 대여 중인 경우 대여된 컴퓨터 ID 출력
                if (((Student)arrUser[i]).is_rent != "N")
                    writer.Write($"(RentComId: {this.usertime[i + 1, 0]})");
            }
            if (arrUser[i] is Worker)
            {
                ((Worker)arrUser[i]).getUserInfo(writer); // 직장인 정보 출력

                // 직장인이 대여 중인 경우 대여된 컴퓨터 ID 출력
                if (((Worker)arrUser[i]).is_rent == "Y")
                    writer.Write($"(RentComId: {this.usertime[i + 1, 0]})");
            }
            if (arrUser[i] is Gamer)
            {
                ((Gamer)arrUser[i]).getUserInfo(writer); // 게이머 정보 출력

                // 게이머가 대여 중인 경우 대여된 컴퓨터 ID 출력
                if (((Gamer)arrUser[i]).is_rent == "Y")
                    writer.Write($"(RentComId: {this.usertime[i + 1, 0]})");
            }
            writer.WriteLine(); // 줄 바꿈
        }
        writer.WriteLine("===========================================================");
    }

    /* 반환시 작동하는 메소드 */
    public void return_Computer(int userId, StreamWriter writer)
    {
        if (usertime[userId, 4] == 1)
        {
            pay(userId, 1, writer); // 반납의 경우에 대한 처리를 위해 `pay` 메서드 호출
        }
    }

    /* 시간 명령어 입력시 작동하는 메소드 */
    public void time_Lend(StreamWriter writer)
    {
        for (int i = 1; i <= arrUser.Length; i++)
        {
            if (usertime[i, 4] == 1)
            {
                this.usertime[i, 2]--; // 남은 대여 일수를 1일 감소시킴
                this.usertime[i, 3]++; // 대여 기간을 1일 증가시킴
            }
        }
        writer.WriteLine("It has passed one day..."); // 하루가 지났음을 출력

        // 대여 기간이 만료된 사용자들에 대해 처리를 위해 `pay` 메서드 호출
        for (int i = 1; i <= arrUser.Length; i++)
        {
            pay(i, 0, writer);
        }

        writer.WriteLine("===========================================================");
    }

    /* 반환 및 타임아웃으로 작동하는 메소드 */
    private void pay(int i, int flag, StreamWriter writer)
    { 
        if (usertime[i, 4] == 1 && usertime[i, 2] == 0)
        {
            if (flag == 0)
            {
                writer.WriteLine($"Time for Computer #{usertime[i, 0]} has expired. User #{i} has returned Computer #{usertime[i, 0]} and paid {usertime[i, 5] * usertime[i, 1]} won.");
                this.totalCost += usertime[i, 5] * usertime[i, 1]; // 기기 금액 * 남은 기간을 전체 비용에 추가
            }
            usertime[i, 4] = 0; // 대여 상태를 종료로 변경

            // 사용자의 유형에 따라 해당 컴퓨터를 대여 가능한 상태로 변경
            if (arrUser[i - 1] is Student)
            {
                ((Student)arrUser[i - 1]).setRent();
                ((NoteBook)arrComp[usertime[i, 0] - 1]).get_isAvail("N");
            }
            if (arrUser[i - 1] is Worker)
            {
                ((Worker)arrUser[i - 1]).setRent();
                ((NetBook)arrComp[usertime[i, 0] - 1]).get_isAvail("N");
            }
            if (arrUser[i - 1] is Gamer)
            {
                ((Gamer)arrUser[i - 1]).setRent();
                ((DeskTop)arrComp[usertime[i, 0] - 1]).get_isAvail("N");
            }
        }
        else if (usertime[i, 4] == 1 && usertime[i, 2] != 0 && flag != 0)
        {
            writer.WriteLine($"User #{i} has returned Computer #{usertime[i, 0]} and paid {usertime[i, 5] * usertime[i, 3]} won.");
            this.totalCost += usertime[i, 5] * usertime[i, 3]; // 기기 금액 * 사용 기간을 전체 비용에 추가
            usertime[i, 4] = 0; // 대여 상태를 종료로 변경

            // 사용자의 유형에 따라 해당 컴퓨터를 대여 가능한 상태로 변경
            if (arrUser[i - 1] is Student)
            {
                ((Student)arrUser[i - 1]).setRent();
                ((NoteBook)arrComp[usertime[i, 0] - 1]).get_isAvail("N");
            }
            if (arrUser[i - 1] is Worker)
            {
                ((Worker)arrUser[i - 1]).setRent();
                ((NetBook)arrComp[usertime[i, 0] - 1]).get_isAvail("N");
            }
            if (arrUser[i - 1] is Gamer)
            {
                ((Gamer)arrUser[i - 1]).setRent();
                ((DeskTop)arrComp[usertime[i, 0] - 1]).get_isAvail("N");
            }
        }
    }

    /* 할당시 작동하는 메소드 */
    public void lendComputer(int userId, int period, StreamWriter writer)
    {
        if(arrUser[userId-1] is Student)
        {
            for(int i=0; i<arrComp.Length; i++){ // 게임방에 등록된 컴퓨터 다 순회
                if(arrComp[i] is NoteBook)
                { // 그 컴퓨터가 노트북인 경우
                    int temp = ((NoteBook)arrComp[i]).get_isAvail("Y"); // 렌트가 불가능하면 0  렌트가 가능하면 노트북 id 반환
                    if(temp != -1){
                        ((Student)arrUser[userId-1]).setRent();
                        writer.WriteLine($"Computer #{this.arrComp[i].comID} has been assinged to User #{userId}");
                        writer.WriteLine("===========================================================");
                        this.usertime[userId, 0] = this.arrComp[i].comID; // 컴퓨터 ID
                        this.usertime[userId, 1] = period; // 할당 기간
                        this.usertime[userId, 2] = period; // 남은 기간
                        this.usertime[userId, 3] = 0; // 사용 기간
                        this.usertime[userId, 4] = 1; // 렌트 여부
                        this.usertime[userId, 5] = ((NoteBook)arrComp[i]).get_won(); // 기기 금액
                        break;
                    }
                }
            }        
        }
        else if(arrUser[userId-1] is Worker)
        {
            for(int i=0; i<arrComp.Length; i++)
            {
                if(arrComp[i] is NetBook)
                { // 그 컴퓨터가 넷북인 경우
                    int temp = ((NetBook)arrComp[i]).get_isAvail("Y"); // 렌트가 불가능하면 0  렌트가 가능하면 노트북 id 반환
                    if(temp != -1){
                        ((Worker)arrUser[userId-1]).setRent();
                        writer.WriteLine($"Computer #{this.arrComp[i].comID} has been assinged to User #{userId}");
                        writer.WriteLine("===========================================================");
                        this.usertime[userId, 0] = this.arrComp[i].comID; // 컴퓨터 ID
                        this.usertime[userId, 1] = period; // 할당 기간
                        this.usertime[userId, 2] = period; // 남은 기간
                        this.usertime[userId, 3] = 0; // 사용 기간
                        this.usertime[userId, 4] = 1; // 렌트 여부
                        this.usertime[userId, 5] = ((NetBook)arrComp[i]).get_won(); // 기기 금액
                        break;
                    }
                }
            }
        }
        else if(arrUser[userId-1] is Gamer)
        {
            for(int i=0; i<arrComp.Length; i++)
            {
                if(arrComp[i] is DeskTop)
                { // 그 컴퓨터가 테스크탑인 경우
                    int temp = ((DeskTop)arrComp[i]).get_isAvail("Y"); // 렌트가 불가능하면 -1  렌트가 가능하면 노트북 id 반환
                    if(temp != -1){
                        ((Gamer)arrUser[userId-1]).setRent();
                        writer.WriteLine($"Computer #{this.arrComp[i].comID} has been assinged to User #{userId}");
                        writer.WriteLine("===========================================================");
                        this.usertime[userId, 0] = this.arrComp[i].comID; // 컴퓨터 ID
                        this.usertime[userId, 1] = period; // 할당 기간
                        this.usertime[userId, 2] = period; // 남은 기간
                        this.usertime[userId, 3] = 0; // 사용 기간
                        this.usertime[userId, 4] = 1; // 렌트 여부
                        this.usertime[userId, 5] = ((DeskTop)arrComp[i]).get_won(); // 기기 금액
                        break;
                    }
                }
            }
        }
    }
}

public class Program
{
    static void Main(string[] args)
    {    
        // input.txt 파일에서 입력을 읽어옵니다.
        string[] inputLines = File.ReadAllLines("input.txt");
        int lineIndex = 0;

        // 컴퓨터와 사용자의 정보를 초기화합니다.
        int total = int.Parse(inputLines[lineIndex++]);
        Computer[] computers = new Computer[total];
        string machine = inputLines[lineIndex++];
        int note = int.Parse(machine.Split(' ')[0]);
        int desk = int.Parse(machine.Split(' ')[1]);
        int net = int.Parse(machine.Split(' ')[2]);

        // 컴퓨터 객체를 생성하여 배열에 저장합니다.
        for (int i = 0; i < total; i++)
        {
            if (i < net) computers[i] = new NetBook();
            else if (i < note + net) computers[i] = new NoteBook(); 
            else if (i < desk + net + note) computers[i] = new DeskTop();
        }

        int userCount = int.Parse(inputLines[lineIndex++]);
        User[] users = new User[userCount];
        string[] job = new string[userCount];
        string[] name = new string[userCount];

        // 사용자 객체를 생성하여 배열에 저장합니다.
        for (int i = 0; i < userCount; i++)
        {
            string str = inputLines[lineIndex++];
            job[i] = str.Split(' ')[0]; 
            name[i] = str.Split(' ')[1]; 
            if (job[i] == "Student") users[i] = new Student(name[i], job[i]);
            else if (job[i] == "Worker") users[i] = new Worker(name[i], job[i]);
            else if (job[i] == "Gamer") users[i] = new Gamer(name[i], job[i]);
        }

        // ComputerManager 객체를 생성합니다.
        ComputerManager manager = new ComputerManager(users, computers);

        // output.txt 파일에 출력을 작성합니다.
        using (StreamWriter writer = new StreamWriter("output.txt"))
        {
            while (true)
            {
                string item = inputLines[lineIndex++];
                if (item.Equals("Q")) break;
                else if (item[0] == 'A') // 'A' 입력 시 함수 호출
                {
                    int str1 = int.Parse(item.Split(' ')[1]);
                    int str2 = int.Parse(item.Split(' ')[2]);
                    manager.lendComputer(str1, str2, writer);
                }
                else if (item[0] == 'R') // 'R' 입력 시 함수 호출
                {
                    int day = int.Parse(item.Split(' ')[1]);
                    manager.return_Computer(day, writer);
                }
                else if (item.Equals("T")) manager.time_Lend(writer); // 'T' 입력 시 함수 호출
                else if (item.Equals("S")) manager.get_ComList(writer); // // 'S' 입력 시 함수 호출
            }
            writer.Flush();
        }
    }
}