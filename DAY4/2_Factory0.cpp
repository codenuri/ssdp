#include <iostream>
#include "helper.h" // �� �ȿ� �Ʒ� ��ũ�� �ֽ��ϴ�.

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







