#include <iostream>
#include <mutex>

// 동기화

class Cursor
{
private:
	Cursor() {}
	Cursor(const Cursor&) = delete;
	Cursor operator=(const Cursor&) = delete;

	static std::mutex mtx;
	static Cursor* sinstance;
public:
	
	static Cursor& get_instance()
	{
		mtx.lock();

		if (sinstance == nullptr)
		{
			sinstance = new Cursor;
		}
		mtx.unlock();

		return *sinstance;
	}
};
Cursor* Cursor::sinstance = nullptr;
std::mutex Cursor::mtx;

int main()
{
	Cursor& c1 = Cursor::get_instance();
	Cursor& c2 = Cursor::get_instance();
}








