// 변하는 것을 분리하는 2가지 기술

// 변하는 것을 가상함수로
// => template method - 도형편집기 draw/imp, 
//						GUI 예제 event 처리 - lbutton_down
// => factory method : 변하는 가상함수가 하는일이 객체의 종류 결정.
//		               즉, 객체를 생성하기 위한 가상함수. 
//						Dialog, WinDialog

// 변하는 것을 다른 클래스로
// => strategy : 알고리즘의 교체 Edit/IValidator
// => state    : 객체의 상태에 따라, 모든 동작(멤버함수) 전체를 교체
// => builder : 복잡한 객체 생성시, 만드는 방법(공정)은 동일한데
//				각 공정의 결과(모자, 유니폼, 신발의 모양)가 다를때

// GoF 패턴 23개는 용도에 따라 3가지로 구분됩니다.

// 생성 패턴 ( 5개 ) - 객체를 만들기 위해 사용하는 패턴
// => singleton
// => prototype
// => abstract factory
// => factory method
// => builder

// 구조 패턴 ( 7개)
// 재귀적 포함 기술 : composite, decorator
// 간접층 기술 : adapter, facade, bridge, proxy
// 속성이 동일하면 공유 : flyweight

// 행위 패턴 (11개)

// 변하는 것 분리 : template method, strategy

// 동일한 방법으로 접근     : iterator
// 동일한 방법으로 연산수행 : visitor

// 객체의 상태 변화를 여러곳에 알리기 : observer
// 발생된 문제를 고리에 따라 전달     : chain of responsibility

// 명령을 캡슐화 해서 undo/redo 를 가능하게 : command




