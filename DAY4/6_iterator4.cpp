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



