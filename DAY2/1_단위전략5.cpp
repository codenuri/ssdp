#include <iostream>
#include <vector>

int main()
{
//	std::vector<int> v; // std::vector<int, std::allocator<T>> v;

	std::vector<int, debug_alloc<int> > v;

	std::cout << "-----------------" << std::endl;

	v.resize(5);

	std::cout << "-----------------" << std::endl;
}
