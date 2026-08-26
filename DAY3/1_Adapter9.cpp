#include <iostream>
#include <list>
#include <vector>
#include <deque>
#include <stack> // 이 안에 있는 stack 이 Adapter8.cpp 와 유사
#include <queue>

int main()
{
	// C++ 표준에서는 "stack" 을 "stack adapter" 라고 부릅니다
	// => cppreference.com 에 접속해 보세요
	// => 1번째 화면에서 "container library" 선택

	std::stack<int> s1;	// std::stack<int, std::deque<int>> s1;
	std::stack<int, std::vector<int>> s2;
	std::stack<int, std::list<int>> s3;

	s1.push(10); // 내부적으로 std::deque 의 push_back() 사용

	std::queue<int> q1;
	std::queue<int, std::list<int>> q2;
}