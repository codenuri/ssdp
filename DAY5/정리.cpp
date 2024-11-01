// 정리
// #1. 공통성과 가변성의 분리
// 1-1. 변하는 것을 가상함수로
//		=> template method ( 도형편집기 draw/draw_imp)
//		=> factory method
// 
// 1-2. 변하는 것을 다른 클래스로
//		=> strategy : 알고리즘 교체 ( Edit/IValidator )
//		=> state	: 객체 상태에 따라 모든 동작 변경 ( Character 동작)
//		=> builder  : 복잡한 객체를 만들때 사용

//		=> policy base design : 알고리즘을 변경할때 인터페이스가 아닌 템플릿 인자로?
//				std::vector<int, debug_alloc<int>> v;

//-------------------------------------------
// #2. 재귀적인 포함을 위해서 공통의 기반 클래스 만들기
// => composite : 재귀적 포함을 사용한 복합객체 만들기 ( 메뉴 예제 )
// => decorator : 재귀적 포함을 사용한 동적 기능추가 ( FileStream, ZipDecorator)

// #3. 간접층을 만들어라
// adapter : 인터페이스의 변경
// bridge  : 구현과 추상의 독립된 update
// facade  : 복잡한 절차를 단순화하는 하나의 인터페이스 제공
// proxy   : 범용적용도의 "대행자" 만들기

// #4. Undo/Redo 가 가능하게
// command : 동작의 취소
// memento : 상태의 저장

// #5. 열거, 통보, 방문

// iterator : 구조가 다른 복합객체를 동일 방식으로 열거
// 
// visitor : 복합객체에 모든 요소에 연산을 수행

// observer : 1:N 의 관계에서 1이 변하면 N 에 통보

// chain of responsibility : 문제의 해결을 "고리에 따라 다른 객체에 전달"


// 디자인 패턴은 용도에 따라 3가지로 분류 합니다.(중요하지는 않음)

// 생성 패턴 5개 - 객체를 만들때 사용
// => singleton
// => abstract factory
// => factory method
// => builder
// => prototype

// 구조 패턴 7개
// 재귀적 포함 2개 : composite, decorator
// 간접층 4개 : adapter, bridge, facade, proxy
// 객체의 공유 : flyweight

// 행위 패턴 11개
// 변하는 것 분리 : template method, strategy, state 
// 열거 방문, 통보 : iterator, visitor, observer, chain of reponsibility
// 취소, 저장 : command, memento
// 중재자     : mediator 
// 컴파일러 파서 만들때 사용했던 패턴(지금은 거의 사용안함) : interpret 