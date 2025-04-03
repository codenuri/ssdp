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

// std::list 로 부터 상속받아서 "방문자패턴기능" 추가
template<typename T>
class MyList : public std::list<T>
{
public:
	void accept(IVisitor<T>* v) override
	{
		// 자신의 모든 요소를 방문자에 보내면 됩니다
		for (auto& e : *this)
			v->visit(e);
	}
};



int main()
{
	std::list<int> s = { 1,2,3,4,5,6,7,8,9,10 };

	TwiceVisitor<int> tv;
	s.accept(&tv);			

//	ShowVisitor<int> sv;	
//	s.accept(&sv);


}





