// range1
#include <iostream>
#include <vector>

// 아래 클래스를 잘 생각해 보세요
template<typename C> class take_view
{
	C& c;
	int cnt;
public:
	take_view(C& c, int n) : c(c), cnt(n) {}

	auto begin() { return c.begin(); }
	auto end()   { return std::next(c.begin(), cnt); }
};
int main()
{
//	std::vector<int> v = { 1,2,3,4,5,6,7,8,9,10 };
	std::vector v = { 1,2,3,4,5,6,7,8,9,10 };

	take_view tv(v, 5);

//	for (auto e : v)
	for (auto e : tv)
	{
		std::cout << e << ", ";
	}

	std::cout << std::endl;
}