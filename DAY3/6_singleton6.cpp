#include <iostream>
#include <mutex>

// RAII
// => 자원 관리는 직접하지 말라!
// => 생성자와 소멸자로 관리하라
// => C++ IDioms 중 가장 중요한 개념

template<typename T>
class lock_guard
{
	T& mtx;
public:
	lock_guard(T& m) : mtx(m) { mtx.lock(); }
	~lock_guard()             { mtx.unlock(); }
};




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
		lock_guard<std::mutex> g(mtx);

//		mtx.lock();
		if (sinstance == nullptr)
		{
			sinstance = new Cursor;
		}
//		mtx.unlock();

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








