#include <vector>
#include <iostream>

template<typename T>
class take_view
{
	T& c;
	int count;
public:
	take_view(T& c, int count) : c(c), count(count) {}

	auto begin() { return c.begin(); }
	auto end()   { return c.begin() + count; }
};
int main()
{
	std::vector<int> v = { 1,2,3,4,5,6,7,8,9,10 };
	take_view tv(v, 3);

//	for (auto e : v)
	for (auto e : tv)  // 생각해보세요
	{
		std::cout << e << ", ";
	}
	std::cout << "\n";

}