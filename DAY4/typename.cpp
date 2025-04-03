class Test
{
public:
	inline static int data = 10;

	using DWORD = int;
};
int* p1 = 0;

template<typename T>
void foo()
{
	// 아래 코드 에서 * 의 의미를 생각해 보세요
	Test::data* p1;
	Test::DWORD* p2;
}

int main()
{

}