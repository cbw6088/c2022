## <strong>Dart 문법</strong>
### <strong>출력</strong>
- print(변수명);
- print("문자열 : $변수명"); -> %d, %c 등등 대신 $표기 사용
- print(변수명.runtimeType); -> 변수가 무슨 타입인지 출력 

### <strong>조건문</strong>
```dart
int point = 80;
if(point >= 90){ // true여야 실행
    print("A학점");
}
else if(point >= 80){
    print("B학점");
}
else{
    print("F학점");
}
```


### <strong>익명함수와 람다식</strong>
- 이름이 없는 함수를 익명함수라고 함
    - 굳이 이름이 없어도 실행이 가능한 함수
- 한 줄만 리턴할거면 람다식 이용
- 두 줄 이상 리턴할거면 익명함수 사용

```dart
void routune(Function start){ // Function은 함수를 인자로 받음
    String result = start();
    print(result);
}

void main(){
    routine((){ // 익명함수
        return "짜파게티 먹기";
    });

    routine(()=>"신라면 멱기"); // 람다식
}
// 익명함수 -> 출력 : 짜파게티 먹기
// 람다식 -> 출력 : 신라면 먹기

void routune(Function start){ // Function은 함수를 인자로 받음
    String result = start();
    print(result);
}

void main(){
    routine(()=>"신라면 먹기"); // start()에 "신라면 먹기"가 들어가 있다고 생각
}
```
### <strong>클래스</strong>
- 클래스란?
    - 클래스는 객체를 정의하는 설계도
    - 예시 : 자전거
        - 형태 : 바퀴 2개 / 손잡이 1개 / 몸체 1개
        - 기능 : 전진 
- 객체란?
    - 클래스를 통해 현실 세계에 뿌리내릴 수 있는 것
    - 아직은 존재하지 않지만, 존재 할 가능성이 있는 것을 객체라고 칭함
    - 올바른 예시 : 사자 클래스
        - 사자 클래스를 정의하면, 사자는 사자 클래스에 존재할 수 있는 객체
    - 잘못된 예시 : 동물 클래스
        - 동물 클래서에는 무언가를 구체적으로 특정할 수 없음 (동물은 존재하는 객체가 아닌, 객체의 묶음 표현) 

```dart
/*
모든 것들이 객체로 존재 하면서 객체들 끼리 협력을 하고,
객체의 상태는 클래스 내부의 함수를 통해 변경하는 것이 객체지향 함수
*/
class Dog{
    String name = "Toto";
    int age = 18;
    String color = "White";
    int thirty = 100; // 가장 목마른 경우;

    void drinkWater(Water w){
        w.drink();
        thirty = thirty - 50;
    }
}

class Water{
    double liter = 2.0;

    void drink(){
        liter = liter - 0.5;
    }
}

void main(){
    Dog d1 = Dog();
    print(d1.name);
    print(d1.age);
    print(d1.color);
    print(d1.thirty);

    Water w = Water();
    d1.drinkWater(w);
    print("갈증 지수 : ${d1.thirty}"); // '.'이 붙으면 중괄호로 감싸기
    print("물의 양 : ${d.liter}");
}
```

### <strong>생성자와 선택적 매개변수</strong>
- 각 변수마다 다른 값을 넣고 싶을 때 사용

```dart
class Dog{
    String name;
    int age;
    String color;
    int thirty;

    Dog(this.name, this.age, this.color, this.thirty); // this에 해당하는 변수의 값이 위의 변수로 저장
}

void main(){
    Dog d1 = Dog("Toto", 13, "White", 100);
    Dog d1 = Dog("Ruby", 11, "Black", 0);
}
```
### <strong>cascade 연산자</strong>
- 첫 번째 함수를 넘기면서 .. 이후에 존재하는 함수들도 같이 실행 

```dart
// 계단 표기법 사용
class Chef{
    void cook(){
        print("요리를 시작합니다.");
    }

    void handwash(){
        print("손을 씼습니다.");
    }
}

void goCompany(Chef c){
    c.cook();
}

void main(){
    goCompany(Chef()..handwash()..cook());
}
```
### <strong>상속</strong>
- 부모가 가진 상태와 행위를 자식이 물려받는 것과 동시에 다형성이 성립해야 함
- 다형성 : 여러가지 형태를 가질 수 있는 능력
    - 엔진 -> 제네시스 : 제네시스는 엔진이라고 표현하지 못함 (다형성 X)
    - 햄버거 -> 치즈햄버거 : 치즈햄버거는 버거라고 표현 가능 (다형성 O)
- extends 혹은 ':' 명령어를 이용하여 상속
- this는 자신을 나타내고, super는 부모를 나타냄
- 부모가 존재하면 부모 먼저 실행

```dart
class Burgar{
    Burgar(this.name){
        print("버거");
    }
}

class CheeseBurgar extends Burger{ // 부모가 존재하므로 부모 먼저  실행 
    CheeseBurgar(String name) : super(name){
        super.name = name
        print("치즈 버거");
    }
}

void main(){
    CheeseBurgar cb1 = CheeseBurgar("치즈 햄버거"); // 치즈버거 클래스로 이동
    //  Burgar cb2 = CheeseBurgar(); // 다형성이기에 이러한 형태도 가능
    print(cb1.name);
}

/*
[출력] 
버거
치즈버거
치즈햄버거
*/
```

### <strong>mixin</strong>
- with 명령어를 사용하며, 상속과는 다르게 코드를 재사용하는 목적으로 사용
```dart
class Engine{
    int power = 5000;
}

class BMW with Engine{

}

void main(){
    BMW bm = BMW();
    print(bm.power);
}
```

### <strong>추상클래스</strong>
- abstract 명령어를 사용하여 클래서 구현
- implements 명령어를 사용하여 추상클래스 받기
- 부모의 함수를 무효화 시키고, 해당 함수 재정의

```dart
abstract class Animal{
    void sound();
}

class Dog implements Animal{
    void sound(){
        print("멍멍 배고파");
    }
}

class Cat implements Animal{
    void sound(){
        print("야옹 배고파");
    }
}

class Fish implements Animal{
    //override -> 부모의 함수 무효화
    void sound(){
        print("뻐끔 배고파"); // 재정의
    }
}

void main(){
    Animal d1 = Dog();
    Animal c1 = Cat();

    d1.sound();
    c1.sound();

    Animal f1 = Fish();
    f1.sound();
}
```

### <strong>컬렉션(List, Map)</strong>
- List는 배열
- Map은 특정 인덱스 칸을 만들 수 있음
- Map은 한 번 만들면 끝, 클래스는 계속해서 생성 가능

```dart
class User{
    int id = 1;
    String username = "cos";
}

void main(){
    /*List*/
    List<int> nums1 = [1, 2, 3, 4];
    var nums2 = [5, 6, 7, 8];
    print(nums1[3]);
    print(nums2[0]);

    /*Map*/
    Map<String, dynamic> user = {
        "id" : 1,
        "username" : "cos"
    };
    print(user["id"]);
    print(user["username"]);

    User u = User();
    print(u.id);
    print(u.username);
}
```

### <strong>반복문 (for, map, where)</strong>
- for문
    - 초기 변수(i)값 지정 -> 범위 지정 -> 조건 지정
- map
    - 람다식에 리턴되는 값 기입
    - 반복되는 값을 하나 씩 변형하기 위해 사용
- where
    - 람다식에 조건 기입

```dart

void main(){
    /*for*/
    var list = [1, 2, 3, 4];
    for(int i = 0; i < 5; i++){ // 0 ~ 4까지 반복
        print(list[i]);
    }

    /*map*/
    var chobab1 = ["새우초밥", "연어초밥", "광어초밥"];
    var chobabChange = chobab1.map((i) => "간장_" + i).toList(); // toList()를 사용하여 타입을 List로 고정 (자주 쓰는 방식)
    print(chobobChange);

    /*where*/
    var chobab2 = ["새우초밥", "연어초밥", "광어초밥"];
    var chobabFinder = chobab2.where((i) => i == "광어초밥").toList();
    print(chobabFinder);
}

/*
1 2 3 4

간장_새우초밥
간장_연어초밥
간장_광어초밥

광어초밥
*/
```
### <strong>스프레드 연산자</strong>
- 리스트일 경우 깊은 복사할 때 사용되며 명령어는 '...'
- 만약 리스트 안에 맵이 들어간 경우 깊은 복사를 하기 위해선 람다식 사용

```dart
void main(){
    var list1 = [1, 2, 3];
    // var newList = list -> 얕은 복사 (주소 복사)
    var newList1 = [...list1]; // -> 깊은 복사 (값 복사)

    var list2 = [{"id" : 1}, {"id" : 2}]; // list안에 맵으로 저장 
    var newList2 = list.map((i) => (...i)).toList();

    print(list);
    print(newList);
    list[0] = 10;
    print(list);
    print(newList);

    /////////////////////////////////////////////////////////////////

    var users = [
        {"id" : 1, "username" : "cos", "password" : 1234},
        {"id" : 2, "username" : "sar", "password" : 5678},
    ];

    var newUsers = users.map((i) => i["id"] == 2 ? {...i, "username" : "love"} : i).toList(); // username만 수정 나머지는 i 그대로
}

/*
1 2 3
1 2 3
10 2 3
1 2 3
*/
```
### <strong>final vs const</strong>
- final / const : 자료형 앞에 삽입하여 사용 (중간에 값을 수정할 수 없게 함)
    - 자료형 생략 가능
- final과 const의 차이점
    - final의 경우 무조건 값 초기화 후 사용
    - const의 경우 컴파일 시 초기화 되어 있어야 하고, 동일한 객체는 같은 메모리를 공유

```dart
final String name = 'nico'; // 기본 형태
name = 'niki'; // 저장된 값 변경 불가

const name = 'nico'; // 자료형 생략 가능
```

### <strong>null safety</strong>
- 컴파일 시 null에 대한 에러를 보호해준다.
- 보호를 위해 null 자체를 없앨 수는 없다.
- 그럼으로 null의 기능을 유지하면서 해당 에러에서 보호해주는게 목적이다.
- 기본적인 변수는 null이 올 수 없음.
- null이 올 수도 안 올 수도 있게 설정하기 위해선 변수 선언 시 '?'표시.

```dart
bool isEmpty(String string) => string.length == 0;

void main(){
    isEmpty(null);
}
/*해당 코드는 에러가 나옴*/
/*0과 null은 다르기 때문*/

void main(){
    String? nico = 'nico'; // null이 들어올 수 있는 변수
    nico = null;
    /*null인지 확인 방법1*/
    if (nico != null){ // nico는 null이 아님을 dart는 알고 있음
        nico.isNotEmpty;
    }
    /*null인지 확인 방법2*/
    nico?.isNotEmpty;
}
```
### <strong>late</strong>
- late는 초기 데이터 없이 변수를 선언할 수 있게 해준다.
- 또한, 실수를 막아준다.
    - 데이터를 넣지 않은 변수는 사용 불가 ex) print(name); <- name에는 값을 넣기 전이라고 가정
```dart
void main(){
    late final String name;
    /*do something, go to api*/
    name = 'nico';
}
```
