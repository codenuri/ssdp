#include <iostream>
#include <list>
#include <vector>

// 방문자의 인터페이스
template<typename T> 
struct IVisitor
{
	virtual void visit(T& e) = 0;
	virtual ~IVisitor() {}
};

// 방문자 핵심 : 요소 한개에 대한 연산을 정의 한것
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



// std::list 로 부터 상속받아서 "방문자패턴기능" 추가
template<typename T>
class MyList : public std::list<T>
{
public:
	// 생성자 상속 문법 : 기반 클래스 모든 생성자를 MyList 도
	//					사용할수 있게 해달라는 것
	using std::list<T>::list;   // std::list<T> 타입이름,
								// list 는생성자이름

	void accept(IVisitor<T>* v) 
	{
		// 자신의 모든 요소를 방문자에 보내면 됩니다
		for (auto& e : *this)
			v->visit(e);
	}
};

int main()
{
	MyList<int> s = { 1,2,3,4,5,6,7,8,9,10 };

	TwiceVisitor<int> tv;
	s.accept(&tv);			

	ShowVisitor<int> sv;	
	s.accept(&sv);


	ZeroVisitor<int> zv; // 방문하는 요소를 0으로 
	s.accept(&zv);


	s.accept(&sv); // 다시 출력
}





