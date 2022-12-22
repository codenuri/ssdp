#include <iostream>

template<typename T> struct Node
{
	T     data;
	Node* next;

	Node(const T& d, Node* n) : data(d), next(n) {}
};

//=============================================
// 핵심 1. 모든 반복자는 사용법이 동일해야 한다. - 반복자의 인터페이스 필요
// => 아래 이름들은 C#의 반복자, "바다" 의 반복자와 같습니다.
template<typename T> struct IEnumerator
{
	virtual T& GetObject() = 0;
	virtual bool MoveNext() = 0;
	virtual ~IEnumerator() {}
};

// 핵심 2. 모든 컨테이너는 동일 방법으로 반복자를 꺼낼수 있어야 한다.
// => 컨테이너의 인터페이스
template<typename T> struct IEnumerable
{
	virtual IEnumerator<T>* GetEnumerator() = 0;
	virtual ~IEnumerable() {}
};

//=======================================
// slist 의 반복자를 만들어 봅시다.
template<typename T>
class slist_enumerator : public IEnumerator<T>
{
	Node<T>* current;
public:
	slist_enumerator(Node<T>* p = nullptr) : current(p) {}

	virtual T& GetObject() override { return current->data; }

	virtual bool MoveNext() override
	{
		current = current->next;
		return current;
	}

};

//slist_enumerator<int> p1(300번지);
//int n = p1.GetObject();
//p1.MoveNext();







// 모든 컨테이너는 약속된 방법으로 반복자를 꺼낼수 있어야 합니다.
template<typename T> 
struct slist : public IEnumerable<T>
{
	Node<T>* head = 0;
public:
	void push_front(const T& a) { head = new Node<T>(a, head); }

	virtual IEnumerator<T>* GetEnumerator()
	{
		return new slist_enumerator<T>(head);
	}
};




int main()
{
	slist<int> s;
	s.push_front(10);
	s.push_front(20);
	s.push_front(30);
	s.push_front(40); 

	//==========================
	IEnumerator<int>* p1 = s.GetEnumerator();

	do
	{
		std::cout << p1->GetObject() << std::endl;
	} while (p1->MoveNext());
}





