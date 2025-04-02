#include <iostream>

class Cursor
{
private:
	Cursor() {}
	Cursor(const Cursor&) = delete;
	Cursor& operator=(const Cursor&) = delete;

public:
	
	static Cursor& get_instance()
	{
//		Cursor instance;	// 지역변수는 stack 에 놓임
							// stack 은 스레드당 한개
							// 2개 스레드가 수행되면 각각 따로 생성
							// 스레드에 안전

		// 아래 코드는 스레드에 안전합니다.
		// get_instance() 가 여러개 스레드에서 동시에 호출되어도
		// 아래 생성자는 1회 호출됨을 보장하고
		// A 스레드가 생성자 호출시 B가 도착하면
		// A 의 생성자 호출종료를 대기 합니다
		// => "spin lock" 기술(busy waiting) 로 동기화
		// C#, java 도 동일
		
		static Cursor instance; // static storage 에 할당
								// 모든 스레드가 공유
								// 오직 한개만 생성됨
	
		return instance;
	}


};
int main()
{
	Cursor& c1 = Cursor::get_instance();

}






