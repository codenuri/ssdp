#include <iostream>

template<typename T> struct Node
{
	T     data;
	Node* next;

	Node(const T& d, Node* n) : data(d), next(n) {}
};

// 함수를 인터페이스로 약속하면 "가상함수" 입니다.
// 다음으로 이동하는 방법을 "인터페이스"로 약속하지 말고
// "문서화로 약속(표준문서)"

// 배열을 열거하는 방법과 동일하게(++로 이동, *로 요소 접근)

// "p.next()" ===> "++p" (p.operator++())
//					"*p"
template<typename T> class slist_iterator 
{
	Node<T>* current;
public:
	slist_iterator(Node<T>* p = 0) : current(p) {}

	inline slist_iterator& operator++()
	{
		current = current->next;
		return *this;
	}
	inline T* operator*() { return current->data; }	
};


template<typename T> struct slist 
{
	Node<T>* head = 0;
public:
	void push_front(const T& a) { head = new Node<T>(a, head); }

	slist_iterator<T> begin()
	{
		return slist_iterator<T>(head); // 임시객체
	}
};
int main()
{
	slist<int> s;
	s.push_front(10);
	s.push_front(20);
	s.push_front(30);
	s.push_front(40);

	auto it = s.begin();
	std::cout << *it << std::endl; // 40
	++it;
	std::cout << *it << std::endl; // 30

}

// 위 방식이 대부분의 객체지향언어(C#, Java, Python, Swift 등)가 사용하는 방식
// 
// C++ 진영에서 위 방식에 대해서 생각하는 문제점

// #1. s.iterator() 반환하는 반복자는 "new" 로 만들게 됩니다.
//	   delete 가 필요하지 않을까요 ?
// 
// #2. 다음으로 이동하는 next()/hasNext()가 가상함수 입니다.
//     가상함수는 호출의 오버헤드가 있습니다.
//     next() 는 루프안에서 수천 ~ 수만번도 호출될수 있습니다.
// 
// #3. 배열도 collection 입니다.
//     C++에서 배열을 열거할때는 "포인터" 사용합니다.
//     p가 포인터일때 "p->next()" 할수 없습니다.
//		포인터는 ++p 로 이동
//     "모든 컬렉션을 동일한 방법으로" 라는 규칙 위배