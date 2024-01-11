## <strong>Dart 개념</strong>
### <strong>VS Code에서 Dart 실행하기</strong>
1. Shift + Command + p 단축키 입력
2. Dart:new project 클릭
3. Console Application 클릭
4. 폴더 생성
5. Dart 시작

### <strong>Dart의 기본 자료형</strong>
- int : 정수형
- double : 실수형
- bool : true / false
- String : 문자열
- var(타입 추론) : 넣는 값을 보고 자료형 결정 (자료형을 중간에 바꿀 수 없음)
- dynamic : 넣는 값을 보고 자료형 결정 (자료형을 중간에)

### <strong>연산자</strong>
- 산술 연산자
    - '+' : 더하기 -> print(1 + 2);
    - '-' : 빼기 -> print(1 - 2);
    - '*' : 곱하기 -> print(1 * 2);
    - '/' : 나누기 -> print(1 / 2);
    - '%' : 나머지 -> print(1 % 2);
- 비교 연산자
    - '==' : 같다
    - '!=' : 다르다
    - '<' : 우측이 크다
    - '>' : 좌측이 크다
    - '<=' : 같거나 우측이 크다
    - '>=' : 같거나 좌측이 크다
- 논리 연산자
    - '!' : 다르면 -> print(!true);
    - '&&' : 둘 다 같으면 -> print(true && false);
    - '||' : 둘 중 하나라도 같으면 -> print(true || false);
