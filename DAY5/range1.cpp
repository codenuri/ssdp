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

template<typename C> class reverse_view
{
	C& c;
public:
	reverse_view(C& c) : c(c) {}

	auto begin() { return c.rbegin(); }
	auto end()   { return c.rend();	}
};

int main()
{
//	std::vector<int> v = { 1,2,3,4,5,6,7,8,9,10 };
	std::vector v = { 1,2,3,4,5,6,7,8,9,10 };

	take_view tv(v, 5);
	reverse_view rv(v);

	v[0] = 100;

//	for (auto e : v)
//	for (auto e : tv)
	for (auto e : rv)
	{
		std::cout << e << ", ";
	}

	std::cout << std::endl;
}