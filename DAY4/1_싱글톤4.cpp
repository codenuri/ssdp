#include <iostream>
#include <mutex>

class Cursor
{
private:
	Cursor() {}
	Cursor(const Cursor&) = delete;
	Cursor& operator=(const Cursor&) = delete;

	static Cursor* pinstance;
	static std::mutex mtx;
public:

	static Cursor& getInstance()
	{
		mtx.lock();

		if (pinstance == nullptr)
			pinstance = new Cursor;

		mtx.unlock();

		return *pinstance;
	}
};
std::mutex Cursor::mtx;
Cursor* Cursor::pinstance = nullptr;







int main()
{
	Cursor& c1 = Cursor::getInstance();
}









