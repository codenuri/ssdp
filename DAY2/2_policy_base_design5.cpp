#include <iostream>
#include <vector>

// STL 컨테이너에 전달할 메모리 할당기 만들기
// 1. 반드시 template 으로 할 필요는 없지만
//    "다양한 타입에 대해서 메모리 할당이 필요 하므로" 관례상 template 으로

template<typename T> class debug_alloc
{

};


int main()
{
//	std::vector<int> v; // std::vector<int, std::allocator<T>> v 와 동일
	
	std::vector<int, debug_alloc<int>> v;

	std::cout << "-----------------" << std::endl;

	v.resize(5);

	std::cout << "-----------------" << std::endl;
}
