/*
#define MAKE_SINGLETON(classname)							\
private:													\
	classname() {}											\
	classname(const classname&) = delete;					\
	classname& operator=(const classname&) = delete;		\
public:														\
	static classname& get_instance()						\
	{														\
		static classname instance;							\
		return instance;									\
	}
private:
*/
#include "helper.h" // 이 안에 위 매크로가 있습니다.

class Cursor
{
	MAKE_SINGLETON(Cursor)

	int a;
};

int main()
{
	Cursor& c = Cursor::get_instance();
}