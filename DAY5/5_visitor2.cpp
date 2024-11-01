#include <iostream>
#include <list>
#include <vector>

// 템플릿과 람다 표현식을 사용한 방문자

template<typename T> class MyList : public std::list<T>
{
public:
	using std::list<T>::list;

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

	s.accept(foo);	// 함수로 만든 방문자

	s.accept([](int& e) { e *= 2; });	// 람다 표현식 사용
	s.accept([](int& e) { std::cout << e << ", "; });
}


