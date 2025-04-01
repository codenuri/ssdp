#include <iostream>
#include <list>
#include <vector>
#include <deque>
// adapter �������� ����� stack �ε�.
// policy base design �� �����ؼ� �������Ͼ��� �����̳�(�����ڷᱸ��)
// �� ��ü�Ҽ� �ִ� ������.
template<typename T, typename C = std::deque<T> >
class stack
{
	C c;
public:
	void push(const T& e) { c.push_back(e); }
	void pop() { c.pop_back(); }
	T& top() { return c.back(); };
}

#include <stack> // �� �ȿ� �ִ� �ڵ尡 ��ó�� �Ǿ� �ֽ��ϴ�.
				 // ����, C++ ǥ���� stack �� "stack adapter" ����մϴ�
int main()
{
	/*
	stack<int, std::list<int>> s1;
	stack<int, std::vector<int>> s2;
	stack<int> s;

	*/
	std::stack<int, std::list<int>> s1;
	std::stack<int, std::vector<int>> s2;
	std::stack<int> s;

	s.push(10);
}
