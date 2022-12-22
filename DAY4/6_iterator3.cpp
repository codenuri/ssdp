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
}