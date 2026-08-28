#include <algorithm>

int main()
{
	int x[5] = { 1,2,-5,3,-4 };

	// 정렬하기
	std::ranges::sort(x); // 오름 차순 정렬

	// 정렬기준을 변경하고 싶다
	// => 정렬시 필요한 요소 비교를 인자로 전달된 함수를 사용해 달라
	// => 비교 함수의 인자를 1개로 할까요 2개로 할까요 ?
	std::ranges::sort(x, 비교함수);

	// C++98 스타일
	std::ranges::sort(x, [](int a, int b) { return abs(a) < abs(b); } );

	// 파이썬 스타일
	// "비교함수(요소1) < 비교함수(요소2)"
	//std::ranges::sort(x, [](int a) { return abs(a); });

	// C++20 스타일 : 2개 모두 가능해!!!

	std::ranges::sort(x, [](int a, int b) { return a < b; },
							[](int a) { return abs(a); });

	// a, b의 요소 비교가 필요하면
	// 이항함수(단항함수(a), 단항함수(b)) 의 결과 사용
	std::ranges::sort(x, 이항함수, 단항함수);
}