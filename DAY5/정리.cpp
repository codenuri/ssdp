// GoF's 패턴은 용도에 따라서 3가지 카테고리로 분류 됩니다.

// 생성 패턴 5가지
// => 객체를 만들때 사용하는 패턴

// singleton : 오직 한개만 만들게 하자.
// prototype : 견본을 먼저 만들고, 복사에 의한 생성

// abstract factory : 교체 가능한 공장!!!

// factory method : 객체를 만들기 위한 인터페이스를 정의 하고 사용하지만, 
//                  어떤 객체인지는 파생 클래스가 결정

// builder : 동일한 공정이지만 각공정의 표현이 다른 복잡한 객체 만들기.


// 구조 패턴 7 가지
// => 재귀적 포함을 사용하는 기술 2가지 : composite(File/Folder), decorator(ZipDecorator)

// => 간접층을 만드는 패턴
// adapter : 인터페이스 변경
// proxy   : 대행자를 만들자
// facade  : 사용하기 쉽게(TCPServer)
// bridge : 구현과 추상층의 독립된 update

// flyweight : 속성이 동일하면 공유할수 있게 하다.

// 행위 패턴 11가지

// 변하는 것을 가상함수로		: template method
// 변하는 것을 다른 클래스로	: strategy, state 

// 복합객체의 요소를 동일하게 열거 : iterator
// 복합객체의 요소에 동일하게 연산 : visitor

// 명령의 취소에 의한 UNDO		: command
// 객체의 상태저장에 의한 UNDO	: memento

// Table 이 변경되면 "모든 그래프에 통보" : observer
// 발생된 이벤트를 "고리에 따라 전달"     : chain of responsibility

// 객체간의 관계가 복잡하면 "중재자" 를 만들어라 : Mediator

// 컴파일러 만들때 "문법을 나타내는 클래스" 를 만들어라 : interpreter
//											(지금은 거의 사용안하는 패턴)
