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


// 위 코드가 전통적인 객체지향 디자인에서는 "반복자" 입니다.
// => C#, java, swift, python 등이 모두 위 코드와 유사 합니다.
// => "바다(C++)"의 반복자도 위와 거의 유사

// 단점 1. s.GetEnumerator() 가 반환하는 반복자는 "new"로 생성했다.
//         => 사용후에는 반드시 delete 되어야 한다.
//		   => 또는, 스마트 포인터 사용

// 단점 2. GetObject()/MoveNext() 가 가상함수 입니다.
//		   => 가상함수 호출의 오버헤드가 있습니다.(느립니다.)

// 단점 3. raw array 도 컨테이너 입니다.
//        raw array 와 열거 방법이 다릅니다.
//        => raw array 는 포인터를 사용해서 ++p 로 이동하고, *p 로 요소접근





