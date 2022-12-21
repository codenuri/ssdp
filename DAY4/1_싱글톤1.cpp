// 7_싱글톤1 - 123 page
#include <iostream>

// 싱글톤 
// 1. 오직 한개의 객체만 존재하는 것.
// 2. 프로그램의 어디에서도 오직 한개의 객체에 동일한 방법으로 접근가능한것          

class Cursor
{
	// 규칙 1. private 생성자
private:
	Cursor() {}

	// 규칙 2. 복사 생성자와 대입연산자를 컴파일러가 만들지 못하게 한다.
	Cursor(const Cursor&) = delete; // 삭제해 달라!
	Cursor& operator=(const Cursor&) = delete; 
								// => 복사 생성자 삭제시 관례적으로
								//    대입 연산자도 삭제


	// 규칙 3. 오직 한개의 객체를 만들어서 반환하는 static 멤버 함수
public:
	static Cursor& getInstance()
	{
		static Cursor instance;
		return instance;
	}
};
int main()
{
	Cursor& c1 = Cursor::getInstance();
	Cursor& c2 = Cursor::getInstance();

	std::cout << &c1 << std::endl;
	std::cout << &c2 << std::endl;

//	Cursor c1, c2; // error. private 생성자

	Cursor c3 = c1; // 복사 생성자도 사용할수 없게 해야 합니다.
}









