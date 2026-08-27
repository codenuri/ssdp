#include <iostream>


template<typename T> struct Node
{
	T     data;
	Node* next;

	Node(const T& d, Node* n) : data(d), next(n) {}
};


// 모든 반복자가 지켜야 하는 규칙
template<typename T> struct IIterator
{
	virtual bool hasNext() = 0;
	virtual T& next() = 0;
	virtual ~IIterator() {}
};

// 모든 컬렉션(컨테이너)가 지켜야 하는 규칙
template<typename T> struct ICollection
{
	virtual IIterator<T>* iterator() = 0;
	virtual ~ICollection() {}
};
//---------------------------------
// 아래 코드가 실제 slist 의 iterator 구현 코드
template<typename T>
class slist_iterator : public IIterator<T>
{
	Node<T>* current = nullptr;
public:
	slist_iterator(Node<T>* p = nullptr)
		: current(p) {}

	// 이제 약속된 방법으로 다음으로 이동만 하면됩니다.

	T& next() override
	{
		T& tmp = current->data;
		current = current->next;
		return tmp;
	}

	bool hasNext() override
	{
		return current != nullptr;
	}
};
/*
slist_iterator<int> p(400번지);
while (p.hasNext())
{
	int n = p.next();
}
*/

//--------------------------
// 모든 컬렉션은 "iterator()" 함수가 있어야 한다
// => ICollection 인터페이스를 구현해야 한다

template<typename T> struct slist : public ICollection<T>
{
	Node<T>* head = 0;
public:
	void push_front(const T& a) { head = new Node<T>(a, head); }

	IIterator<T>* iterator()
	{
		return new slist_iterator<T>(head);
	}
};

int main()
{
	slist<int> s;
	s.push_front(10);
	s.push_front(20);
	s.push_front(30);
	s.push_front(40);

	// 아래 코드가 실제 Java 에서 iterator 사용하는 방법과 거의 동일합니다.

	auto p = s.iterator();

	while (p->hasNext())
	{
		std::cout << p->next() << std::endl;
	}
}

// 반복자(iterator) 구현 원리
// => 결국 컨테이너(컬렉션)의 1번째 요소를 가리킬수 있도록 포인터 멤버을 가진 클래스
// => 그리고 약속된 방식으로 이동하면서 요소를 반환하면 됩니다.
// => Java, C# 등은 그 약속을 인터페이스로 만든것

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



