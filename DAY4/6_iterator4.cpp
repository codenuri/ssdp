#include <iostream>


template<typename T> struct Node
{
	T     data;
	Node* next;

	Node(const T& d, Node* n) : data(d), next(n) {}
};

// ��� �ݺ��� Ŭ������ ���Ѿ� �ϴ� ��Ģ
template<typename T>
struct IIterator
{
	virtual bool hasNext() = 0;
	virtual T& next() = 0;
	virtual ~IIterator() {}
};

// ��� �÷����� ���Ѿ� �ϴ� ��Ģ(�ݺ��ڸ� ������ �־�� �Ѵ�.)
template<typename T>
struct ICollection
{
	virtual IIterator<T>* iterator() = 0;
	virtual ~ICollection() {}
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

	// ��ǥ : java ��Ÿ���� �ݺ���

	auto it = s.iterator();

	while (it->hasNext())
	{
		std::cout << it->next() << std::endl;
	}
}
