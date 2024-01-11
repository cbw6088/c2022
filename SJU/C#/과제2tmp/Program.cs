/* VisualStudioCode를 사용하여 구현 */
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Threading.Tasks;
using System.Text.RegularExpressions;

namespace 과제2;

class DeliveryVehicle
{
    /*필요한 차량 정보 배열 선언*/
    public int[] Id;
    public int[] Number;
    public int[] Address;
    public int[] Priority;

    public DeliveryVehicle(int size)
    {
        Id          = new int[size];
        Number      = new int[size];
        Address     = new int[size];
        Priority    = new int[size];
    }

    /*차량 정보 데이터 저장*/
    public void car_Info(int id, int number, int address, int priority, int totalCount)
    {
        this.Id[totalCount]       = id;
        this.Number[totalCount]   = number;
        this.Address[totalCount]  = address;
        this.Priority[totalCount] = priority;
    }   

    /*해당 정보 출력*/
    public void input_Info(int number, int id, StreamWriter writer)
    {
        writer.WriteLine($"Vehicle {number} assigned to WaitPlace #{id}.");
    }

    /*한 칸씩 정보 이동*/
    public void output_Info(int idx)
    {
        this.Id[idx]          = this.Id[idx + 1];
        this.Number[idx]      = this.Number[idx + 1];
        this.Address[idx]     = this.Address[idx + 1];
        this.Priority[idx]    = this.Priority[idx + 1];
    }

    /*상태 우선순위 대로 출력*/
    public void status_Info(int max, int id, StreamWriter writer)
    {
        int cnt = 1;
        for(int j = 0; j < max; j++)
        {
            for(int k = 0; k < max; k++)
            {
                if(this.Priority[k] == cnt && this.Id[k] == id)
                {
                    writer.WriteLine($"FNUM: {this.Number[k]} DEST: Address{this.Address[k]} PRIO: {this.Priority[k]}");
                    break;
                }
            }
            cnt++;
        }
    }
}

class DeliveryVehicleManager
{
    /*차량 정보 변수 선언*/
    public int[] carCount; // 아이디별 차량 배열
    public int totalCount = 0; // 전체 차량 수

    public DeliveryVehicleManager(int waitPlace)
    {
        carCount    = new int[waitPlace]; // 최대 장소 수 만큼 차량 배열 초기화
    }

    public void inputManager()
    {
        this.totalCount += 1; // 차량 수 증가
    }

    public void outputManager()
    {
        this.totalCount -= 1; // 차량 수 차감
    }
}

class Program
{
    static void Main(string[] args)
    {
        /*변수 지정*/
        try
        {
            string[] inputLines = File.ReadAllLines("input.txt"); // 입력 파일 읽기
            int id, number, address, priority, total, lineIndex = 0;
            int waitPlace       = int.Parse(inputLines[lineIndex++]);
            int[] idCheck       = new int[waitPlace];
            int[] idCount       = new int[waitPlace];
            string[] carID      = new string[waitPlace];
            string str;
            for(int i = 0; i < waitPlace; i++)
                idCheck[i] = i + 1;  
            DeliveryVehicle cars            = new DeliveryVehicle(100000);
            DeliveryVehicleManager carsMag  = new DeliveryVehicleManager(waitPlace);
            using (StreamWriter writer = new StreamWriter("output.txt")) // 출력 파일
            {
                while(true)
                {
                    str = inputLines[lineIndex++]; // 읽기 파일에서 순차적으로 문자열 저장
                    string[] tmpInput = str.Split(' '); // 공백 기준으로 나눠서 저장
                    if(tmpInput[0] == "ReadyIn")
                    {
                        for(int i = 1; i <= 4; i++) // 문자열에 있는 숫자 외의 문자는 모두 NULL로 변환
                            tmpInput[i] = Regex.Replace(tmpInput[i], @"[^0-9]", "");
                        /*입력한 값의 숫자만 저장*/
                        id                          = int.Parse(tmpInput[1]);
                        number                      = int.Parse(tmpInput[2]);
                        address                     = int.Parse(tmpInput[3]);
                        priority                    = int.Parse(tmpInput[4]);
                        carsMag.carCount[id - 1]    += 1;
                        total                       = carsMag.totalCount;
                        
                        /*DeliveryVehicle클래스에 있는 변수에 순차적으로 저장*/
                        cars.car_Info(id, number, address, priority, total);
                        cars.input_Info(number, id, writer);
                        carsMag.inputManager(); // 차 개수 증가
                    }
                    else if(tmpInput[0] == "Ready")
                    {
                        for(int i = 1; i <= 3; i++) // 문자열에 있는 숫자 외의 문자는 모두 NULL로 변환
                            tmpInput[i] = Regex.Replace(tmpInput[i], @"[^0-9]", "");

                        /*입력한 값의 숫자만 저장*/
                        number      = int.Parse(tmpInput[1]);
                        address     = int.Parse(tmpInput[2]);
                        priority    = int.Parse(tmpInput[3]);
                        
                        int min                   = Array.IndexOf(carsMag.carCount, carsMag.carCount.Min()); // 해당 배열의 최소값의 인덷스
                        id                        = idCheck[min]; // 최소값
                        carsMag.carCount[id - 1] += 1;
                        total                     = carsMag.totalCount;
                        /*DeliveryVehicle클래스에 있는 변수에 순차적으로 저장*/
                        cars.car_Info(id, number, address, priority, total);
                        cars.input_Info(number, id, writer);
                        carsMag.inputManager(); // 차 개수 증가
                    }
                    else if(tmpInput[0] == "Status")
                    {
                        writer.WriteLine("************************ Delivery Vehicle Info ************************");
                        writer.WriteLine($"Number of WaitPlaces: {waitPlace}"); // 총 위치 수
                        int max = cars.Priority.Max(); // 우선순위 중 가장 큰 값
                        for(int i = 0; i < waitPlace; i++)
                        {
                            writer.WriteLine($"WaitPlace #{idCheck[i]} Number Vehicles: {carsMag.carCount[i]}"); // 현재 위치, 위치 개수
                            if(carsMag.carCount[i] == 0) // 위치에 대기 차량이 없을 경우
                            {
                                writer.WriteLine("---------------------------------------------------");
                                continue;
                            }
                            cars.status_Info(max, idCheck[i], writer); // 상태 출력
                            writer.WriteLine("---------------------------------------------------");
                        }
                    }
                    else if(tmpInput[0] == "Cancel")
                    {
                        number = int.Parse(tmpInput[1]);
                        writer.WriteLine("********************** End Delivery Vehicle Info **********************");
                        writer.WriteLine($"Cancelation of Vehicle {number} completed."); // 취소할 차량 번호
                        for(int i = 0; i < carsMag.totalCount; i++)
                        {
                            if(cars.Number[i] == number) // 차량 번호인 경우
                            {
                                for(int j = i; j < carsMag.totalCount - 1; j++)
                                {
                                    cars.output_Info(j); // 차량 수 한 칸씩 이동하며 차감
                                }
                                carsMag.carCount[cars.Id[i] - 1]    -= 1; // 해당 차량 수 차감
                                carsMag.outputManager(); // 전체 차량 수 차감
                            }
                        }
                    }
                    else if(tmpInput[0] == "Deliver")
                    {
                        tmpInput[1] = Regex.Replace(tmpInput[1], @"[^0-9]", "");
                        id = int.Parse(tmpInput[1]);
                        writer.WriteLine("********************** End Delivery Vehicle Info **********************");
                        int min = cars.Priority.Max(); // 우선순위 가장 큰 값 저장
                        int prio = 0;
                        for(int i = 0; i < carsMag.totalCount; i++)
                        {
                            if(cars.Id[i] == id)
                            {
                                if(min > cars.Priority[i])
                                {
                                    min = cars.Priority[i]; // 가장 작은 값 저장
                                    prio = i; // 가장 작은 값의 인덱스 저장
                                }
                            }
                        }
                        writer.WriteLine($"Vehicle {cars.Number[prio]} used to deliver.");
                        for(int i = prio; i < carsMag.totalCount; i++)
                        {
                            cars.output_Info(i); // 차량 수 한 칸씩 이동하며 차감
                        }
                            carsMag.carCount[id - 1]   -= 1; // 해당 차량 차감
                            carsMag.outputManager(); // 전체 차량 한 칸 차감
                    }
                    else if(tmpInput[0] == "Clear")
                    {
                        tmpInput[1] = Regex.Replace(tmpInput[1], @"[^0-9]", "");
                        id = int.Parse(tmpInput[1]);
                        writer.WriteLine("********************** End Delivery Vehicle Info **********************");
                        writer.WriteLine($"WaitPlace #{id} cleared.");
                        for(int i = 0; i < carsMag.totalCount; i++)
                        {
                            if(cars.Id[i] == id) // 같은 id인 경우
                            {
                                for(int j = i; j < carsMag.totalCount; j++)
                                {
                                    cars.output_Info(j); // 한 칸 씩 이동하며 차감
                                }
                                carsMag.outputManager(); // 차량 전체 수 한 칸 차감
                                carsMag.carCount[id - 1] -= 1; // 해당 차량 한 칸 차감
                                i -= 1; // 한 칸 이동한 만큼 다시 돌아가기
                            }
                        }
                    }
                    else if(tmpInput[0] == "Quit")
                    {
                        writer.WriteLine("********************** End Delivery Vehicle Info **********************");
                        break; // 종료
                    }
                }
            }
        }
        catch(Exception ex)
        {
            Console.WriteLine(ex);
        }
    }
}

/*
3
ReadyIn W2 1000 Address1 P7
ReadyIn W2 2000 Address2 P2
ReadyIn W2 3000 Address3 P1
Status
Cancel 2000
Status
Ready 600 Address4 P5
Status
Ready 700 Address5 P4
Status
Ready 800 Address6 P1
Status
Clear W2
Status
Deliver W1
Status
Quit
*/