#include <iostream>


template<typename T> struct Node
{
	T     data;
	Node* next;

	Node(const T& d, Node* n) : data(d), next(n) {}
};



template<typename T>
class slist_iterator
{
	Node<T>* current = nullptr;
public:
	slist_iterator(Node<T>* p = nullptr)
		: current(p) {
	}
	inline slist_iterator& operator++()
	{
		current = current->next;
		return *this;
	}

	inline T& operator*() { return current->data; }
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

	auto p = s.begin();

	std::cout << *p << std::endl; // 40
	++p;
	std::cout << *p << std::endl; // 30

}


