#include <iostream>

// static 멤버 데이타 vs static 지역변수

class Cursor
{
private:
	Cursor() { std::cout << "Cursor()\n"; }
	Cursor(const Cursor&) = delete;				
	Cursor& operator=(const Cursor&) = delete;	

//	Cursor instance;		// error
//	static Cursor instance; // ok. static 멤버 데이타로 자신 타입가능
public:
	static Cursor& get_instance()
	{
		static Cursor instance; 
		return instance;
	}
};
//Cursor Cursor::instance; // static 멤버 데이타는 외부 선언 필요



int main()
{
//	Cursor& c1 = Cursor::get_instance();

}



