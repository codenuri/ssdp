// 정리

// 객체지향 디자인 패턴의 핵심 1. 변하지 않은 코드에서 변하는 코드를 분리
// 객체지향 디자인 패턴의 핵심 2. 재귀적 포함

// A는 B를 포함하지만 A 자신도 포함할수 있다.
// => A와 B는 공통의 기반 클래스가 필요 하다.

// 왜?? 재귀적 포함을 사용하는데 ?? 의도가 뭔데 ???

// 복합객체를 만들기 위해 : Composite
// 객체에 동적인 기능추가 : Decorator 


// 객체지향 디자인 패턴의 핵심 3. 간접층의 도입
// => 다양한 문제를 해결하기 위해 간접층을 도입하는 것
// => 왜??? 간접층을 도입하는데??? 의도가 뭔데... 에 따라 패턴의 이름이 다름


// 사용자 ================= stack =================> list
//											=> 인터페이스 변경을 위한 간접층
//											=> "Adapter 패턴"
// 
// 사용자 ================= TCPServer =============> IPAddress, Socket...
//											=> "사용하기 쉽게하기 위한 포괄적 개념의 인터페이스"
//											=> "facade"
// 
// 사용자 ================= MP3 ===================> IMP3
//											=> "구현과 추상(사용자가 사용하는 클래스)의
//											=> 상호 독립적 "update"
//											=> "bridge"
// 
// 사용자 ================= CalcProxy =============> Calc Server
//											=> 다양한 용도의 "범용적"인 대행자
//											=> "proxy"








