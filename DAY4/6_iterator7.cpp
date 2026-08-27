#include <iostream>
#include <vector>

int main()
{
	int v[3] = { 1,2,3 };
//	std::vector<int> v = { 1,2,3 };

//	auto first = v.begin(); // C++98 에서 소개된 방법 - 배열 안됨
//	auto first = std::begin(v); // C++11 에서 소개된 방법 - 배열도 가능

//	auto first = std::begin( std::vector{ 1,2,3 } ); // 임시 벡터
									// 에러 아닌데, 절대 first 사용하면 안됨
									// 이미 파괴된 컨테이너를 가리키는 반복자

	auto first1 = std::ranges::begin( v ); // ok. v 는 파괴 안됨
	auto first2 = std::ranges::begin(std::vector{ 1,2,3 }); // error.인자가 임시객체

	

}