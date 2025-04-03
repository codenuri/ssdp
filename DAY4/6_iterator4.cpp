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
//-------------------------------------------------------
// �Ʒ� �ڵ尡 �̱۸���Ʈ �ݺ��� �Դϴ�.
// => ����� �ʽ��ϴ�.

template<typename T>
class slist_iterator : public IIterator<T>
{
	Node<T>* current;
public:
	slist_iterator(Node<T>* p = nullptr)
		: current(p) {}

	// ���� ��ӵ� ������� �̵��� �ϸ�˴ϴ�.
	T& next() override 
	{
		T& tmp = current->data;
		current = current->next; // ����Ʈ�̵�
		return tmp;
	}

	bool hasNext() override
	{
		return current != nullptr;
	}

};

//slist_iterator<int> p(300����);



// ��� �÷����� �ݺ��ڸ� ������ �־�� �մϴ�
// => ICollection �������̽� ����
template<typename T> 
struct slist : public ICollection<T>
{
	Node<T>* head = 0;
public:
	void push_front(const T& a) { head = new Node<T>(a, head); }


	IIterator<T>* iterator() override
	{
		return new slist_iterator<T>( head );
	}
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

// iterator �� �ᱹ
// => �÷���(list��)�� 1��° ��Ҹ� ����Ű�� �����͸� ������ �ִٰ�
// => ��ӵ� ��Ģ��� �̵�/������� �ϴ°�

// C++�� �����ϴ� �� ����� ����.  

// #1. �ݺ��ڸ� ������ s.iterator()�� ������ ������
// =>

// #2. next() �Լ��� �����Լ� �Դϴ�.


// #3. �迭�� ��ȸ ����� ������ ������


