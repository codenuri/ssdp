#include <iostream>


template<typename T> struct Node
{
	T     data;
	Node* next;

	Node(const T& d, Node* n) : data(d), next(n) {}
};


template<typename T>
struct IIterator
{
	virtual bool hasNext() = 0;
	virtual T& next() = 0;
	virtual ~IIterator() {}
};

template<typename T>
struct ICollection
{
	virtual IIterator<T>* iterator() = 0;
	virtual ~ICollection() {}
};


template<typename T>
class slist_iterator : public IIterator<T>
{
	Node<T>* current;
public:
	slist_iterator(Node<T>* p = nullptr)
		: current(p) {
	}

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

template<typename T>
struct slist : public ICollection<T>
{
	Node<T>* head = 0;
public:
	void push_front(const T& a) { head = new Node<T>(a, head); }


	IIterator<T>* iterator() override
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



	auto it = s.iterator();

	while (it->hasNext())
	{
		std::cout << it->next() << std::endl;
	}
}



