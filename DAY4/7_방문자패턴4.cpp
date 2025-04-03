#include <iostream>
#include <list>
#include <vector>

// 전통적인 디자인 패턴에서는 "방문자3.cpp" 처럼
// IVisitor 인터페이스를 만들게 됩니다.

// 이번에는 요즘 스타일로 변경해 봅시다.



template<typename T>
class MyList : public std::list<T>
{
public:
	using std::list<T>::list;   

	// 다양한 방문자를 받기 위해서 인터페이스가 아닌 template 으로
	template<typename V>
	void accept( V v )
	{
		for (auto& e : *this)
			v(e); // v 는 함수 처럼()로 호출가능해야 한다.
	}
};

int main()
{
	MyList<int> s = { 1,2,3,4,5,6,7,8,9,10 };

	s.accept( [](int& e) { e *= 2; } );

	s.accept([](int e) { std::cout << e << std::endl; });
	

	// 위 코드가 자바에 있습니다.
	// => 자바에서는 accept 가 아니고 forEach 입니다.
//	s.forEach( 람다 표현식 )
}





