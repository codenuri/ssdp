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
template<typename T> class slist_iterator : public IIterator<T>
{
public:
};










template<typename T> struct slist
{
	Node<T>* head = 0;
public:
	void push_front(const T& a) { head = new Node<T>(a, head); }
};

int main()
{
	slist<int> s;
	s.push_front(10);
	s.push_front(20);
	s.push_front(30);
	s.push_front(40);
}
