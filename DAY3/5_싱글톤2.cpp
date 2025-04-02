#include <iostream>

// 오직 한개의 객체를 static 멤버 데이타로 만든 모델

// static 지역변수 버전
// => get_instance() 를 처럼 호출할때 Cursor 생성자 호출
// => 필요할때 초기화 하겠다는 의도
// => lazy initialization

// static 멤버 데이타 버전
// => 프로그램 실행시 main 함수 실행전에 Cursor 생성자 호출
// => early initialization


class Cursor
{
private:
	Cursor() { std::cout << "Cursor()\n"; }

	Cursor(const Cursor&) = delete;
	Cursor& operator=(const Cursor&) = delete;

//	Cursor instance; // error. 자신의 타입의 객체를 멤버로 넣을수 없다.
	static Cursor instance; // ok. static 은 가능.

public:
	static Cursor& get_instance()
	{
//		static Cursor instance;
		return instance;
	}
};
Cursor Cursor::instance;


int main()
{
	std::cout << "AAAA\n";
	Cursor& c1 = Cursor::get_instance();
}







