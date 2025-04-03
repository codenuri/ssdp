#include <iostream>

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
	slist<int> s;
	// 복습하실때 아래 코드가 실행시 메모리 구조 그려보세요
	// push_front 만 잘 이해 하면 됩니다.
	s.push_front(10);
	s.push_front(20);
	s.push_front(30);
	s.push_front(40);
}
