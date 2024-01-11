# <strong>>Flutter란?</strong>
- Flutter는 고성능, 고품질의 IOS, Android 앱과 웹을 단일 코드 베이스로 개발할 수 있는 구글의 모바일 UI 프레임 워크
- 스크롤 동작, 글씨, 아이콘과 같이 플랫폼 별로 달라지는 부분들을 아울러서 서로 다른 플랫폼에서도 자연스럽게 동작하는 고성능의 앱을 개발할 수 있게 하는 것이 Flutter의 목표

### <strong>단일 코드 베이스로 개발을 할 수 있다는 것은?</strong>
- 한 번 코딩으로 IOS, Android앱을 만들 수 있다는 뜻
- 하나의 앱을 만들기 위해서 IOS와 Android를 위한 2개의 코드(Java, Swift)가 필요
- 하지만 플러터는 하나의 코드베이스로 크로스 플랫폼 개발을 가능하게 함

### <strong>UI 프레임워크란?</strong>
- UI란 User Interface의 줄임말
- 사용자와 애플리케이션이 커뮤니케이션을 할 수 있도록 도움을 주는 매개체 역할
- 그 매체의 역할을 하는 종류는 다양하게 존재
- 휴대폰 화면의 터치 이벤트, 리모콘의 버튼 이벤트 등 . . .

### <strong>프레임워크란?</strong>
- Frame(틀)과 Work(일)의 합성어
- 어떤 틀 안에서 일을 할 수 있게 도움을 주는 환경

### <strong>플러터의 특징</strong>
- 구글이 지원하는 무료 오픈소스
- 네이티브앱으로 컴파일이 가능하여 네이티브 수준의 성능을 자랑(AOT 지원 / Skia엔진 보유)
- 크로스플랫폼용 앱을 구현할 수 있도록 도움
- 플러터의 모든 것은 위젯이기 때문에 위젯에 대해서만 개념을 숙지하면 쉽게 개발 가능
- Dart라는 프로그래밍 언어 사용 (Kotlin, Swift, Java, Typescript를 알고 있으면 쉬움)
- Dart를 네이티브 코드로 컴파일하여 앱에 빌드 가능
- 앱 개발시 핫 리로드라는 특수 기능이 있는 가상 머신 (VM)을 사용
- 코드를 업데이트하고 다시 배포하지 않고도 코드를 저장하면 변경 사항을 실시간으로 확인 가능

### <strong>Dart언어의 특징</strong>
- C#, Javascript, Java 어떤 언어든 숙지가 되어 있다면 배우기 쉬움
- Type을 지원하는 언어
- Type 추론을 지원
- 단일 스레드로 비동기 방식 지원
- UI에 최적화된 언어
- 동시성을 지원하지만 완벽하게 격리됨(isolate)을 보장
- 스프레드 연산자를 지원
- 배열은 없고 컬렉션만 존재

### <strong>Skia 엔진</strong>
- 2D 그래픽 라이브러리(엔진)
- React의 경우
    - React는 CSS로 버튼을 만듦
    - Android / IOS 에서 버튼과 동일한 것을 찾아냄
    - 해당 버튼을 휴대폰에 그림
    - 이러한 것들을 브릿지(bridge)라 함
<img width="446" alt="image" src="https://user-images.githubusercontent.com/99342700/210201259-6759b2d4-531d-448f-a8eb-25f17bc7f424.png">

- Flutter의 경우
    - 버튼을 만듦
    - 자체 내장되어 있는 Skia 엔진 이라는 곳에서 바로 그리고 휴대폰에 저장 
<img width="444" alt="image" src="https://user-images.githubusercontent.com/99342700/210201364-32a087cf-88b9-4a03-a764-c17cb0a530a5.png">

### <strong>AOT와 JIT 지원</strong>
- AOT(Ahead of time) : 프로덕션 모드
    - Dart언어로 개발한 코드를 휴대폰에 빌드하기 전에 해당 핸드폰의 기계어 코드(네이티브 코드)로 사전 컴파일하여 코드를 빌드
    - 즉, 네이티브 성능을 낼 수 있음
    - Dart Code -> IOS Native Code(사전 컴파일) -> IOS
    - Dart Code -> Android Native Code(사전 컴파일) -> Android
- JIT(Just in time) : 개발 모드
    - 런타임에서 실행할 수 있는 중간언어로 변환 후 Dart의 가상머신(VM)을 통해서 중간언어를 실시간으로 번역
- 해당 기계에 맞게 번역을 하고 즉시 실행
- AOT에 비해 런타임시 실행이 느림
- 이 방식은 개발 모드에서만 사용
- 프로덕션 모드에서는 AOT를 사용
- Dart Code(코드 생성) -> Dart 가상머신이 이해할 수 있는 중간언어로 변환(컴파일) -> Dart가상머신 -> 실행(해당 휴대폰에 맞게 컴파일 및 실행)
