#include <iostream>

#define MAKE_SINGLETON(classname)				\
private:										\
	classname() {}								\
	classname(const classname&) = delete;		\
	void operator=(const classname&) = delete;	\
public:											\
	static classname& get_instance()			\
	{											\
		static classname instance;				\
		return instance;						\
	}											\
private:

class Cursor
{
	MAKE_SINGLETON(Cursor)
};

int main()
{
	Cursor& c = Cursor::get_instance();
}

