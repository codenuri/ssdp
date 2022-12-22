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
		return *this;	
	}

	inline bool operator==(const slist_iterator& it) { return current == it.current; }
	inline bool operator!=(const slist_iterator& it) { return current != it.current; }
};





template<typename T>
struct slist
{
	Node<T>* head = 0;
public:
	void push_front(const T& a) { head = new Node<T>(a, head); }

	// 컨테이너 설계자는 자신의 반복자 이름을 약속된 이름(iterator)으로
	// 외부 노출해야 합니다
	using iterator = slist_iterator<T>;


//	slist_iterator<T> begin() { return slist_iterator<T>(head); }

	iterator begin() { return iterator(head); }
	iterator end()   { return iterator(0); }


};





int main()
{
	slist<int> s;
	s.push_front(10);
	s.push_front(20);
	s.push_front(30);
	s.push_front(40);

	//==========================
	slist<int>::iterator p1 = s.begin();
	slist<int>::iterator p2 = s.end();

	while (p1 != s.end()) // 또는 p1 != p2
	{
		std::cout << *p1 << std::endl;
		++p1;
	}
}

	






