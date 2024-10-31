// typename.cpp

struct Test
{
	using dword = int; // typedef int dword;
	inline static int value = 10;
};

int p1 = 0;

template<typename T>
void foo(T a)
{
	// 아래 2줄에서 * 의 의미를 생각해 보세요
	Test::value * p1;
	Test::dword * p2;
}
int main()
{
}