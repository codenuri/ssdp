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









int main()
{
	std::list<int> s = { 1,2,3,4,5,6,7,8,9,10 };

	TwiceVisitor<int> tv;
	s.Accept(&tv);			

	ShowVisitor<int> sv;	
	s.Accept(&sv);


}





