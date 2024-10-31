#include <iostream>

template<typename T> struct Node
{
	T     data;
	Node* next;

	Node(const T& d, Node* n) : data(d), next(n) {}
};

template<typename T> class slist_iterator
{
	Node<T>* current;
public:
	slist_iterator(Node<T>* p = 0) : current(p) {}

	// 진짜 포인터와 동일하게 사용하려면 4개의 연산자 재정의 필요
	// => ++, *, ==, !=  
	inline slist_iterator& operator++()
	{
		current = current->next;
		return *this;
	}
	inline T& operator*() { return current->data; }

	inline bool operator==(const slist_iterator& other)
	{
		return current == other.current;
	}
	inline bool operator!=(const slist_iterator& other)
	{
		return current != other.current;
	}

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

	slist_iterator<T> end()
	{
		return slist_iterator<T>(0);
	}
};
int main()
{
	slist<int> s;
	s.push_front(10);
	s.push_front(20);
	s.push_front(30);
	s.push_front(40);

	auto first = s.begin();
	auto last  = s.end();

	while (first != last) // first.operator!=(last)
	{
		std::cout << *first << std::endl;
		++first;
	}
}

