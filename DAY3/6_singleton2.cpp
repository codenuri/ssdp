#include <iostream>

// static 지역변수 : get_instance() 가 최초 호출될때 Cursor 생성
//					지연된 초기화
//					필요할때 생성한다는 것


// static 멤버변수 : 프로그램 처음 실행 될때 Cursor 생성. main 함수 이전에 생성자 호출
//					이른 초기화
//					

class Cursor
{
private:
	Cursor() { std::cout << "Cursor()\n"; }

	Cursor(const Cursor&) = delete;
	Cursor operator=(const Cursor&) = delete;

//	Cursor instance;	// error. 자신의 타입으로 멤버 데이타 만들수 없다
	static Cursor instance;	// ok
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
	std::cout << "A\n";
//	Cursor& c1 = Cursor::get_instance();
//	Cursor& c2 = Cursor::get_instance();

}








