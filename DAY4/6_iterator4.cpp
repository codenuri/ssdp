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
	Node<T>* current;
public:
	slist_iterator(Node<T>* p = nullptr) : current(p) {}


	inline T& operator*() { return current->data; }

	inline slist_iterator& operator++()
	{
		current = current->next;
		return *this;	// ++연산자는 자신을 참조로 반환해야 합니다.
	}
};

//slist_iterator p1(300번지);
//int n = *p1; // p1.GetObject();
//++p1;  //p1.MoveNext();






template<typename T>
struct slist 
{
	Node<T>* head = 0;
public:
	void push_front(const T& a) { head = new Node<T>(a, head); }
	
	slist_iterator<T> begin() { return slist_iterator<T>(head); }
};



int main()
{
	slist<int> s;
	s.push_front(10);
	s.push_front(20);
	s.push_front(30);
	s.push_front(40);

	//==========================
	slist_iterator<int> p = s.begin();

	std::cout << *p << std::endl; // 40
	++p;
	std::cout << *p << std::endl; // 30
}





