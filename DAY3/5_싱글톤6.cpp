#include <iostream>
#include <mutex>


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
		std::lock_guard<std::mutex> g(mtx);  

		if (sinstance == nullptr)
			sinstance = new Cursor;

		return *sinstance;
	}
};
Cursor* Cursor::sinstance = nullptr;
std::mutex Cursor::mtx;

// Mouse Ŭ������ ���� ���� �̱������� �ϰ� �ʹ�.
class Mouse
{
public:
};

int main()
{
	Mouse& m = Mouse::get_instance();

}






