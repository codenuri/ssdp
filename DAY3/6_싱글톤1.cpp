// 7_싱글톤1 - 123 page
#include <iostream>

// 싱글톤 : 오직 한개의 객체만 존재하고
//		   프로그램의 어디에서도 동일한 방법으로 접근 할수 있다.

// => 결국 "전역변수" 와 유사합니다.
// => 그런데, 전역변수는 좋지 않다고 배우게 됩니다.
// => 그래서, 싱글톤 패턴도 비판이 많습니다.



class Cursor
{
	// 규칙 1. 생성자를 private 에
private:
	Cursor() {}

	// 규칙 2. 컴파일러가 복사생성자와 대입연산자를 만들지 못하게
	Cursor(const Cursor&) = delete;				// 복사 생성자를 만들지말라
	Cursor& operator=(const Cursor&) = delete;	// 관례상. 복사를 금지하면
												//         대입도 금지



	// 규칙 3. 오직 한개의 객체만 만들어서 반환하는 static 멤버 함수
public:
	static Cursor& get_instance()
	{
		static Cursor instance; // 핵심 : static 지역변수
		return instance;
	}
};
int main()
{
	Cursor& c1 = Cursor::get_instance();
	Cursor& c2 = Cursor::get_instance();

	std::cout << &c1 << std::endl;
	std::cout << &c2 << std::endl;

//	Cursor c3 = c1; // 복사 생성자 사용
					// 복사 생성자는 사용자가 만들지 않으면 컴파일러 제공
					// error 나오게 해야 합니다.
					// 
//	Cursor c1, c2; // error. private 생성자
}








