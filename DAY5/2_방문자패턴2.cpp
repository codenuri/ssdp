#include <iostream>
#include <list>
#include <vector>

// 방문자의 인터페이스
// => 방문자는 한개의 요소를 방문에게 됩니다.
template<typename T> struct IVisitor
{
	virtual void visit(T& value) = 0;
	virtual ~IVisitor() {}
};

// 방문의 대상(list)이 인터페이스
template<typename T> struct IAcceptor
{
	virtual void Accept(IVisitor<T>* visitor) = 0;
	virtual ~IAcceptor() {}
};

//-------------------------------------------------------
// 방문자 객체의 핵심 
// => 방문하는 요소 한개에 대한 연산을 정의하는 클래스
// => "방문 하는 요소" ==> "전달 받은 인자" 입니다.

// 요소를 2배로 하는 방문자
template<typename T> class TwiceVisitor : public IVisitor<T>
{
public:
	virtual void visit(T& value) { value = value * 2; }
};

//==========================
// STL list 는 방문자 패턴을 사용하지 않습니다.
// std::list 를 상속 받아서 방문자 패턴을 적용해 봅시다.

template<typename T> 
class MyList : public std::list<T>, public IAcceptor<T>
{
public:
	using std::list<T>::list; // 생성자 상속


	// list 에 방문자가 도착했을때 해야 할일을 아래 함수에서 구현
	virtual void Accept(IVisitor<T>* visitor)
	{
		for (auto& e : *this) // *this 는 현재 "list" 입니다.
			visitor->visit(e);
	}
};





template<typename T> class ShowVisitor : public IVisitor<T>
{
public:
	virtual void visit(T& value) { std::cout << value << std::endl; }
};

template<typename T> class ZeroVisitor : public IVisitor<T>
{
public:
	virtual void visit(T& value) { value = 0; }
};

int main()
{
	MyList<int> s = { 1,2,3,4,5,6,7,8,9,10 };

	TwiceVisitor<int> tv;	
	s.Accept(&tv);			

	ShowVisitor<int> sv;	
	s.Accept(&sv);

	ZeroVisitor<int> zv; // 모든 요소를 0으로 만드는 방문자
	s.Accept(&zv);

	s.Accept(&sv);
}





