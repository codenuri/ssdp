#include <iostream>


template<typename T> struct Node
{
	T     data;
	Node* next;

	Node(const T& d, Node* n) : data(d), next(n) {}
};

// C++ 의 반복자 설계 원리
// 
// 모든 반복자가 지켜야 하는 규칙
// => 인터페이스로 약속하지 말고 문서로 약속하자


// 모든 컬렉션(컨테이너)가 지켜야 하는 규칙
// => 인터페이스로 약속하지 말고 문서로 약속하자



template<typename T>
class slist_iterator 
{
	Node<T>* current = nullptr;
public:
	slist_iterator(Node<T>* p = nullptr)
		: current(p) {
	}
	// 다음으로 이동/요소 접근을 "raw pointer 동작 방식" 과 동일하게 하자
	// => C++ 은 연산자 재정의가 된다.

	slist_iterator& operator++()
	{		
		current = current->next;
		return *this;
	}
	
	T& operator*() { return current->data; }
};


template<typename T> struct slist 
{
	Node<T>* head = 0;
public:
	void push_front(const T& a) { head = new Node<T>(a, head); }

	slist_iterator<T> begin()
	{
		return slist_iterator<T>(head);
	}
};

int main()
{
	slist<int> s;
	s.push_front(10);
	s.push_front(20);
	s.push_front(30);
	s.push_front(40);


	// 아래 코드가 실제 STL 과 거의 동일하게 사용하는 반복자 입니다.
	auto p = s.begin();

	std::cout << *p << std::endl; // 40
	++p;
	std::cout << *p << std::endl; // 30

}









// C++ 관점
// 문제점 #1. iterator() 함수 가 반환한 반복자는 "new" 로 생성된것
// => 사용후, 사용자가 반드시 delete 해야 한다.
// => 라이브러리가 new 했는데, 사용자가 delete 한다 ???  좋지 않다..

// 문제점 #2. C++ 에서 배열도 컨테이너 이다.
//			 배열의 모든 요소 열거는 "raw pointer 를 사용해서 ++" 로 이동한다
//		     하지만 위 코드는 next()로 이동
//			일관성이 없다

// 문제점 #3. 다음으로 이동시 사용하는 "next()" 가 가상함수 이다
//			  가상함수 호출의 오버헤드가 있다
//			  next() 는 한번만 호출하는 것이 아니라 "루프안"에 있을수 있다
//			  느리다!!



