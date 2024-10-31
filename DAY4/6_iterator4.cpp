#include <iostream>

template<typename T> struct Node
{
	T     data;
	Node* next;

	Node(const T& d, Node* n) : data(d), next(n) {}
};

// 규칙 1. 모든 반복자는 아래 인터페이스를 구현해야 한다.
template<typename T> 
struct IIterator
{
	virtual T& next() = 0;
	virtual bool hasNext() = 0;
	virtual ~IIterator() {}
};

// 규칙 2. 모든 컬렉션은 아래 인터페이스는 구현해야 한다.
template<typename T>
struct ICollection
{
	virtual IIterator<T>* iterator() = 0;
	virtual ~ICollection() {}
};
//----------------------------------------------------
// 자바 스타일로 만든 싱글리스트 반복자
// 반복자의 핵심
// => 1번째 요소를 가리키다가 약속된 방법으로 이동

template<typename T> class slist_iterator
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
