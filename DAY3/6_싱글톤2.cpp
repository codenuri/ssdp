#include <iostream>

// static 멤버 데이타 vs static 지역변수

// static 지역변수 : 함수가 최초 호출되는 순간 Cursor() 생성자 호출
//					함수를 호출하지 않으면 Cursor() 생성자 호출 안됨
//					지연된 초기화

// static 멤버 데이타 : main 함수 가 실행되기 전에 Cursor 생성자 호출
//						한번도 사용하지 않아도 Cursor 생성자 호출
//						이른 초기화.



class Cursor
{
private:
	Cursor() { std::cout << "Cursor()\n"; }
	Cursor(const Cursor&) = delete;				
	Cursor& operator=(const Cursor&) = delete;	

//	Cursor instance;		// error
	static Cursor instance; // ok. static 멤버 데이타로 자신 타입가능
public:
	static Cursor& get_instance()
	{
//		static Cursor instance; 
		return instance;
	}
};
Cursor Cursor::instance; // static 멤버 데이타는 외부 선언 필요

int main()
{
	std::cout << "=======\n";
//	Cursor& c1 = Cursor::get_instance();

}



