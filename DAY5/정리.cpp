// 정리 - 교재 마지막 페이지 참고 하세요

// 생성 패턴 5개 : 
// => singleton, builder, abstract factory, factory method, prototype


// 구조 패턴 7개 :
// => 재귀적 포함을 사용하는 2개의  패턴    : composite, decorator
// => 간접층을 사용해서 문제를 해결하는 패턴 : adapter, bridge, facade, proxy
// => 속성이 동일하면 공유                 : flyweight


// 행위 패턴 11개 : 
// => 변하는 것의 분리 : template method, strategy, state
// => undo/redo       : command
// => 객체의 저장/복구 : memento
// => 열거, 방문       : iterator, visitor
// => 1:N 구조, 1의 변화를 N에 통보 : observer

// => 요청을 고리에 따라 전달            : chain of responsibility
// => M:N 의 복잡한 관계를 1:N 으로 변경 : mediator
// 
// => 컴파일러 만들때 사용하던 패턴(지금은 사용안함) : interpret

//=========================================================
// SOLID
// SRP : Single Responsibility Principle
// => 하나의 클래스는 하나의 책임만

// OCP : Open Close Principle

// LSP : Liskov Substitution Principle
// => 기반 클래스가 사용되는 자리에는 파생 클래스를 보낼수 있어야 한다.
// => 기반 클래스 기능을 파생 클래스가 제거 하지 말라(아래처럼 재정의해서 예외 발생)
void foo(std::list<int>* p) {}

class MyList : public std::list<int>
{
public:
	void push_back(int n) { throw 1; }
};
MyList s;
foo(&s); // 반드시 되어야 합니다.
//====================================
// ISP : Interface Segregation Principle
// => 인터페이스는 구체적 으로 분리되는 것이 좋다.
// 다음 중 좋은 것은 ?
struct IStream					// 1번
{
	virtual void Read() = 0;
	virtual void Write() = 0;
};

// 2번
struct IReadStream	
{
	virtual void Read() = 0;
};
struct IWriteStream
{
	virtual void Read() = 0;
};



// DIP : Dependency Inversion Principle
// => 구체에 의존하지 말고, 추상(인터페이스)에 의존해라

void useCamera(ICamera* p)  {} // good
void useCamera(HDCamera* p) {} // bad