#include <iostream>
#include <mutex>

// 동기화 버전

class Cursor
{
private:
	Cursor() {}
	Cursor(const Cursor&) = delete;
	Cursor& operator=(const Cursor&) = delete;

	
	static Cursor* sinstance;
	static std::mutex mtx;
public:
	static Cursor& get_instance()
	{
		mtx.lock();

		if (sinstance == nullptr)
			sinstance = new Cursor;

		mtx.unlock();
		return *sinstance;
	}
};
Cursor* Cursor::sinstance = nullptr;
std::mutex Cursor::mtx;




int main()
{
	Cursor& c1 = Cursor::get_instance();

}






