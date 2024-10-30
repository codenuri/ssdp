#include <iostream>


class Cursor
{
private:
	Cursor() {}

	Cursor(const Cursor&) = delete;				
	Cursor& operator=(const Cursor&) = delete;	

public:

	// C++11 부터 static 지역변수의 생성자 호출은
	// 멀티스레드에 안전합니다.
	// 아래코드에서 "스레드 A" 가 먼저 도착해서 생성자를 호출하고 있을때
	// "스레드 B" 가 도착하면 A의 생성자 호출이 종료될때까지 대기 합니다.
	// => 즉, 동기화 됨.
	// => 동기화 방법은 "spin lock(busy waiting)" 입니다.
	static Cursor& get_instance()
	{
		static Cursor instance; // lock()
								// Cursor() 호출
								// unlock()

		return instance;
	}

};
int main()
{



}







