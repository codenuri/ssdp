#include <algorithm>
#include <vector>
#include <string>
#include <print>

int main()
{
	std::vector<std::string> v = { "AA", "B", "CCC" };

	// a, b 비교 필요하면
	// 2번째인자함수(3번째인자함수(a), 3번째인자함수(b))
	/*
	std::ranges::sort(v, 
					  [](int a, int b) { return a < b; },
					  [](const std::string& s) { return s.size(); });
					  */

	// v안의 모든 요소를 사전순서가 아닌 문자열 길이로 정렬한것
	std::ranges::sort(v, {}, &std::string::size );

	std::println("{}", v); // C++23 출력.  vector 를 바로 출력 가능
}