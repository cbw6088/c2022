﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Threading.Tasks;

namespace assignment_1;

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
        comID = ++comIdCounter;   
    }
}

public class NoteBook : Computer
{
    private static int noteIdCounter = 0;
    private int noteId;
    
    public NoteBook()
    {
        this.is_avail = "Y";
        this.Use = new string[2];
        this.Use[0] = "Internet";
        this.Use[1] = "Scientific";

        noteId = ++noteIdCounter;
        this.won = 10000;
    }

    public int get_won()
    {
        return this.won;
    }
    public int get_isAvail(string str)
    {
        if(str == "Y")
        {
            this.is_avail = "N";
            return noteId;
        }
        else
        {
            this.is_avail = "Y";
            return -1;
        }
    }

    public void getComInfo()
    {
        Console.Write($"type: Notebook, ComId: {this.comID}, NoteId: {this.noteId}, Used for: {this.Use[0]}, {this.Use[1]}, Avail: {this.is_avail}");
    }
}

public class DeskTop : Computer
{
    private static int deskIdCounter = 0;
    private int deskId;
    public DeskTop()
    {
        this.is_avail = "Y";
        this.Use = new string[3];
        this.Use[0] = "Internet";
        this.Use[1] = "Scientific";
        this.Use[2] = "Game";

        deskId = ++deskIdCounter;
        this.won = 13000;
    }

    public int get_won()
    {
        return this.won;
    }
    
    public int get_isAvail(string str)
    {
        if(str == "Y")
        {
            this.is_avail = "N";
            return deskId;
        }
        else
        {
            this.is_avail = "Y";
            return -1;
        }
    }

    public void getComInfo()
    {
        Console.Write($"type: Desktop, ComId: {this.comID}, DeskId: {this.deskId}, Used for: {this.Use[0]}, {this.Use[1]}, {this.Use[2]}, Avail: {this.is_avail}");
    }
}

public class NetBook : Computer
{
    private static int netIdCounter = 0;
    private int netId;
    public NetBook()
    {
        this.is_avail = "Y";
        this.Use = new string[1];
        this.Use[0] = "Internet";

        netId = ++netIdCounter;
        this.won = 7000;
    }

    public int get_won()
    {
        return this.won;
    }

    public int get_isAvail(string str)
    {
        if(str == "Y")
        {
            this.is_avail = "N";
            return netId;
        }
        else
        {
            this.is_avail = "Y";
            return -1;
        }
    }

    public void getComInfo()
    {
        Console.Write($"type: Netbook, ComId: {this.comID}, NetId: {this.netId}, Used for: {this.Use[0]}, Avail: {this.is_avail}");
    }
}

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
        UserID = ++userIdCounter;
    }
}

public class Student : User
{
    private static int studIdCounter = 0;   
    protected int studID;
    public Student(string UserName, string UserType)
    {
        this.is_rent = "N";
        studID = ++studIdCounter;
        this.Use = new string[2];
        this.UserName = UserName;
        this.UserType = UserType;
        this.Use[0] = "Internet";
        this.Use[1] = "Scientific";
    }
     public void getUserInfo()
    {
        Console.Write($"type: Studnet, Name: {this.UserName}, UsereId: {this.UserID}, StudId:{this.studID}, Used for: {this.Use[0]}, {this.Use[1]}, Rent: {this.is_rent}");
    }

    public void setRent()
    {
        if(this.is_rent == "N")
            this.is_rent = "Y";
        else if(this.is_rent == "Y")
            this.is_rent = "N";
    }
}

public class Worker : User
{
    private static int workIdCounter = 0;   
    protected int workID;
    public Worker(string UserName, string UserType)
    {
        this.is_rent = "N";
        workID = ++workIdCounter;
        this.Use = new string[1];
        this.UserName = UserName;
        this.UserType = UserType;
        this.Use[0] = "Internet";
    }
     public void getUserInfo()
    {
        Console.Write($"type: Worker, Name: {this.UserName}, UsereId: {this.UserID}, WorkId:{this.workID}, Used for: {this.Use[0]}, Rent: {this.is_rent}");
    }

    public void setRent()
    {
        if(this.is_rent == "N")
            this.is_rent = "Y";
        else if(this.is_rent == "Y")
            this.is_rent = "N";
    }
}

public class Gamer : User
{
    private static int gameIdCounter = 0;   
    protected int gameID;
    public Gamer(string UserName, string UserType)
    {
        this.is_rent = "N";
        gameID = ++gameIdCounter;
        this.Use = new string[2];
        this.UserName = UserName;
        this.UserType = UserType;
        this.Use[0] = "Internet";
        this.Use[1] = "Game";
    }
     public void getUserInfo()
    {
        Console.Write($"type: Gamer, Name: {this.UserName}, UsereId: {this.UserID}, gameId:{this.gameID}, Used for: {this.Use[0]}, {this.Use[1]}, Rent: {this.is_rent}");
    }

    public void setRent()
    {
        if(this.is_rent == "N")
            this.is_rent = "Y";
        else  if(this.is_rent == "Y")
            this.is_rent = "N";
    }
}

public class ComputerManager
{
    private Computer[] arrComp;
    private User[] arrUser;
    public int totalCost;
    public int[,] usertime;

    public ComputerManager(User[] users, Computer[] computers) // 최초 대여 가능한 컴퓨터 정보 + 대여할 user 정보 삽입
    {
        this.totalCost = 0;
        this.arrComp = computers;
        this.arrUser = users;
        this.usertime = new int[users.Length + 1, 6];
    }

    public void get_ComList() // 리스트 
    {
        int numOfCom = 1;
        int numOfUser = 1;
        Console.WriteLine($"Total Cost: {this.totalCost}");
        Console.WriteLine($"Computer List:");
        // for 반복
        
        for(int i=0; i<arrComp.Length; i++){ // Computer list
            Console.Write($" ({numOfCom++})");
            if (arrComp[i] is NoteBook) ((NoteBook)arrComp[i]).getComInfo();
            else if (arrComp[i] is DeskTop)
                ((DeskTop)arrComp[i]).getComInfo();
            else if (arrComp[i] is NetBook)
                ((NetBook)arrComp[i]).getComInfo();
            if(this.arrComp[i].is_avail == "N")
            {
                for(int j=1; j<=arrUser.Length; j++)
                {
                    if(this.arrComp[i].comID == usertime[j, 0])
                    {
                        Console.Write($"(UserId: {j}, DR: {usertime[j,1]}, DL: {usertime[j,2]}, DU: {usertime[j,3]})");
                        break;
                    }
                }
            }
            Console.WriteLine();
        }
        Console.WriteLine($"User List:");
        for(int i=0; i<arrUser.Length; i++){ //User List
            Console.Write($" ({numOfUser++})");
            if(arrUser[i] is Student)
            {
                ((Student)arrUser[i]).getUserInfo();
                if(((Student)arrUser[i]).is_rent != "N") Console.Write($"(RentComId: {this.usertime[i+1, 0]})");
            }
            if(arrUser[i] is Worker)
            {
                ((Worker)arrUser[i]).getUserInfo();
                if(((Worker)arrUser[i]).is_rent == "Y") Console.Write($"(RentComId: {this.usertime[i+1, 0]})");
            }
            if(arrUser[i] is Gamer)
            {
                ((Gamer)arrUser[i]).getUserInfo();
                if(((Gamer)arrUser[i]).is_rent == "Y") Console.Write($"(RentComId: {this.usertime[i+1, 0]})");
            }
            Console.WriteLine();
        }  
        Console.WriteLine("===========================================================");
    }

    public void return_Computer(int userId)
    {
        if(usertime[userId, 4] == 1)
        {
            pay(userId, 1);
        }
    }

    public void time_Lend()
    {
        for(int i=1; i<=arrUser.Length; i++)
        {
            if(usertime[i,4] == 1)
            {
                this.usertime[i, 2]--;
                this.usertime[i, 3]++; 
            }
        }
        Console.WriteLine("It has passed one day...");
        for(int i=1; i<=arrUser.Length; i++)
        {
            pay(i, 0);
        }
        Console.WriteLine("===========================================================");
    }

    private void pay(int i, int flag)
    { 
        if(usertime[i, 4] == 1 && usertime[i, 2] == 0)
        {
            if(flag == 0)
            {
                Console.WriteLine($"Time for Computer #{usertime[i, 0]} has expired. User #{i} has returned Computer #{usertime[i, 0]} and paid {usertime[i, 5]*usertime[i, 1]} won.");
                this.totalCost += usertime[i, 5]*usertime[i, 1]; // 기기 금액 * 남은 기간
            }
            usertime[i, 4] = 0;
            if(arrUser[i-1] is Student)
            {
                ((Student)arrUser[i-1]).setRent();
                ((NoteBook)arrComp[usertime[i,0] -1]).get_isAvail("N");
            }
            if(arrUser[i-1] is Worker)
            {
                ((Worker)arrUser[i-1]).setRent();
                ((NetBook)arrComp[usertime[i,0] -1]).get_isAvail("N");
            }
            if(arrUser[i-1] is Gamer)
            {
                ((Gamer)arrUser[i-1]).setRent();
                ((DeskTop)arrComp[usertime[i,0] -1]).get_isAvail("N");
            }
            
        }
        else if(usertime[i, 4] == 1 && usertime[i, 2] != 0 && flag != 0)
        {
            Console.WriteLine($"User #{i} has returned Computer #{usertime[i, 0]} and paid {usertime[i, 5]*usertime[i, 3]} won.");
            this.totalCost += usertime[i, 5]*usertime[i, 3]; // 기기 금액 * 사용 기간
            usertime[i, 4] = 0;
            if(arrUser[i-1] is Student)
            {
                ((Student)arrUser[i-1]).setRent();
                ((NoteBook)arrComp[usertime[i,0] -1]).get_isAvail("N");
            }
            if(arrUser[i-1] is Worker)
            {
                ((Worker)arrUser[i-1]).setRent();
                ((NetBook)arrComp[usertime[i,0] -1]).get_isAvail("N");
            }
            if(arrUser[i-1] is Gamer)
            {
                ((Gamer)arrUser[i-1]).setRent();
                ((DeskTop)arrComp[usertime[i,0] -1]).get_isAvail("N");
            }
        }
    }

    public void lendComputer(int userId, int period)
    {
        if(arrUser[userId-1] is Student)
        {
            for(int i=0; i<arrComp.Length; i++){ // 게임방에 등록된 컴퓨터 다 순회
                if(arrComp[i] is NoteBook)
                { // 그 컴퓨터가 노트북인 경우
                    int temp = ((NoteBook)arrComp[i]).get_isAvail("Y"); // 렌트가 불가능하면 0  렌트가 가능하면 노트북 id 반환
                    if(temp != -1){
                        ((Student)arrUser[userId-1]).setRent();
                        Console.WriteLine($"Computer #{this.arrComp[i].comID} has been assinged to User #{userId}");
                        Console.WriteLine("===========================================================");
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
                        Console.WriteLine($"Computer #{this.arrComp[i].comID} has been assinged to User #{userId}");
                        Console.WriteLine("===========================================================");
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
                        Console.WriteLine($"Computer #{this.arrComp[i].comID} has been assinged to User #{userId}");
                        Console.WriteLine("===========================================================");
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

class Program
{
    static void Main(string[] args)
    {   
        int total = int.Parse(Console.ReadLine());
        Computer[] computers = new Computer[total];
        string machine = Console.ReadLine();
        int note = int.Parse(machine.Split('\x020')[0]);
        int desk = int.Parse(machine.Split('\x020')[1]);
        int net = int.Parse(machine.Split('\x020')[2]);
        for(int i=0; i<total; i++)
        {
            if(i < net) computers[i] = new NetBook();
            else if(i < note + net) computers[i] = new NoteBook(); 
            else if(i < desk + net + note) computers[i] = new DeskTop();
        }
        int userCount = int.Parse(Console.ReadLine());
        User[] users = new User[userCount];


        string []job = new string[userCount];
        string []name = new string[userCount];
        for(int i=0; i<userCount; i++)
        {
            string str = Console.ReadLine();
            job[i] = str.Split('\x020')[0]; 
            name[i] = str.Split('\x020')[1]; 
            if(job[i] == "Student") users[i] = new Student(name[i], job[i]);
            else if(job[i] == "Worker") users[i] = new Worker(name[i], job[i]);
            else if(job[i] == "Gamer") users[i] = new Gamer(name[i], job[i]);
        }
        ComputerManager manager = new ComputerManager(users, computers);
        using (StreamWriter writer = new StreamWriter("output.txt"))
        while(true)
        {
            string item = Console.ReadLine();
            if(item.Equals("Q")) break;
            else if(item[0] == 'A')
            {
                int str1 = int.Parse(item.Split('\x020')[1]);
                int str2 = int.Parse(item.Split('\x020')[2]);
                manager.lendComputer(str1, str2);                
            }
            else if(item[0] == 'R')
            {
                int day = int.Parse(item.Split('\x020')[1]);
                manager.return_Computer(day);
            }
            else if(item.Equals("T")) manager.time_Lend();
            else if(item.Equals("S")) manager.get_ComList();
        }
    }
}

/*
6
2 1 3
4
Student Kim
Gamer Lee
Worker Choi
Student Park

*/