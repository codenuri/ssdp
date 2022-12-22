#include <iostream>
/*
// 싱글톤 코드를 자동생성하는 매크로
#define MAKE_SINGLETON(classname)				\
private:										\
	classname() {}								\
	classname(const classname&) = delete;		\
	classname& operator=(const classname&) = delete;	\
public:													\
	static classname& getInstance()						\
	{													\
		static classname instance;						\
		return instance;								\
	}
*/
#include "helper.h" // 이 안에 위 매크로 있습니다.

class Cursor
{
	MAKE_SINGLETON(Cursor)
};

int main()
{
	Cursor& c1 = Cursor::getInstance();
	Cursor& c2 = Cursor::getInstance();

	std::cout << &c1 << std::endl;
	std::cout << &c2 << std::endl;

}









