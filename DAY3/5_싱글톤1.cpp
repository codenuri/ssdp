// 7_싱글톤1 - 123 page
#include <iostream>

// 싱글톤 : 오직 한개의 객체만 존재하고
//		   프로그램의 어디에서도 동일한 방법으로 접근 가능 한것

// 결국 "전역변수" 같은 존재
// => 전역변수는 나쁜 코드 입니다
// => 그래서 싱글톤 패턴은 많은 비판이 있습니다.

class Cursor
{
	// 규칙 #1. private 생성자
private:
	Cursor() {}

	// 규칙 #2. 복사 생성자와 대입연산자를 컴파일러가 만들지 못하게!!
	Cursor(const Cursor&) = delete;
	Cursor& operator=(const Cursor&) = delete;


	// 규칙 #3. 오직 한개의 객체를 만들어 반환하는 static 멤버 함수
public:
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

	std::cout << &c1 << ", " << &c2 << std::endl;

	// 아래 처럼만드는 것도 막아야 합니다.
//	Cursor c3 = c1;

//	Cursor c1, c2;
}









