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
	// �Ʒ� �ڵ� ���� * �� �ǹ̸� ������ ������
	Test::data* p1;
	Test::DWORD* p2;
}

int main()
{

}