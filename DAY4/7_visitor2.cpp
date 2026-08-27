#include <iostream>
#include <list>
#include <vector>

// visitor 패턴
// 
// 모든 방문자의 인터페이스
template<typename T> 
struct IVisitor
{
	virtual void visit(T& e) = 0;
	virtual ~IVisitor() {}
};

// 방문자 핵심 : 자신이 방문하는 "요소 한개 에 대한 연산을 정의" 하는 클래스
template<typename T>
class TwiceVisitor : public IVisitor<T>
{
public:
	void visit(T& e) { e *= 2; }
};
template<typename T>
class ShowVisitor : public IVisitor<T>
{
public:
	void visit(T& e) { std::cout << e << std::endl; }
};
template<typename T>
class ZeroVisitor : public IVisitor<T>
{
public:
	void visit(T& e) { e = 0; }
};

// 모든 방문의 대상은 accept 가 있어야 한다.
// => 인터페이스로 약속
template<typename T> struct IAcceptor
{
	virtual void accept(IVisitor<T>* visitor) = 0;
	virtual ~IAcceptor() {}
};

// 표준의 std::list 를 상속해서 방문자 패턴(accept) 를 구현해 봅시다.
template<typename T> class MyList : public std::list<T>, public IAcceptor<T>
{
public:
	using std::list<T>::list; // 생성자 상속. list 의 모든 생성자를 사용할수있게

	void accept(IVisitor<T>* visitor)
	{
		// 자신의 모든 요소를 방문자에게 전달
		for (auto& e : *this)  // *this : 현재 자신은 list 이므로 range-for 가능
		{
			visitor->visit(e);
		}
	}
};
int main()
{
	MyList<int> s = { 1,2,3,4,5,6,7,8,9,10 };
		
	// #1. accept 는 다양한 방문자를 받아야 한다.
	// => 모든 방문자의 인터페이스가 필요 하다

	TwiceVisitor<int> tv;  // 방문하는 요소를 2배로
	s.accept(&tv);	

	ZeroVisitor<int> zv;  // 방문하는 요소를 0 으로
	s.accept(&zv);


	ShowVisitor<int> sv;	// 방문하는 요소를 출력
	s.accept(&sv);

}





