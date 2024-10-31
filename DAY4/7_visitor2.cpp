#include <iostream>
#include <list>
#include <vector>

// 방문자 : 요소 한개에 대한 연산을 정의하는 객체
class TwiceVisitor
{
public:
	void visit(int& e) { e *= 2; }
};

int main()
{
	std::list<int> s = { 1,2,3,4,5,6,7,8,9,10 };

	// 방문자를 사용하는 코드
	TwiceVisitor tv;
	s.accept(&tv);
}





