# <strong>C#.Finally_Exam</strong>
## <strong>인터페이스</strong>
### <strong>인터페이스 선언</strong>
- 인터페이스는 interface키워드를 이용해서 선언
- 메소드, 이벤트, 인덱서, 프로퍼티만을 가질 수 있음
    - 메소드, 이벤트, 인덱서, 프로퍼티의 구현부는 없음
    - 접근 제한자 한정자(e.g. private)사용 불가
- 인터페이스는 인스턴스를 만들 수 없음
    - 인터페이스를 상속받는 클래스의 인스턴스를 만드는 것은 가능
```c#
/*사용 예시*/
interface 인터페이스이름
{
    반환형식 메소드이름 (매개변스_목록);
}
```

### <strong>인터페이스 사용</strong>
- 인터페이스를 상속 받는 파생 클래스
    - 인터페이스에 선언된 모든 메소드(및 프로퍼티)를 구현 해야함
    - 해당 메소드들은 public한정자로 수식
- 인터페이스는 인스턴스를 만들 수 없지만 참조는 만들 수 있음
    - 참조에 파생 클래스 객체의 위치를 저장

### <strong>인터페이스는 약속이다</strong>
- USB포트를 예시로 설명하면, PC와 주변 기기는 USB포트라는 약속을 따름
    - USB플래시 메모리를 꽂아 넣으면 저장 장치로 사용
    - 키보드나 마우스를 꽂으면 입력 장치로 사용
- 인터페이스도 소프트웨어 내에서 USB와 같은 역할 수행
    - 클래스가 따라야 하는 약속
    - 인터페이스로부터 파생될 클래스가 어떤 메소드를 구현해야 할지를 정의
- ILogger인터페이스는 파생클래스에 WriteLog() 메소드 구현을 강제
    - ConsoleLogger 파생클래스를 선언하여 WriteLog() 메소드 구현을 강제
    - 또한, ILogger를 상속 받는 새로운 클래스를 선언하여 파일에 로그출력도 가능
```c#
interface ILogger { void WriteLog(string message); }
class ConsoleLogger : ILogger
{
    public void WriteLog(string msg)
    {
        Console.WriteLine("{0} {1}", DataTime.Now.ToLocalTime(), msg);
    }
}
```

### <strong>여러 개의 인터페이스, 한꺼번에 상속하기</strong>
- 클래스는 "죽음의 다이아몬드"문제 때문에, 여러 클래스를 한꺼번에 상속할 수 없음
- 인터페이스는 내용이 아닌 외형을 상속
    - "죽음의 다이아몬드"문제 발생하지 않음

### <strong>인터페이스의 다중 상속 지원</strong>
- 클래스와 달리 인터페이스는 다중 상속이 허용
    - 인터페이스의 메소드를 자식 클래스에서 구현할 때는 반드시 public접근 제한자 명시
    - 다만, 인터페이스 명을 직접 붙이는 경우 public접근 제한자 생략 가능
    - 예를 들어, Notebook클래스에서는 Computer클래스와 IMoniter, Ikeyboard인터페이스를 모두 상속 받음
```c#
static void Main(string[] args)
{
    Notebook notebook = new Notebook();
    notebook.TurnOn();
}

class Computer { }

interface IMoniter
{
    void TurnOn();
}

interface IKeyboard{ } // 비어있는 인터페이스 정의 가능

class Notebook : Computer, IMoniter, IKeyboard
{
    public void TurnOn(); // public 접근제한자 반드시 명시

    void IMonitor.TurnOn(); // 인터페이스 명을 직접 붙이는 경우 public 생략 가능
}
```

### <strong>인터페이스와 다형성</strong>
- 인터페이스의 메서드는 가상 메서드이기 때문에 다형성의 특징이 적용
    - C# 컴파일러는 인터페이스의 메서드를 가상 메서드로 간주
    - Virtual / override예약어 사용할 필요 없음 (사용시 컴파일 에러)

### <strong>인터페이스 자체로 의미 부여</strong>
- 비어있는 인터페이스를 상속받는 것으로 의미 부여
    - 예를 들어, System.Object클래스의 ToString을 재정의한 클래스만을 구분

### <strong>인터페이스를 이용한 콜백 : Array.Sort</strong>
- Array.sort 메소드는 배열만 인자로 받으면 기본적으로 배열을 오름차순으로 정렬
- Array.sort 메소드에 IComparer 인터페이스 인자를 사용하는 경우
    - IComparer인터페이스의 Compare메소드 구현에 따라 내림차순 정렬도 가능

### <strong>인터페이스를 사용한 느슨한 결합</strong>
- 강력한 결합(tight coupling)
    - 클래스 간의 호출
    - 유연성이 떨어진다는 약점이 있음
- 느슨한 결합(loose coupling)
    - ppt 내용 부실

### <strong>인터페이스를 상속하는 인터페이스</strong>
- 기존 인터페이스에 새로운 기능을 추가한 인터페이스를 만들 때
- 인터페이스를 수정하지 않고 인터페이스를 상속하는 인터페이스를 이용하는 이유
    - 상속하려는 인터페이스가 어셈블리로만 제공되는 경우
    - 이미 인터페이스를 상속하는 클래스들이 존재하는 경우

### <strong>인터페이스의 기본 구현 메소드</strong>
- 인터페이스에 기본적인 구현체를 가지는 메소드 생성
    - 파생 클래스에서 해당 메소드를 구현하지 않아도 에러 발생하지 않음
    - 기본 구현 메소드는 인터페이스 참조로 업캐스팅 했을 때만 사용 가능

### <strong>인터페이스의 프로퍼티</strong>
- 인터페이스는 메소드 뿐만 아니라 프로퍼티와 인덱서도 가질 수 있음
    - 파생 클래스에서 프로퍼티와 인덱서를 반드시 구현해야 함
    - 인터페이스의 프로퍼티 선언은 클래스의 자동구현 프로퍼티 선언과 동일
```c#
interface IProduct
{
    string ProductName
    {
        get; set;
    }
}

class Product : IProduct
{
    private string productName;
    public string ProductName
    {
        get {return productName;}
        str {productName = value;}
    }
}
```

## <strong>추상 클래스</strong>
### <strong>추상 클래스 : 인터페이스와 클래스 사이</strong>
- 추상 클래스는 abstract 키워드를 사용하여 선언
    - 인스턴스를 가질 수 없음
    - 접근 제한자를 명시하지 않으면 private으로 선언됨
- 추상 메소드
    - abstract 키워드를 사용하여 메소드 선언
    - 파생클래스에서 override 키워드를 사용하여 반드시 구현되어야 함
    - public, protected, internal, protected internal 접근 제한자 중 하나로 수식

### <strong>추상 클래스의 프로퍼티</strong>
- 추상 프로퍼티 (Abstract Property)
    - abstract 키워드를 사용하여 선언
    - 파생 클래스에서 해당 프로퍼티를 구현하도록 강제
    - 인터페이스의 프로퍼티와 유사

## <strong>파일 입출력</strong>
### <strong>파일과 디렉터리 정보 관리</strong>
- 파일은 컴퓨터 저장 매체에 기록되는 데이터의 묶음
- 디렉토리는 파일이 위치하는 주소이고 파일을 담는 폴더라고 불림
- .NET은 System.IO 네임스페이스 안에 다음의 클래스를 제공
    - File          : 파일의 생성, 복사, 삭제, 이동, 조회를 처리하는 정적 메소드를 제공
    - FileInfo      : File 클래스와 하는 일은 동일하지만 정적 메소드 대신 인스턴스 메소드를 제공
    - Directory     : 디렉터리의 생성, 삭제, 이동, 조회를 처리하는 정적 메소드를 제공
    - DirectoryInfo : DirectoryInfo 클래스와 하는 일은 동일하지만 정적 메소드 대신 인스턴스 메소드를 제공

### <strong>주요 메소드와 프로퍼티</strong>
- File, FileInfo, Directory, DirectoryInfo 클래스가 제공하는 메소드와 프로퍼티
    - 파일 / 디렉토리의 생성, 복사, 삭제, 이동, 정보 조회 등의 기능을 수행
    -   기능              |      File        |   FileInfo     |       Directory        |   DirectoryInfo
    -   생성              |      Create()    |   Create()     |   CreateDirectioy()    |   Create()
    -   복사              |      Copy()      |   CopyTo()     |           -            |       -
    -   삭제              |      Delete()    |   Delete()     |       Delete()         |   Delete()
    -   이동              |      Move()      |   MoveTo()     |       Move()           |   MoveTo()
    -   존재 여부 확인    |      Exists()    |   Exists()     |       Exists()         |   Exists()
    -   속성 조회         |  GetAttributes() |   Attributes() |       GetAttributes()  |   Attributes()
    -   하위 디렉토리 조회|      -           |       -        |       GetDirectories() |   GetDirectories()
    -   하위 파일 조회    |      -           |       -        |       GetFiles()       |   GetFiles()

### <strong>System.IO.Stream 클래스</strong>
- 스트림(Stream)
    - 데이터가 흐르는 통로를 의미
    - 저장매체(하드디스크)와 메모리 사이의 스트림을 놓은 후 파일에 담긴 데이터를 바이트 단위로 메모리로 차례차례 옮김
    - 파일을 처음부터 끝까지 순서대로 읽고 쓰는 "순차접근" 가능
    - 또한, 곧장 원하는 주소에 위치한 데이터에 접근하는 "임의접근" 가능
- .NET 에서 제공하는 Stream 클래스
    - 추상 클래스 형태로 인스턴스를 만들기 위해 파생클래스를 이용
    - 하나의 스트림 모델로 다양한 매체나 장치들에 대한 파일 입출력을 다룰 수 있음
    - 주요 파생클래스
        - FileStream    : 디스크 파일에 데이터를 기록
        - NetwortStream : 네트워크를 통해 데이터를 주고 받도록 지원
        - BufferdStream : 데이터를 메모리 버퍼에 담았다가 일정량이 쌓일 때마다 기록

### <strong>FileStream 클래스 : 파일 쓰기</strong>
- BitConverter 클래스
    - 임의의 형식의 데이터를 byte의 배열로 변환
    - byte의 배열에 담겨있는 데이터를 다시 임의의 형식으로 변환
    - 예를 들어, long 형식의 데이터를 파일에 기록

### <strong>임의의 접근을 통한 파일 입출력</strong>
- Stream 클래스 (파생 클래스 FileStream)의 Position 프로퍼티
    - 현재 스트림의 읽는 위치 또는 쓰는 위치를 나타냄
    - WriteByte() 또는 ReadByte() 메소드를 호출하면 자동으로 Position이 1씩 증가
    - Write() 또는 Read()는 쓰거나 읽는 바이트 수만큼 Position이 증가
- 임의의 접근 (Random access) 방식
    - Seek() 메소드를 호출하거나 Position 프로퍼티에 원하는 값 대입
    - 지정한 위치로 점프해 읽기 / 쓰기를 위한 준비를 할 수 있음
```c#
Stream outStream = new FileStream("a.dat", FileMode.Create);
. . .
outStream.Seek(5, SeekOrigin.Current); // 현재 위치에서 5바이트 뒤로 이동
outStream.WriteByte(0x04);
```

### <strong>파일 입출력을 위한 using 키워드</strong>
- using 키워드는 파일이나 소켓을 비롯한 자원을 다룰 때 사용 가능
    - 코드 블록의 마지막에 Dispose() 메소드를 호출
    - Stream.Close() 메소드도 Dispose()를 호출하기 때문에 사실상 동일한 코드

### <strong>이진 데이터 처리 : BinaryWrite / BinaryReader</strong>
- FileStream 클래스는 파일처리를 위해 byte 또는 byte 배열형식으로 변환
    - .NET은 FileStream의 불편함을 해소하기 위해 도우미 클래스 제공
- BinaryWriter / BinaryReader 클래스
    - 스트림에 이진 데이터를 기록하거나 읽어 들이기 위한 기능 수행

### <strong>텍스트 파일 처리 : StreamWriter / StreamReader</strong>
- 텍스트 파일은 구조는 간단하고 활용도가 높은 파일 형식
    - ASCII 인코딩에서는 각 바이트가 문자 하나를 나타냄
    - ASCII 인코딩의 경우, 바이트 오더 문제가 없고 플랫폼에 상관 없이 생성하고 읽음
    - 생성한 파일의 내용을 편집기로 열면 사람이 바로 읽을 수 있음
- StreamWriter / StreamReader 클래스
    - 텍스트 파일을 쓰고 읽기 위한 기능을 제공
    - Stream의 파생 클래스의 인스턴스가 필요

### <strong>객체 직렬화</strong>
- 개발자가 정의한 복합 데이터형식을 쉽게 스트림에 쓰고 읽기
    - 복합 데이터형식이 가진 필드 값을 저장할 순서를 정하고,
    - 정해진 순서에 따라 저장하고 읽을 수 있도록 지원
    - [Serializable] 애트리뷰트를 클래스 선언부 앞에 붙여줌
```c#
/*직렬화하여 저장*/
Stream ws = new FileStream("a.dat", FileMode.Create);
BinartFormatter serializer = new BinaryFormatter();

MyClass obj = new MyClass(); // obj의 필드에 값 저장

serializer.Serialize(ws, obj);
ws.Close();

/*역직렬화하여 복원*/
Stream rs = new FileStream("a.dat", FileMode.Open);
BinaryFormatter deserializer = new BinaryFormatter();

MyClass obj = (MyClass)deserializer.Deserialize(rs);
rs.Close();
```

### <strong>객체 직렬화(Serialization)</strong>
- 직렬화하고 싶지 않은 필드 또는 직렬화 할 수 없는 필드 처리
    - 해당 필드를 [NonSerialized] 애트리뷰트로 수식
    - 직렬화할 때도 저장되지 않고, 역직렬화할 때도 복원되지 않음

## <strong>일반화 프로그래밍</strong>
### <strong>일반화 프로그래밍</strong>
- 클래스 또는 메소드를 정의할 때, 내부에 사용되는 데이터형식에 식별자를 지정
    - 보통 식별자로 "T"를 많이 사용
    - 식별자에 원하는 데이터 형식을 할당하여 해당 클래스 또는 메소드 사용
- 매개변수의 데이터형식이 다른 오버로딩 메소드들을 효과적으로 일반화
    - int형과 string형을 포함해 31가지의 데이터형식으로 오버로딩 메소드를 작성해야 할 수도 있음
    - 일반화 프로그래밍은 데이터형식을 일반화하여 효율적으로 메소드 정의

### <strong>일반화 메소드</strong>
- 매개변수의 데이터형식을 일반화하여 정의한 메소드
    - 메소드 이름 뒤에 꺾은 괄호 <> 안에 "T"를 넣어주면, "T"는 형식 매개변수가 됨
```c#
void CopyArray<T>(T[] source, T[] target)
{
    for (int i = 0; i < source.Length; i++)
        target[i] = source[i];
}
```

### <strong>일반화 클래스 : 두 개 이상의 형식 매개변수</strong>
- 일반화 프로그래밍에서 형식 매개변수는 두 개이상으로 사용 가능

### <strong>형식 매개변수 제약시키기 : where 키워드</strong>
- 특정 조건을 갖춘 형식에만 대응하는 형식 매개변수를 사용하도록 제약
    - 메소드 또는 클래스에 where 키워드와 함께 제약조건을 나타냄
    - ex) where 형식_매개변수 : 제약조건
    - where T : struct              -> T는 값 형식이어야 함
    - where T : class               -> T는 참조 형식이어야 함
    - where T : new()               -> T는 반드시 매개변수가 없는 생성자가 있어야 함
    - where T : 기반_클래스_이름    -> T는 명시한 기반 클래스의 파생 클래스여야 함
    - where T : 인터페이스_이름     -> T는 명시한 인터페이스를 반드시 구현해야 함. 인터페이스_이름에는 여러 개의 인터페이스 명시 가능
    - where T : U                   -> T는 또 다른 형식 매개변수 U로부터 상속 받는 클래스여야 함

## <strong>일반화 컬렉션</strong>
### <strong>일반화 컬렉션</strong>
- 이전 수업에 배운 기존 컬렉션은 object 형식을 기반
    - ArrayList, Queue, Stack . . . etc
    - 모든 데이터형식을 다룰 수 있지만, 컬렉션 요소 접근 때마다 형식변환 수행
    - object형식 기반이기 때문에 태생적인 성능 문제를 가지고 있음
- 일반화 컬렉션은 object 형식 기반 컬렉션의 성능 문제를 해결
    - 형식 매개변수를 통해 컴파일 할 때 컬렉션에 사용할 형식이 결정됨
    - List<T>, Queue<T>, Stack<T> . . . etc

## <strong>C# 코드로 WinForm 윈도우 생성</strong>
### <strong>WinForm 기반 사용자 인터페이스 (UI)</strong>
- .NET을 통한 사용자 인터페이스(UI) 생성
    - .NET 프레임워크 1.0부터 WinForm 제공
    - .NET 프레임워크 3.0부터 도입된 WPF(Windows Presentation Foundation)이용
    - WPF가 더 다양한 효과를 제공하지만, 내용이 방대하여 익히기 어려움
- 비주얼스튜디오는 WinForm UI구성을 위한 폼 디자이너 툴 제공
    - 개발자가 그림 그리듯 UI 생성 가능
    - 도구상자에서 버튼이나 콤보박스 등의 컨트롤을 끌어다 윈도우에 올려 놓음
    - 뒤로는 해당 UI에 대한 C#코드를 자동으로 생성

### <strong>Application 클래스</strong>
- Application 클래스는 크게 두 가지 역할 수행
    - 윈도우 응용 프로그램을 시작하고 종료시키는 메소드 제공
    - 윈도우 메세지를 처리
- Application.Run() 메소드
    - 응용프로그램을 시작하는 메소드
- Application.Exit() 메소드
    - 해당 응용프로그램을 종료하는 메소드
    - 응용프로그램이 갖고 있는 모든 윈도우를 닫은 뒤 Run() 메소드가 반환되도록 함
    - Run() 메소드 뒤의 코드를 실행

### <strong>Application 클래스 : 메시지 필터링</strong>
- 윈도우 기반 응용프로그램은 이벤트 기반 방식으로 동작
    - 마우스 클릭, 키보드 입력과 같이 갑자기 발생하는 사건(이벤트)에 반응하여 코드 실행
    - 마우스, 키보드를 제어하면 인터럽트가 발생하고, 윈도우 OS가 인터럽트를 바탕으로 윈도우 메세지를 생선한 뒤 이벤트를 받아야하는 응용 프로그램에 전달
- Application 클래스는 관심있는 메세지만 걸러낼 수 있는 메세지 필터링 기능 수행
    - 예를 들어, "Alt + F4" 키를 입력하여 응용프로그램을 종료하는 메세지를 걸러낼 수 있음
    - 윈도우 메세지는 식별 번호(ID)가 붙여져 있음
    - 특정 ID의 메세지를 걸러내는 필터를 등록할 수 있음
- Application.AddMessageFilter() 메소드는 응용프로그램에 메세지 필터 설치
    - IMessageFilter 인터페이스를 구현하는 파생 클래스의 인스턴스를 인수로 받음
    ```c#
    public interface IMessageFilter
    {
        bool PreFilterMessage(ref Message m);
    }
    ```

### <strong>윈도우를 표현하는 Form클래스</strong>
- Form(과 컨트롤)에 정의된 이벤트와 이벤트 처리기 연결하기
- Form의 프로퍼티를 조절하여 윈도우 모양 바꾸기
- Form 위에 컨트롤 올리기
- [메세지 발생] -> [메세지 필터] -> [이벤트 발생] -> [이벤트 처리기]

### <strong>Form에 정의된 이벤트와 이벤트 처리기 연결</strong>
- Form 클래스는 운영체제가 보내는 메세지 중 일부에 대해 이벤트를 구현
    - 예를 들어, 윈도우 위에서 마우스 왼쪽 버튼을 클릭하면 WM_LBUTTONDOWN 메세지가 Form객체에 전달
    - Form 객체는 이에 대해 MouseDown 이벤트를 발생
    - 미리 정의된 이벤트에 이벤트 처리기 메소드를 선언하여 등록 필요

### <strong>Form에 정의된 이벤트와 이벤트 처리기 연결</strong>
- MouseDown 이벤트의 선언
    - public event MouseEventHandler MouseDown;
- MouseEventHandler는 대리자 (이벤트는 대리자를 기반으로 선언)
    - public delegate void MouseEventHandler(object ? sender, MouseEventArgs e);
    - sender            : 이벤트가 발생한 객체 (예 : Form또는 Button객체 자신)
    - MouseEventArgs    : 아래의 프로퍼티를 제공하여 마우스 이벤트의 상세정보 제공
        - Buttom    : 마우스의 어떤 버튼에서 이벤트가 발생했는지 나타냄
        - Clicks    : 마우스의 버튼을 클릭한 횟수
        - Delta     : 마우스 휠의 회전 방향과 회전한 거리
        - X         : 마우스 이벤트가 발생한 폼 또는 컨트롤상의 x좌표
        - Y         : 마우스 이벤트가 발생한 폼 또는 컨트롤상의 y좌표

### <strong>Form 위에 컨트롤 올리기</strong>
- 컨트롤이란?
    - 윈도우 OS가 제공하는 사용자 인터페이스 요소
    - 메뉴, 콤보박스, 리스트뷰, 버튼 텍스트박스 등
- 컨트롤을 폼 위에 올리기 위한 구현 과정
    - 컨트롤의 인스턴스 생성
    - 컨트롤의 프로퍼티에 값 지정
    - 컨트롤의 이벤트에 이벤트 처리기 등록
    - 폼에 컨트롤 추가

## <strong>폼 디자이너를 이용한 WinForm UI 구성</strong>
### <strong>폼 디자이너를 이용한 WinForm UI 구성</strong>
- 폼디자이너
    - 비주얼스튜디오 IDE 일부
    - 컨트롤을 폼 위에 배치하고 프로퍼티를 변경하는 것을 마우스 클릭으로 수행
    - 폼디자이너 사용을 위해 새 프로젝트를 "Windows Form 응용 프로그램" 템플릿으로 선택
- 도구상자와 폼디자이너를 이용해 UI를 구성하는 방법
    - 도구상자에서 컨트롤을 마우스로 끌어서 폼디자이너에 올려 놓음
    - 폼 위에 올려진 컨트롤의 위치 및 크기, 프로퍼티를 수정

### <strong>Buttom, Form, Dialog</strong>
- "GroupBox" 컨트롤을 먼저 배치 후, 버튼 컨트롤 배치
    - 버튼을 클릭했을 때 Modal 창, Modaless 창, MessageBox를 띄움
    - Modal 창      : 창을 띄우고 창을 닫을 때 까지 다른 UI 사용 불가
    - Modaless 창   : 창을 띄우고 창을 닫을 때 까지 다른 UI 사용 가능

## <strong>예외 처리</strong>
### <strong>예외(Exception)</strong>
- 개발자가 생각하는 시나리오에서 벗어나는 사건을 예외라고 함
    - 예를 들어, 배열의 범위 밖의 배열의 요소를 접근하려고 시도
- 예제코드 for문에서 배열 범위 밖의 요소 접근 시, 예외 메세지를 출력하고 프로그램 종료
    - 배열 객체는 예외에 대한 상세정보를 IndexOutofRangeException 객체에 담은 후 Main()메소드에 던짐
    - Main() 메소드는 예외를 CLR에 던짐
    - CLR까지 전달된 예외는 "처리되지 않은 예외"가 되고, 예외 관련 메세지 출력 후 강제 종료
```c#
static void Main(string[] agrs)
{
    int[] arr = {1, 2, 3};

    for(int i = 0; i < 5; i++)
    {
        Console.WriteLine(arr[i]);
    }
    Console.WriteLine("종료"); // 실행 x
}
```

### <strong>예외 처리 (Exception Handling)</strong>
- 예외가 프로그램의 오류 또는 다운으로 이어지지 않도록 적절하게 처리
    - 기본 에러 처리와 고급 에러 처리로 나눌 수 있음
- 기본 예외 처리
    - 예외가 발생하지 않게 사전에 해결

### <strong>고급 에러 처리 : try ~ catch로 예외 받기</strong>
- C#에서 예외를 받을 때 try ~ catch문을 이용
    - 이전 슬라이드 예제에서 배열이 IndexOutRangeException 예외를 던졌을 때, Main()메소드는 try ~ catch 문으로 예외를 받을 수 있음
- 실행코드를 try블록에 작성하고, try블록에서 던지는 예외는 catch 블록에서 받음
    - catch문은 try블록에서 던지는 예외 객체외 형식이 일치해야 받을 수 있음
    - 모든 catch문에서 예외를 받지 못하면 "처리되지 않은 예외"로 남게 됨
```c#
try
{
    // 실행하고자 하는 코드
}
catch(예외_객체)
{
    // 예외가 발생했을 때의 처리
}
```

### <strong>Systen.Exception 클래스</strong>
- C#에서 모든 예외 클래스는 System.Exception클래스를 상속 받음
    - IndexOutRangeException 예외도 System.Exception으로 부터 파생
    - 관례상으로는 응용 프로그램 개발자를 정의하는 예외는 ApplicationException 타입을 상속하고, CLR에서 미리 정의된 예외는 SystemException타입을 상속
    - 하지만, 최근 닷넷 가이드라인 문서는 응용프로그램 개발자가 만드는 예외를 System.Exception에서 직접 상속 받도록 권장
- 상속관계로 인해 모든 예외 클래스는 System.Exception형식으로 변환 가능
    - System.Exception형식의 예외를 받는 catch절 하나면 모든 예외를 받을 수 있음
- 하나의 System.Exception타입 사용 시, 코드를 면밀히 검토 필요
    - 처리하지 않아야 할 예외까지 처리하는 일 없도록 주의

### <strong>System.Exception 클래스의 주요 멤버</strong>
- Message(프로퍼티)     : 예외를 설명하는 메세지 반환
- Source(프로퍼티)      : 예외를 발생시킨 응용 프로그램의 이름을 반환
- StackTrace(프로퍼티)  : 예외가 발생된 메서드의 호출 스택을 반환
- ToString(메서드)      : Message, StackTrace 내용을 포함하는 문자열 반환

### <strong>예외 던지기 : throw문</strong>
- 예외 객체는 throw문을 통해 던지고 던저진 예외는 try ~ catch문을 통해 받을 수 있음
```c#
static void Main(string[] args)
{
    try
    {
        throw new Exception("예외를 던집니다.");
    }
    catch(Exception e) // throw문을 통해 던져진 예외 객체는 catch문을 통해 받음
    {
        Console.WriteLine(e.Message);
    }
}
```

### <strong>고급 에러 처리 : try ~ catch 와 finally</strong>
- try 블록 코드 실행 중 에러가 던져지면 catch절로 바로 뛰어넘어 옴
    - 만약 try블록의 자원 해제 같은 중요한 코드를 미처 실행하지 못한다면 문제가 됨
- try ~ catch문의 마지막에 연결해서 사용하는 finally절
- try절 안에 return문이나 throw문이 사용되어도 finally절은 반드시 실행
    - 단, finally절 안에 return문 사용은 컴파일 에러 발생
- finally절이 없는 경우 try와 catch블록 모두 파일을 닫는 코드 포함하여 처리
- finally절이 있는 경우 finally절에만 파일을 닫는 코드 포함하여 처리
```c#
FileStream file = null;

try
{
    file = . . . ;
    // . . . 열린 파일로 작업, 이 과정에서 예외가 발생할 수 있음
}
catch(XXXException e)
{
    // . . .
}
finally
{
    file.Close();
}
```

### <strong>사용자 정의 예외 클래스</strong>
- 개발자는 C#에서 정의 되어 있지 않은 새로운 예외 클래스를 만들 수 있음
    - 반드시 Exception클래스를 상속하는 파생 클래스
    ```c#
    class MyException : Exception
    {
        // . . .
    }
    ```
- 사용자 정의 예외 예제 프로그램
    - 8비트 정수를 매개변수로 입력 받아 32비트 정수 안에 병합하는 MergeARGB()메소드 구현
    - 매개변수 입력 값이 0 ~ 255 사이이고, 이 범위를 벗어나면 InvalidArgumentException예외 발생

### <strong>예외 처리 사용</strong>
- try ~ catch문을 이용한 예외 처리 효과
    - 예외를 종류별로 정리하여 코드의 가독성이 향상
    - try문에서 발생할 수 있는 다수의 예외 상황을 하나의 catch문에서 처리 가능
    - StackTrace 프로퍼티를 통해 예외 발생 위치추적 용이
- try ~ catch문을 통한 예외 처리의 단점
    - 기본 예외처리보다 예외 발생 시 처리 시간이 오래 걸림

## <strong>대리자</strong>
### <strong>대리자(delegate)</strong>
- 대리자는 메서드에 대한 참조
    - 참고로 "참조"라는 용어는 객체의 주소를 가리키는 것을 의미
    - 대리자에 메소드의 주소를 할당한 후 대리자를 호출하면 이 대리자가 메소드를 호출
- 대리자는 delegate 키워드를 이용해서 선언
    - 클래스를 선언하는 위치와 같은 위치라면 어디든 선언할 수 있음
- 사용 형식 : 한정자 delegate 반환_형식 대리자_이름(매개변수_목록);
    - 예시) delegate int MyDelegate(int a, int b);

### <strong>형식(type)으로의 대리자</strong>
- 대리자는 인스턴스가 아닌 데이터 평식(type)
    - 메소드를 참조하기 위해 대리자의 인스턴스를 생성하여 사용
    - 대리자의 인스턴스는 메소드를 참조

### <strong>대리자 인스턴스 생성부터 호출까지</strong>
- Callback라는 반환 형식이 int, 매개변수가 (int, int)인 MyDelegate대리자 인스턴스가 있다고 가정
- MyDelegate() 생성자를 호출해서 Callback 인스턴스 생성
- 생성자의 인수로 Plus() 또는 Minus()를 사용하여 Callback이 해당 메서드를 참조하게 만듦
- 메서드를 호출하듯이 Callback을 사용하면 현재 참조하는 메소드를 실행하여 결과를 반환

### <strong>대리자의 활용</strong>
- 대리자는 메소드를 매개변수로 넘기기 위해 사용
    - 예를 들어, 배열을 정렬하는 메소드에서 비교 메소드를 매개변수로 받는 경우
    - 매개변수로 전달받은 비교 메소드에 따라 오름차순 정렬인지 내림차순 정렬인지 결정됨
- 대리자를 사용해 비교 메소드를 매개변수로 받는 버블정렬 메소드 작성

### <strong>일반화 대리자</strong>
- 대리자는 일반화 메소드도 참조 가능
    - 대리자도 형식 매개변수를 이용하여 선언 (일반화 대리자)

## <strong>대리자 체인</strong>
### <strong>대리자 인스턴스의 메소드 참조</strong>
- C# 2.0부터는 대리자 인스턴스에 메소드를 쉽게 연결하도록 지원
    - 기존에는  new연산자를 사용하고 생성자의 인수로 메소드 이름을 입력
    - C# 2.0부터는 '=' 연산자를 사용해 대리자 인스턴스에 메소드를 직접 대입 가능

### <strong>대리자 체인</strong>
- 대리자 하나가 여러 개의 메소드를 동시에 참조
    - '+='연산자를 이용하여 대리자 인스턴스에 여러 메소드를 결합 가능
    - '+='연산자가 아니어도 다음의 방법들로 대리자 체인 생성 가능
    ```c#
    ThereIsAFire Fire = new ThereIsAFire(Call119)
        + new ThereIsAFire(ShotOut)
        + new ThereIsAFire(Escape);

    ThereIsAFire Fire = (ThereIsAFie)Delegate.Combine(
        new ThereIsAFire(Call119),
        new ThereIsAFire(ShotOut),
        new ThereIsAFire(Escape)),
    )
    ```
    - 대리자 체인에서 특정 대리자를 끊어낼 때는 '-='연산자를 이용
    ```c#
    ThereIsAFire Fire = new ThereIsAFire(Call119)
        + new ThereIsAFire(ShoutOut)
        + new ThereIsAFire(Escape);

    Fire -= new ThereIsAFire(ShotOut);
    Fire -= Escape;
    Fire("우리집"); // Call119만 출력 : 소방서죠? 불 났어요! 주소는 우리집
    ```

### <strong>익명 메소드</strong>
- 이름이 없는 메소드
    - delegate 키워드를 사용해 선언하고 대리자 인스턴스에 연결 가능
    - 익명 메소드는 자신을 참조할 대리자와 동일한 반환 / 매개변수 형식 사용

### <strong>이벤트</strong>
- WinForm에서 버튼 클릭, 콤보 박스에서 값 선택 등 발생한 사건을 알리는 것을 의미
- 이벤트는 대리자를 event 한정자로 수식해서 생성

### <strong>대리자와 이벤트</strong>
- 이벤트는 단지 대리자를 event 키워드로 수식해서 선언한 것을 의미
- 대리자와 다른 이벤트의 특징
    - 이벤트가 선언된 클래스 밖에서 직접 이벤트 호출 불가 (컴파일 에러 발생)
    - 단, 클래스 밖에서 해당 이벤트에 이벤트 핸들러 등록 또는 해지 가능

### <strong>.NET에서 지원하는 이벤트 처리</strong>
- .NET에서 이미 정의된 이벤트 대리자 EventHandler를 사용하여 이벤트 생성 가능
    - 클래스에서 EventHandler를 이용해 이벤트 선언
    - 클래스 외부에서 자유롭게 이벤트를 처리하기 위한 메서드 등록 및 해지 가능
    - 주의 할 점은 이벤트 발생은 오직 이벤트가 선언된 클래스 내부에서만 가능
    - 이벤트 대리자 EventHandler의 첫 번째 매개변수는 이벤트를 발생시킨 타입의 인스턴스
    - 두 번째 매개변수는 .NET에서 이미 정의된 System.EventArgs타입의 이벤트에 속한 값

## <strong>람다식 소개</strong>
### <strong>람다식 (Lambda Expression)</strong>
- 람다식은 람다 계산법이라는 수학 이론에 사용하는 식
- 수학 이론에 그치지 않고 프로그래밍 언어에 도입
- 람다식은 익명 메소드를 만들기 위해 사용
    - 람다식으로 만드는 익명 메소드는 무명함수(Anonymous Function)이라 부름
    - 람다식 선언은 입력 연산자 '=>' 를 중심으로 왼편은 매개변수, 오른편은 식이 위치
    - 사용 형식 : (매개변수_목록) => 식
    ```c#
    delegate int Calculate(int a, int b); // 익명 메소드를 만들려면 대리자가 반드시 필요

    static void Main(string[] args)
    {
        Calculate cale = (int a, int b) => a + b; // 두 매개변수의 합을 반환하는 익명메소드를 람다식으로 구현
    }
    ```

### <strong>형식 유추(Type Inference)</strong>
- 대리자 선언 코드로부터 람다식이 만드는 익명 메소드의 매개변수의 형식을 유추
    - 람다식을 작성할 때 매개변수 형식을 제거하여 간편하게 나타낼 수 있음
    - 예시) Calculate cale = (a, b) => a + b;

### <strong>문 형식의 람다식</strong>
- '=>' 연산자의 오른편에 식 대신에 if조건문과 같은 문장을 사용
    - '=>' 연산자의 오른편에 식 대신 '{' 와 '}' 로 둘러쌓인 코드 블록이 위치
    - 반환 형식이 없는 무명 함수도 만들 수 있음
    ```c#
    delegate void DoSomething();

    static void Main(stirng[] args)
    {
        DoSomething Dolt = () => // 매개변수가 없는 경우
        {
            Console.WriteLone("출력1");
            Console.WriteLone("출력2");
            Console.WriteLone("출력2");
        }; // 문장 형식의 람다식은 '{' 와 '}' 로 둘러쌈
        Dolt();
    }
    ```

### <strong>무명함수를 위한 전용 대리자 : Func와 Action</strong>
- 무명함수를 만들기 위해 매번 대리자를 선언해야 하는 번거로움이 있음
- .NET은 Func와 Action 대리자를 미리 정의하여 이 번거로움에 관한 문제 해결
- Func 대리자
    - 결과를 반환하는 익명 메소드 또는 무명 함수를 참조
    - 입력 매개변수가 없는 것 부터 16개에 이르는 것 까지 버전이 다양
    - 예시) public delegate TResult Func<in T, out TResult>(T arg); // 입력 매개변수 한 개 (여러 개 입력 가능)
    - in    -> 메소드 안에서 읽기 가능 -> 메소드 안에서 쓰기 불가능
    - out   -> 메소드 안에서 읽기 가능 -> 메소드 안에서 쓰기 필수
- Action 대리자
    - 결과를 반환하지 않는 익명 메소드 또는 무명 함수를 참조
    - 입력 매개변수가 없는 것부터 16개에 이르는 것 까지 버전이 다양
    - 예시) public delegate void Action<in T>(T arg); // 입력 매개변수 한 개 (여러 개 입력 가능)
- 매개변수가 없는 버전, Action<>의 사용 예
```c#
Action act1 = () => Console.WriteLine("Action()");
atr1();
```

### <strong>식으로 이루어지는 멤버</strong>
- 메소드, 속성, 인덱서, 생성자, 종료자 멤버의 본문을 식(Expression)로만 구현 가능
    - "식 본문 멤버(Expression - Bodied Member)" 라고 부름
    - 사용 형식 : 멤버 => 식;

## <strong>LINQ의 개념</strong>
### <strong>LINQ (Language INtegrated Query)</strong>
- C# 언어에 통합된 데이터 질의 기능
- 프로그래밍에서 많은 부분을 차지하는 데이터 작업의 효율을 크게 향상
- 데이터 질의란 데이터 집합에서 원하는 데이터를 찾는 작업
- 데이터 질의 기본 요소
    - From   : 어떤 데이터 집합에서
    - Where  : 어떤 조건으로
    - Select : 어떤 항목을
- from절
    - from<범위 변수>in<데이터 원본>의 형식으로 사용
```c#
int[] numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
var result = from n in numbers
            where n % 2 == 0
            orderby n
            select n;

foreach(int n in result)
    Console.WriteLine("짝수 : {0}", n);
// 출력 : 짝수 : 2 ~ 짝수 : 10
```
- where절
    - 찾고자 하는 데이터를 필터
    - 범위 변수가 충족해야 하는 조건을 매개변수로 입력
```c#
Profile[] arrProfile =
{
    new Profile() {Name = "정우성", Height = 186},
    new Profile() {Name = "김태희", Height = 158},
    new Profile() {Name = "고현정", Height = 172},
    new Profile() {Name = "이문세", Height = 178},
};

var profiles = from profile in arrProfile
                where profile.Height < 175
                select profile;
```
- orderb절
    - 필터링된 데이터를 정렬
    - ascending(오름차순) / descending(내림차순) 선택 가능
        - 아무것도 선택하지 않으면 ascending 기본 적용
```c#
var profiles=  from profile in arrProfile
                where profile.Height < 175
                orderby profile.Height descending // 공백 혹은 ascending 가능
                select profile;
```
- select절
    - 최종 결과를 추출하는 쿼리식의 마침표 같은 존재
    - LINQ질의 결과인 IEnumerable<T>객체의 매개 변수 T는 select문에 의해 결정
```c#
var profiles = from profile in arrProfile
                where profile.Height < 175
                orderby profile.Height
                select profile; // profilrs의 형식은 IEnumerable<Profile>, profile.Name; 로 작성 시 형식은 IEnumerable<string>
```
- group by절
    - 특정 기준으로 데이터를 분류
```c#
Profile[] arrProfile =
{
    new Profile() {Name = "정우성", Height = 186},
    new Profile() {Name = "김태희", Height = 158},
    new Profile() {Name = "고현정", Height = 172},
    new Profile() {Name = "이문세", Height = 178},
};

var listProfile = from profile in arrProfile
                group profile by profile.Height < 175 into g
                select new {GropuKey = g.Key, Profiles = g};
/*
정우성 186    김태희 158
김태희 158    고현정 172
            -> 위 < 175, 아래 >= 175
고현정 172    이문세 178
이문세 178    정우성 186
*/
```
### <strong>조인(Join)</strong>
- 두 데이터 원본을 연결하는 연산
- 각 데이터 원본에서 특정 필드가 일치하는 데이터끼리 연결
- 내부 조인 : 일종의 교집합; 두 데이터 원본 사이에 일치하는 데이터만 연결하여 반환
- 외부 조인 : 한 쪽 데이터 원본을 기준으로 삼은 상태에서 다른 데이터 원본과 결합하여 반환

### <strong>내부 조인</strong>
<img width="1218" alt="image" src="https://github.com/cbw6088/c2022/assets/99342700/ffc96131-4047-4067-a50c-db31d19d5afe">

### <strong>외부 조인</strong>
- join절을 이용해서 조인을 수행 후 그 결과를 임시 컬렉션에 저장
- DefaultIfEmpty 연산을 통해  임시 컬렉션의 비어있는 조인 결과에 빈 값 삽입
- DefaultIfEmpty 연산을 거친 임시 컬렉션에서 다시 from절을 통해 범위 변수 추출
- 범위 변수와 기준 데이터 원본에서 뽑아낸 범위 변수를 이용해서 최종 결과 추출
<img width="1217" alt="image" src="https://github.com/cbw6088/c2022/assets/99342700/c6db68a6-c672-4497-b549-6724d8ff205b">

## <strong>네트워크 프로그래밍</strong>
### <strong>인터넷</strong>
- 네트워크는 그물에서 파생된 단어로, 어떤 물건이나 사람 등이 상호 연결되어 있는 체계를 말함
- 소련의 스푸트니크 위성 발사 사건에 충격 받은 미국이 설립함 DARPA에서 지역간 연수로를 그물처럼 연결하기 시작한 것이 시초
- 1980년대 말 전 세계에 연결됨

### <strong>TCP / IP 프로토콜 (1/4)</strong>
- 프로토콜 : 네트워크에서 데이터를 주고 받기 위한 규약
- TCP / IP : Transport Control Protocol / Internet Protocol
    - 여러 가지 프로토콜의 모음(Suite)
    - 링크/ 인터넷 / 전송 / 응용 계층으로 구성
    - TCP / IP 스택(Stack)이라고 부르기도 함
### <strong>TCP / IP 프로토콜 (2/4)</strong>
<img width="794" alt="image" src="https://github.com/cbw6088/c2022/assets/99342700/7e9aac3a-f9e9-4e42-a524-1dff52c9d70e">

### <strong>TCP / IP 프로토콜 (3/4)</strong>
- TCP / IP의 주소 체계
    - 인터넷에서 사용하는 이 주소를 일컬어 IP주소(Address)라고 함
        - IPV4 : 8비트 정수 4개로 구성(즉, 32비트)되는 주소
        - 예) 211.56.101.37
- IPV6 : 128비트의 주소 체계
    - IPV4 주소가 빠르게 고갈됨에 따라 새롭게 제정된 주소 체계
    - 예) 3FFE:FFFF:7654:FEDA:1245:BA98:3210:4562
- 포트(Port)
    - IP주소가 건물 주소라면, 포트는 출입구에 해당
    - 범위 : 0 ~ 65535 정수값을 가지며
    - 알려진(Well-Known) 포트
        - HPPT : 80, HTTPS : 443, FTP : 21, Telnet : 23, SMTP : 25, IRC : 194, IIOP : 535

### <strong>TCP / IP 프로토콜 (4/4)</strong>
- 동작 방식 : 서버 / 클라이언트
<img width="455" alt="image" src="https://github.com/cbw6088/c2022/assets/99342700/806a7d39-6608-4414-988a-99a6d3ae8ba8">

### <strong>TcpListener & TcpClient 클래스 (1/4)</strong>
- TCP / IP 통신 모델에 맞추어 소켓을 Wrapping한 클래스
- TcpListener : TCP 서버.클라이언트의 연결 요청을 기다리는 역할 수행
- TcpClient 클래스
    - 서버와 클라이언트 양쪽에서 사용
    - 서버와 연결 요청 및 실제 통신 수행
    - 서버가 클라이언트의 요청을 수락하면 TcpClient의 인스턴스가 반환 됨
- TcpClient.GetStream()
    - NetworkStream 객체를 반환
    - NetworkStream은 <18 파일 다루기> 에서 설명한 Stream과 사용 방법 동일

### <strong>TcpListener & TcpClient 클래스 (2/4)</strong>
<img width="1016" alt="image" src="https://github.com/cbw6088/c2022/assets/99342700/14914a28-80d1-4b5b-bffc-9d9c07739005">

### <strong>TcpListener & TcpClient 클래스 (3/4)</strong>
- 서버 / 클라이언트 접속
<img width="880" alt="image" src="https://github.com/cbw6088/c2022/assets/99342700/ecadeb1e-e701-4ca0-bc30-a67ee764b8fd">

### <strong>TcpListener & TcpClient 클래스 (4/4)</strong>
- NetworkStream을 이용한 데이터 송수신
<img width="758" alt="image" src="https://github.com/cbw6088/c2022/assets/99342700/a0e7c24d-6218-4c0f-ba65-0e7cfecb63ec">

### <strong>TCP 버퍼 이해하기 (1/2)</strong>
- TCP는 연결 지향, 흐름 지향의 프로토콜
    - UDP는 메세지 지향 프로토콜
    - 서버와 클라이언트가 연결되어 있는 상태에서 데이터 전송
    - TCP앱은 데이터의 흐름으로부터 패킷의 경계를 구분해야 함
- TCP앱은 강에서 댐과 같은 역할을 하는 버퍼 보유
<img width="524" alt="image" src="https://github.com/cbw6088/c2022/assets/99342700/680f7855-9657-4d58-84b9-e20bfbec46be">

### <strong>TCP 버퍼 이해하기 (2/2)</strong>
<img width="947" alt="image" src="https://github.com/cbw6088/c2022/assets/99342700/90301719-8a20-4dd1-b3fe-17a6d2c52689">



