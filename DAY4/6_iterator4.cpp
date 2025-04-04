#include <iostream>


template<typename T> struct Node
{
	T     data;
	Node* next;

	Node(const T& d, Node* n) : data(d), next(n) {}
};

// 모든 반복자 클래스가 지켜야 하는 규칙
template<typename T>
struct IIterator
{
	virtual bool hasNext() = 0;
	virtual T& next() = 0;
	virtual ~IIterator() {}
};

// 모든 컬렉션이 지켜야 하는 규칙(반복자를 꺼낼수 있어야 한다.)
template<typename T>
struct ICollection
{
	virtual IIterator<T>* iterator() = 0;
	virtual ~ICollection() {}
};
//-------------------------------------------------------
// 아래 코드가 싱글리스트 반복자 입니다.
// => 어렵지 않습니다.

template<typename T>
class slist_iterator : public IIterator<T>
{
	Node<T>* current;
public:
	slist_iterator(Node<T>* p = nullptr)
		: current(p) {}

	// 이제 약속된 방법으로 이동만 하면됩니다.
	T& next() override 
	{
		T& tmp = current->data;
		current = current->next; // 리스트이동
		return tmp;
	}

	bool hasNext() override
	{
		return current != nullptr;
	}

};

//slist_iterator<int> p(300번지);



// 모든 컬렉션은 반복자를 꺼낼수 있어야 합니다
// => ICollection 인터페이스 구현
template<typename T> 
struct slist : public ICollection<T>
{
	Node<T>* head = 0;
public:
	void push_front(const T& a) { head = new Node<T>(a, head); }


	IIterator<T>* iterator() override
	{
		return new slist_iterator<T>( head );
	}
};


int main()
{
	slist<int> s;
	s.push_front(10);
	s.push_front(20);
	s.push_front(30);
	s.push_front(40);

	// 목표 : java 스타일의 반복자

	auto it = s.iterator();

	while (it->hasNext())
	{
		std::cout << it->next() << std::endl;
	}
}

// iterator 란 결국
// => 컬렉션(list등)의 1번째 요소를 가리키는 포인터를 가지고 있다가
// => 약속된 규칙대로 이동/요소접근 하는것

// C++이 생각하는 위 방식의 단점.  

// #1. 반복자를 꺼내는 s.iterator()의 구현을 보세요
// => new 를 사용해서 반복자가 생성됩니다.
// => delete 가 필요 합니다.
// => 라이브러리 내부에서 new 한것을 사용자가 delete 하는 것은 좋지 않습니다

// #2. next() 함수는 가상함수 입니다.
// => 1~2 회 호출하는 것은 문제 없지만
// => 루프안에서 수백~천번 호출되는 것은 오버헤드가 큽니다.


// #3. 배열을 순회 방법을 생각해 보세요
// => int* p = arr; 처럼 포인터로 처음을 가리키게 하고
// => ++p 로 이동 *p 로 접근합니다.
// => 즉, 위 방법은 배열을 순회하는 것과는 다릅니다.
// => "모든 컬렉션을 동일하게" 라는 정책에 위배 됩니다.


