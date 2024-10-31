#include <iostream>
#include <list>
#include <vector>

// visitor3.cpp 는 전통적인 디자인 기법으로 만든 방문자 입니다.
// 방문자를 만들때
// 1. IVisitor 에서 상속되어야 하고
// 2. visit() 함수가 가상함수 이므로 오버헤드가 있습니다.


// C++ 스타일로 다시 만들어 봅시다.



template<typename T> class MyList : public std::list<T>
{
public:
	using std::list<T>::list;


	// 여러 방문자을 받기 위해 
	// 1. 인터페이스를 사용하지 말고 template 으로
	// 2. "v->visit(e)" 가 아니라 "v(e)" 즉, v는 () 로 호출가능해야 한다.
	template<typename V>
	void accept(V v)
	{
		for (auto& e : *this)
			v(e);
	}
};

void foo(int& e) { e *= 2; }

int main()
{
	MyList<int> s = { 1,2,3,4,5,6,7,8,9,10 };

//	s.accept(foo);


	s.accept( [](int& e) { e *= 2; } );
	s.accept( [](int& e) { std::cout << e << ", "; } );

}





