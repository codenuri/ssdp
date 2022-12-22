#include <iostream>

class Cursor
{
private:
	Cursor() {}
	Cursor(const Cursor&) = delete; 
	Cursor& operator=(const Cursor&) = delete;
	
public:
	static Cursor& getInstance()
	{
		static Cursor instance;
		return instance;
	}
};
int main()
{
	Cursor& c1 = Cursor::getInstance();
}









