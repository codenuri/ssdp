#include <iostream>

// Iterator 를 직접 구현하려면 "간단한 자료구조 클래스" 가 필요 합니다.
// 
// 아래 코드는 "싱글 링크드 리스트" 입니다.

template<typename T> struct Node
{
	T     data;
	Node* next;

	Node(const T& d, Node* n) : data(d), next(n) {}
};

template<typename T> struct slist
{
	Node<T>* head = 0;
public:
	void push_front(const T& a) { head = new Node<T>(a, head); }
};

int main()
{
	// 아래 코드의 메모리 그림을 이해하면 됩니다.
	slist<int> s;
	s.push_front(10);
	s.push_front(20);
	s.push_front(30);
	s.push_front(40);
}
