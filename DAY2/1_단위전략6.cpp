#include <iostream>
#include <vector>

// 사용자 정의 메모리 할당기(STL 컨테이너용)
// 1. 반드시 템플릿일 필요는 없지만 다양한 타입에 사용하기 위해
//    대부분 템플릿
// 2. 반드시 약속된 함수를 만들어야 한다.
template<typename T>
class debug_alloc
{

};


int main()
{
	std::vector<int, debug_alloc<int> > v;

	std::cout << "-----------------" << std::endl;

	v.resize(4);

	std::cout << "-----------------" << std::endl;

	v.resize(8);

	std::cout << "-----------------" << std::endl;
}
