#include <iostream>
#include <list>
#include <vector>

// 방문자 : 요소 한개에 대한 연산을 정의하는 객체
class TwiceVisitor
{
public:
	void visit(int& e) { e *= 2; }
};

// STL 은 방문자 패턴이 적용되어 있지 않습니다.
// std::list 를 확장해서 방문자 패턴을 적용해 봅시다.

template<typename T> class MyList : public std::list<T>
{
public:
	void accept(TwiceVisitor* visitor)
	{
		for (auto& e : *this)  // *this 의미를 생각해 보세요
			visitor->visit(e);
	}
};

int main()
{
	std::list<int> s = { 1,2,3,4,5,6,7,8,9,10 };

	// 방문자를 사용하는 코드
	// 의미 : "요소한개에 대한 연산의 정의" 만 컨테이너에 전달
	//	     컨테이너가 내부적으로 모든 요소를 방문자에게 전달
	TwiceVisitor tv;
	s.accept(&tv);
}





