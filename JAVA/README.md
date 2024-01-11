# JAVA_Doit

### JAVA이론
1. 자바를 쓰면 왜 좋을까??
    - 객체 지향 언어이기 때문에 유지보수가 쉽고 확장성이 좋다.
    - 프로그램이 안정적이다.
    - 풍부한 기능을 제공하는 오픈 소스이다.

2. 자바 컴파일
    - java 파일명 // 컴파일 하는 방법 (해당 폴더에 들어가서 할 것)
    - 자료형 없이 변수를 사용하는 방법은 var형으로 선언. // 뒤에 값을 보고 자동으로 지정됨. (자바10부터 가능)
        - 단 한번 정해진 타입은 변경 불가.
        - 지역 변수에만 사용 가능.
    - 상수는 변하지 않는 값. // final을 붙임.
        - final int num = 0;
    - long이나 float 값으로 저장해야 하는 경우 식별자 (L,I,F,f)를 명시.
        - final float PI = 3.14f;
    - 입력 받기 
        - import java.util.Scanner; (include 같은 라이브러리)
        - Scanner kb = new Scanner(System.in); // kb(keyboard)라는 이름의 스캐너를 만든다는 뜻.
        - int input = kb.nextInt(); // 입력 받는 코드.
    - 출력
        - System.out.println(num); // 코드 출력 방법(줄바꿈 포함) ( print(num)으로 출력 할 경우 커서가 바로 뒤에옴. 줄 바꿈(x) )
```java
import java.util.Scanner; // 입력을 받는 라이브러리

//package FolderName //(폴더 안에 있으면 생략 가능)
public class FileName{
    public static void main(String[] args){ // 이 형식으로 사용
        var num = 10; // 뒤의 값을 보고 자동으로 자료형 결정.
        Scanner kb = new Scanner(System.in); // kb라는 이름의 스캐너를 만듬.
        System.out.print("Please enter an integer : "); // 줄바꿈 없이 출력. (마우스 커서가 바로 뒤로 옴)
        int input = kb.nextInt(); // 입력 받는 코드.
        if(input == num){
            System.out.print("Numbers match!");
        }
        else{
            System.out.print("Numbers do not match!");
        }
    }
}
```

3. 자바의 여러가지 연산자
    - c언어와 동일.
    - 비트 연산자. 
        - << a // 승 곱하기.
        - >> a // 승 나누기.
```java
int num = 5;
System.out.println(num<<2); // 이 경우 5 * 2 : 10
System.out.println(num<<3); // 이 경우 5 * 2 * 2 : 20
```

4. 제어 흐름 이해하기
    - if문/switch문 c언어와 동일.
    - while문/do while문/for문 c언어와 동일.

5. 배열
    - 자료형 [] 변수 // 선언 방법 ex) int [] arr = new int[10]; or int [] arr = {1,2,3,4};
    - Arr.length를 이용하면 배열의 크기를 알아낼 수 있다. // ex) for(int i=0; i<Arr.length; i++)
    - for each 방법
    ```java
    int [] arr = {10,20,30,40,50}; // 기존 방식
        for(int i=0; i<arr.length; i++){
	        int value = arr[i];
        } 
        //for each 방식
        for(int value : arr){
	        System.out.println(value);	
        }
        // value의 값은 차례대로 10, 20, 30, 40, 50의 값이 들어간다.
        // 자동 자료형 추론을 사용하자 
        // c++ -> auto 
        // java -> val
    ```

    6. 객체지향 언어 : 프로그램을 구성하는 요소는 객체이며 이것만 상호작용 하록 프로그래밍
        - 클래스 : 객체를 만들기 위한 틀 // ex) 객체 : 붕어빵 / 클래스 : 붕어빵 틀
        ```java
            public class Car{
	
            }
            public class CarEx{
	            public static void main(String [] args){
		            Car c1 = new Car(); 
                // new를 사용하여 객체를 만들어야 함
	            }
            }       
        ```

    7. 자바에 존재하는 2가지 타입
            - 기본형 타입 : 논리형, 문자형, 정수형, 실수형
            - 참조형 타입 : 기본형을 제외한 모든 타입
        ```java
        int i = 4; //기본형 타입
            String str = new String("HELLO"); //참조형 타입
        ```
        - new라는 키워드는 메모리에 올려달라는 의미이다 c에서 동적할당과 같은 개념이며 이렇게 메모리에 올라간 클래스를 **인스턴스**라고 말한다.
        - 메모리에 올라간 인스턴스를 가리키는 변수 = 참조하는 변수 = 레퍼런스하는 변수  모두 같은 말이다.
        - 인스턴스를 가지고 있는게 아니라 가리키고 있다는 의미이다. 즉, 포인터

    8. 클래스는 모두 참조형이다.
        - String의 특징
            - 특징 1. String은 예외적은 new연산자 없이도 생성이 가능하지만 약간의 차이가 있다.
            ```java
            String str1 = "HelloWorld"; // ->상수영역에있는 Hello를 가르키고 있다.
            String str2 = "HelloWorld"; // ->상수영역에있는 Hello를 가르키고 있다.
            String str3 = new String("HelloWorld"); //상수영역에 있는걸 참조하는게 아니라 새롭게 힙영역에 생성한다.

            ////////////////////// 차이점 비교 ////////////////////
            if(str1==str2) --> true 둘은 상수영역에 있는 같은 레퍼런스를 참조하고 있다 
            if(str1 == str3) --> false str1은 상수영역 str3은 힙영역에 새롭게 생성된 인스턴스이다.
            // 사람이 보기에는 같은 Hello이지만 자바는 new로 생성된 string과 그냥 생성된 string을 다르게 생각한다.
            ```
            - 특징 2. String은 다른 클래스와 다르게 한 번 생성된 클래스는 변허지 않는다.
            ```java
            // str1.을 이용하여 메서드 확인
            System.out.println(str1.substring(3)); //3번 인덱스부터 잘라져서 보여짐
            System.out.println(str1); // 내부의 값은 변하지 않음
            // 즉 수행하기 전에 새로운 스트링을 만들어서 반환한다고 생각하면 된다.
            ```

    9. 클래스의 구성요소 : 필드 // ex) 객체 : 자동차 / 필드 : 자동차의 구성요소(속성) - 차 이름, 차량번호
        ```java
            public class Car{
	            String name;
	            int number;
            }
            //자동차 클래스 생성

            public static void main(String[] args){
	            Car c1 = new Car();
	            Car c2 = new Car();
	
	            c1.name = "소방차";
	            c1.number = 1234;

	            c2.name = "구급차";
	            c2.number = 1111;
                // 자동차 객체를 생성한 후 속성 값 삽입

	            System.out.println(c1.name);
	            System.out.println(c1.number);
                // c1 객체 확인
	            System.out.println(c2.name);
	            System.out.println(c2.number);
                // c2 객체 확인
            }
            // 각각의 자동차 객체 생성 되었고, 각자 다른 값이 들어있는걸 확인할 수 있다.
        ```

    10. 객체 지향 언어 : 하나의 사물을 하나의 클래스로 설명
        - 사물 = 상태 -> 필드 (이름,차량번호)
                행동 -> 메소드 (전진,후진)
        - 메소드 = 함수와 같다 입력값 -> 결과값 (입력값 : 매개변수(인자) / 결과값 : 리턴값(반환값))
        - 메소드 = 클래스가 가지고 있는 기능 
        ```java
        public 리턴타입(ex int) 메소드 이름(매개변수){
            구현
        }
        ```

    11. 다양한 메소드 선언
        ```java
        public void method1(){ //리턴값이 없다면 void를 사용
            System.out.println("mthod1이 실행됨");
        }

        public void method2(int value){ //정수형 인자를 받음
            System.out.println(value + "method2가 실행됨");
        }

        public int method3(){
            System.out.println("method3이 실행됨");
            return 10;
        } // 리턴값을 설정했으니 리턴값을 줘야함

        public void method4(int x, int y){ //여러개의 인자를 받음
	        System.out.println(x+y + "method4가 실행됨");
        }

        public int method5(int x){ //정수형 인자를 받음
	        System.out.println(x + "method5가 실행됨");
	        return x*2;
        } // 받은 인자를 이용하여 리턴
        ```

    12. 선언한 메소드 사용
        - 위에 클래스를 생성했다고 가정하고 진행(Myclass)
        - 실행 시 선언했던 조건을 맞춰줘야 한다.
        ```java
        public static void main(String [] args){
		    Myclass myclass = new Myclass();
		    // myclass.을 이용하여 메소드 접근가능
		    myclass.method1();

		    myclass.method2(10); //정수형을 무조건 넣어줘야 한다.

		    int value = myclass.method3(); //리턴값을 받아낼 변수가 필요
		    System.out.println(value);  //받은 값 확인

		    myclass.method4(3,4); //2개의 정수값을 인자로

		    int value1 = myclass.method5(10); //정수 인자를 이용하여 리턴값 받음
		    System.out.println(value1); //확인
        }
        ```

    13. 이미 만들어진 클래스들을 이용하는 방법.
        - 자주 사용하는 String 클래스의 메소드 확인
        ```java
        public static void main(String[] args){
            String str = "Hello";
            str.length(); // 문자열의 길이를 반환해주며 공백도 하나의 문자로 인식한다.
            str.concat(" World"); // 문자열을 더해준다 -> Hello World
            /* 
            이때 str을 확인해보면 Hello World가 아닌 Hello로 나온다. 
            즉 concat을 사용하면 새롭게 생성한 String Hello World를 반환하다.
            */
            str = str.concat(" World"); // 이 처럼 사용해야 str값이 변환된다.

            str.substring(3); //3번 인덱스부터 잘라준다.
            str.substring(3,6); // 3번부터 6번까지 인덱스를 잘라준다.    
        }
        ```

    14. 변수의 사용범위 : 변수가 선언된 블록
    ```java
    public class VariableScopeExam{
    	int globalscope = 10;
	
    	public void scopeType1(int value){
	    	int localscope =20;
    		globalscope = value;
    		localscope = 40; //가능
    	}
    
    	public void scopeType2(int value){
    		globalscope = value; //가능
    		localscope = 40; //불가능
    	}
	
    	public static void main(String[] args){
    		globalscope = 100; //불가능
    		localscope = value; //불가능
    	}
    }
    ```
    
    15. 모든 클래스는 인스턴스화 하지 않은 채로 사용할 수 없다.
        - 붕어빵틀 != 붕어빵
        - static 키워드를 사용하면 인스턴스화(객체 생성) 하지 않아도 사용이 가능하다.
        ```java
        public class VariableScopeExam{
	        int globalscope = 10;
	        static int staticValue = 10;
	
        	public void scopeType1(int value){
         		int localscope =20;
        		globalscope = value; //가능
        		localscope = 40; //가능
        	}

         	public void scopeType2(int value){
        		globalscope = value; //가능
    	    	localscope = 40; //불가능
        	}
    
        	public static void main(String[] args){
        		globalscope = 100; //불가능
        		localscope = value; //불가능
        		staticValue = 20 // 가능
    
    	    	VariableScopeExam v1 =new VariableScopeExam();
    	    	VariableScopeExam v2 =new VariableScopeExam();
    	    	v1.globalscope = 100; 
    	    	v2.globalscope = 200;
    	        // 위처럼 객체를 생성해서 사용해야 하며 각각 다른객체 이므로 다른값이 들어간다.
    	    	v1.staticValue = 100;
    	    	v2.staticValue = 200;
         	    // static 필드는 값을 공유하므로 두 객체는 같은값을 가지고 있다.
        	}
        }
        ```

    16. 클래스 변수
        - static한 변수, 값을 저장할 수 있는 공간이 하나밖에 없어서 값을 공유한다.
        - 클래스 이름을 직접 사용하는 것이 가능하다.
            - 클래스이름.클래스변수명 ex) VariableScopeExam.staticValue
    
    17. JDK5에서 추가된 문법(enum)
        - 기존 사용 방식
        ```java
        public class EnumEx{
	        public static final String MALE ="MALE";
    	public static final String FEMALE ="FEMALE";
    
    	public static void main(String [] args){
    		String gender1; //MALE 과 FEMAL 둘 중 하나의 값을 넣고싶음
    		gender1 = EnumEx.MALE;
    		gender1 = EnumEx.FEMALE;
    		gender1 = "boy"; //하지만 다른 string 값이 들어와도 오류를 발생시키지 않는다.
    
    		Gender gender2;
    		gender2 = Gender.MALE;
    		gender2 = Gender.FEMALE;
    		gender2 = "boy"; //에러 
    	}
        enum Gender{
         		MALE,FEMALE; 
	        }
        }
        // 위 처럼 특정 값만 사용할 때는 열거형을 사용하면 좋다.
        ```
        - 다른 값이 들어왔을 때 오류가 생길 수 있을 때 사용하면 좋아보인다.
    
    18. 클래스 다듬기 - 생산자 : new연산자를 사용하면 반드시 생성자가 나와야 함
        - 리턴 타입이 없다.
        - 매개 변수가 없는 생성자를 기본 생성자라 하고 자동으로 만들어진다.
            - 생성자를 하나라도 만든다면 기본 생성자는 만들어지지 않는다.
        ```java
        public class Car{
	        String name;
	        int Number;
        }
        Car c1 = new Car(); 
        // car()이 부분이 생성자이다.

        // 위 처럼 아무런 생성자를 만들지 않는다면 자동으로 만들어진다.

        public Car(String n){
	        name = n;
        }

        Car c1 = new Car();  //오류
        Car c1 = new Car("소방차"); 
        // Car라는 객체가 생성되면서 매개변수를 이용하여 생성되며 기본생성자는 만들어지지 않는다.
        ```
        
    19. 객체 자신을 참조하는 this
    ```java
    public Car(String name){
	    name = name
    } //이름이 똑같기 때문에 컴파일러는 동일한 값을 가르킨다.

    public Car(String name){
	this.name = name;
    }
    // 객체 자신을 참조하는 this를 이용!!
    ```

    20. 메소드 오버로딩 : 메소드 오버로딩을 사용하면 매개변수의 수, 타입이 다른 경우에 동일한 이름의 메소드를 여러개 정의할 수 있다.
    - 정수 2개를 받아 그 합을 리턴하는 메소드
    - 정수 3개를 받아 그 합을 리턴하는 메소드
    - 문자열 2개를 받아 그 합을 리턴하는 메소드
    - 위 예시 처럼 각각 타입과 매개변수의 수가 다른 경우 사용이 가능하다.
    ```java
    public int plus(int x, int y){
	    return x+y;
    } // int 타입과 int형 매개변수 2개

    public int plus(int x, int y, int z){
	    return x+y+z;
    } // int 타입과 int형 매개변수 3개

    public String plus(String x, String y){
    	return x+y;
    } // String 타입과 String 형 매개변수 2개
    ```

    21. 생상자 오버로딩과 this - 생상자도 메소드와 마찬가지로 여러개로 생성이 가능하며 이를 생성자 오버로딩이라 한다.
    ```java
    Car c1 = new Car("소방차");
    Car c2 = new Car(); // 기본 생성자는 다른 생성자가 있으면 자동으로 생성되지 않는다.
    ```
    - 기본 생성자를 사용하고 싶다면 마찬가지로 미리 정의해둬야 한다.
    - this() : 자신의 생성자를 이용하여 초기화 가능
    - 자신이 정의해둔 생성자 조건에 맞게 선언해야 한다.
    ```java
    public car(){
	    //this.name = "이름없음"
	    //this.Number = 0;
	    this("이름없음", 0); 
        // 아래에 있는 생성자를 이용하여 초기화 가능
    } //기본 생성자 오버로딩

    public car(String name, int Number){
	    this.name = name;
	    this.Number = Number;
    } // 생성자 오버로딩
    ```

    22. 패키지 : 서로 관련이 있는 클래스 또는 인터페이스들을 묶어 놓은 묶음
        - 파일들이 많아지면 관련있는 파일끼리 묶어 하나의 폴더에 보관한다.
        - package이름은 대부분 도메인 이름을 거꾸로 적은 후 프로젝트 이름을 붙여 사용한다.
        - 패키지가 있는 클래스를 사용할 때는 improt를 이용
        - 패키지 이름은 숫자로 시작할 수 없다.
        ```java
        package 패키지명;
        // import 패키지명.*;을 이용하여 사용하여야 한다.
        public class 클래스 이름{
	        ...
        }
        ```

    23. 상속 : 부모가 가지고 있는 것을 자식이 물려받는 것
        - 노트북은 컴퓨터의 한 종류이다.
        - 침대는 가구의 한 종류이다.
        - extends 키워드를 사용
        ```java
        public class Car{
	        public void run(){
		        System.out.prinlnt("달리다");
	        }
        } //기존의 Car클래스

        public class Bus extends Car {
	        public void ppangppang(){
		        System.out.println("빵빵");
    	    }
        }

        public static void main(String [] args){
	        Bus bus = new Bus();
	        bus.run(); 
	        bus.ppangppang();
            // Bus클래스에는 run 메소드가 없지만 Car 클래스를 상속받았으므로 Car의 run메소드 사용가능.
            // 뿐만 아니라 자신의 메소드도 사용가능하다 
	        Car car = new Car();
	        car.run();
	        car.ppangppang(); //오류
            // 부모 클래스인 Car는 자신의 메소드인 run()메소드는 사용가능하지만 자식의 메소드는 사용이 불가능하다.
            // 자식은 상속받은 부모의 메소드를 모두 사용 가능하지만 부모는 자식의 메소드를 사용할 수 없다.
        }
        ```

    24. 접근제한자
        - 클래스
            - 필드
            - 메소드
        - 캡술화 : 관련된 내용을 모아서 가지고 있는 것
            - public -> 전체 허용 누구든지 가능하다.
            - protected -> 같은 패키지인 경우 접근 허용하며 다른 패키지라도 상속을 받은 경우 접근 허용
            - default접근 제한자 -> 자기 자신과 같은 패키지만 허용
            - private -> 자기 자신만 접근 가능
        - public > protected > default > private
        ```java
        public int p = 3  //-> 누구든지 접근가능
        protected int p2 = 4; // -> 같은 패키지인 경우 접근 허용하며 다른 패키지라도 상속을 받은 경우 접근 허용
        int k =2 ; // default접근 제한자 -> 자기 자신과 같은 패키지
        private int i = 1; //자기 자신만 접근 가능
        ```

    25. 추상클래스
        - 구체적이지 않은 클래스를 추상클래스라고 한다.
            - ex) '새' 라는 말을 들으면 각자 생각하는 새의 종류가 다르다. '비둘기' 라는 말을 들으면 모두 한 새의 이미지를 떠올린다.
        - 추상 클래슨느 객체가 될 수 없다.
        - abstract 키워드를 이용한다.
        - 메소드가 하나라도 추상메소드인 경우 해당 클래스도 추상클래스가 된다.
        ```java
        public abstract class Bird{
	        public abstract void sing(); //각각 새마다 울음소리가 다르다.
	        public void fly(){
		        System.out.println("날다");
	        }
        }

        public class Duck extends Bird{
	        @Override
	        public void sing(){
		        System.out.println("꽥꽥");
	        } // 추상 클래스에서 상속받은 추상메소드 sing을 구현해야 함.
        }

        public static void main(String [] args){
	        Duck duck = new Duck();
	        duck.sing();
	        duck.fly();
	
            //	Bird bird = new Bird(); // 추상클래스는 객체로 생성할 수 없다.
        }
        ```

    26. super : 부모 객체를 나타내는 키워드
        - class가 인스턴스화(객체화) 될 때 생성자가 실행되면서 객체의 초기화를 한다. 그 때 자신의 생성자만 실행이 되는 것이 아니고, 부모의 생성자부터 실행 된다.
        - super()를 사용하여 부모의 기본 생성자를 호출이 가능하다.
            - 이 때 부모의 생성자가 기본 생성자가 아닌 경우 자동으로 호출이 되지않고 사용자가 따로 정의해줘야 한다.
        ```java
        public class Car{
            /*	public Car(){
		    System.out.println("Car의 기본생성자");
	        }
            */  //기본생성자의 경우

            public Car(String name){
		        System.out.println("Car의 생성자");
	        }
        }
        // 기본생성자가 아닌경우

        public class truck extends Car{
	        public Truck(){
		        // super(); //부모의 생성자를 이야기함 직접 부르지않아도 자동으로 불러진다.
		        super("소방차"); // 부모의 기본생성자가 없는경우 생성자에 맞게 호출해줘야 한다.
		        System.out.println("Trcuk의 기본생성자");
	        }
        }

        public static void main(String [] args){
	        Truck truck  = new Truck();
            // 이때 Car의 기본생성자와 트럭의 기본생성자가 실행된다.
        }
        ```

    27. 오버라이딩
        - 부모가 가지고 있는 메소드와 똑같은 모양의 메소드를 자식이 가지고 있는 것이다. 즉, 오버라이딩이란 메소드를 재정의 하는 것이다.
        - 오버로딩 : 한 클래스 내에서 동일한 이름의 메소드를 여러개 정의 하는 것.
        - 오버라이딩 : 부모의 메소드를 재정의 하는 것
        - super 키워드를 이용하여 부모의 메소드를 사용할 수 있다.
        ```java
        public class Car{
	        public void run(){
	    	    System.out.println("Car의 run메소드");
    	    }
        }

        public class Bus extends Car{
		    public void run(){
				super.run() //부모의 메소드를 호출하고 싶을때 
				System.out.println("Bus의 run메소드");
			}
	    }

        public static void main(String [] args){
	        Bus bus = new Bus();
	        Car car = new Car();
	        bus.run();
	        car.run();
        }
        ```
    
    28. 클래스 형변환 - 부모타입으로 자식개체를 참조하게 되면 부모가 가지고 있는 메소드만 사용할 수 있다. 자식객체가 가지고 있는 메소드나 속성을 사용하고 싶다면 형변환 해야한다.
        - 부모타입으로 자식을 가리킬 수 있지만 부모가 가지고 있는 내용만 사용 가능하다.
        - 자식의 내용을 사용하고 싶으면 자식 클래스로 형변환 해야한다.
            - 큰 그릇 -> 작은 그릇(가능), 부모 -> 자식(가능)
            - 작은 그릇 -> 큰 그릇(불가능), 자식 -> 부모(불가능)
        ```java
        public class Car{
	        public void run(){
		        System.out.println("Car의 run메소드");
	        }
        }

        public class Bus extends Car{
		    public void ppangppang(){
			    System.out.println("빵빵");
		    }
        }

        public static void main(String [] args){
		    Car c = new Bus(); //부모가 자식을 가르킬 수 있지만 메소드는 사용이 불가능하다.
		    c.run(); //가능
		    //c.ppangppang(); //불가능

		    Bus bus = (Bus)c;
		    bus.run();
		    bus.ppangppang();
        }
        ```

    29. 파트 9
        
        