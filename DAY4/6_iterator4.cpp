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
		return new slist_iterator<T>( ? );
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
