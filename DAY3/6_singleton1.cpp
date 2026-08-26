// 7_싱글톤1 - 123 page
#include <iostream>

// 싱글톤 : 오직 한개의 객체만 존재하는 것.
//		   그리고, 어디에서도 동일한 방법으로 객체에 접근 할수 있다

class Cursor
{
	// 규칙 #1. 생성자를 private 에
private:
	Cursor() {}

	// 규칙 #2. 복사 생성자와 대입연산자를 컴파일러가 만들지 않도록
	Cursor(const Cursor&) = delete;
	Cursor operator=(const Cursor&) = delete;


	// 규칙 #3. 오직 한개의 객체를 만들어서 반환하는 static 멤버 함수
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

//	Cursor c3 = c1; // 일반 생성자가 아닌 복사 생성자
					// 사용자가 만들지 않으면 컴파일러 제공
}








