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
	slist_iterator(Node<T>* p = nullptr): current(p) {}

	// 다음으로 이동하고 요소에 접근하는 것을
	// => 실제 포인터와 동일한 방법으로 합니다.
	// => 연산자 재정의 기술

	// C++규칙 : operator++ 은 자신을 참조로 반환해야 한다.
	//           (그래야 연속 사용가능 ++(++p))
	inline slist_iterator& operator++()
	{
		current = current->next; 
		
		return *this;
	}

	inline T& operator*() { return current->data; }
	
	// 포인터와 유사하게 사용하려면 ==, != 가 있어야 합니다.
	inline bool operator==(const slist_iterator& other)
	{
		return current == other.current;
	}
	inline bool operator!=(const slist_iterator& other)
	{
		return current != other.current;
	}
};



template<typename T>
struct slist 
{
	Node<T>* head = 0;
public:
	void push_front(const T& a) { head = new Node<T>(a, head); }


	inline slist_iterator<T> begin()
	{
//		slist_iterator<T> it(head);
//		return it;

		return slist_iterator<T>(head); // new 사용안함!
	}

	inline slist_iterator<T> end()
	{
		return slist_iterator<T>(nullptr); 
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
	auto last = s.end();

	while (first != last)
	{
		std::cout << *first << std::endl;
		++first;
	}

	/*
	// C#
	IEnumerator<int> e = s.GetEnumerator();

	while (e.MoveNext())
	{
		WriteLine("{}", e.Current);
	}
	*/
}



