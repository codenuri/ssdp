#include <iostream>

// À¯ÀÏÇÑ °´Ã¼¸¦ "Èü"¿¡ ¸¸µå´Â ¸ðµ¨

class Cursor
{
private:
	Cursor() {}
	Cursor(const Cursor&) = delete; 
	Cursor& operator=(const Cursor&) = delete;
	
	static Cursor* pinstance;
public:

	static Cursor& getInstance()
	{
		if (pinstance == nullptr)
			pinstance = new Cursor;

		return instance;
	}
};

Cursor* Cursor::pinstance = nullptr;







int main()
{
	Cursor& c1 = Cursor::getInstance();
}









