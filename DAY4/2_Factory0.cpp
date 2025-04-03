#include <iostream>
#include "helper.h" // 이 안에 아래 매크로 있습니다.

/*
#define MAKE_SINGLETON(classname)						\
private:												\
	classname() {}										\
	classname(const classname&) = delete;				\
	classname& operator=(const classname&) = delete;	\
public:													\
	static classname& get_instance()					\
	{													\
		static classname instance;						\
		return instance;								\
	}													\
private:
*/

class Cursor
{
	MAKE_SINGLETON(Cursor)

	int a;
};

int main()
{
	Cursor& c1 = Cursor::get_instance();

}







