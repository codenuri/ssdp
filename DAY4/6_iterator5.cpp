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

	// �������� �̵��ϰ� ��ҿ� �����ϴ� ����
	// => ���� �����Ϳ� ������ ������� �մϴ�.
	// => ������ ������ ���

	// C++��Ģ : operator++ �� �ڽ��� ������ ��ȯ�ؾ� �Ѵ�.
	//           (�׷��� ���� ��밡�� ++(++p))
	inline slist_iterator& operator++()
	{
		current = current->next; 
		
		return *this;
	}

	inline T& operator*() { return current->data; }
	
	// �����Ϳ� �����ϰ� ����Ϸ��� ==, != �� �־�� �մϴ�.
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

		return slist_iterator<T>(head); // new ������!
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



