#include <iostream>

// 오직 한개의 객체를 static 멤버 데이타로 만든 모델

class Cursor
{
private:
	Cursor() {}
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
	Cursor& c1 = Cursor::get_instance();
}







