#include <iostream>


class Cursor
{

private:
	Cursor() {}
	Cursor(const Cursor&) = delete;
	Cursor operator=(const Cursor&) = delete;

public:
	// 2 개이상의 스레드가 동시에 아래 함수를 실행한다면 안전할까요 ?
	// => 아래 코드는 멀티스레드에 안전한 코드 일까요 ?
	// => 안전합니다.
	// => static 지역변수의 생성자 호출은 C++ 언어에서 스레드 동기화를 책임집니다.
	// => godbolt.org 에서 이 코드 복사하고 get_instance() 어셈 코드 보세요
	static Cursor& get_instance()
	{

		static Cursor instance;


		return instance;
	}
};

int main()
{
	Cursor& c1 = Cursor::get_instance();
	Cursor& c2 = Cursor::get_instance();
}








