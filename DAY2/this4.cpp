// C++ 에서 범용적 callback 이 어려운 이유
// => 일반 함수 주소와 멤버 함수주소를 모두 담는 함수 포인터가 없습니다.
// => 그래서 만든것이 std::function<>
// => 그런데 std::function 이 없으면, 만들어 봅시다
#include <iostream>

class FunctionPointer
{
	void(*handler)();
public:
	FunctionPointer(void(*f)()) : handler(f) {}

	void execute()
	{
		handler();
	}	
};

void foo() { std::cout << "foo\n"; }

int main()
{
	FunctionPointer mp(&foo);
	mp.execute();
}
