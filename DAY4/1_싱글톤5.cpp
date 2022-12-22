#include <iostream>
#include <mutex>

// lock/unlock 을 직접하게 되면 
// "deadlock" 의 가능성이 있습니다.

// 항상 자원의 관리는 생성자/소멸자를 사용해서 관리해야 합니다.

template<typename T> class lock_guard
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
	Cursor& operator=(const Cursor&) = delete;

	static Cursor* pinstance;
	static std::mutex mtx;
public:

	static Cursor& getInstance()
	{
		lock_guard<std::mutex> g(mtx);
//		mtx.lock();

		if (pinstance == nullptr)
			pinstance = new Cursor;

//		mtx.unlock();

		return *pinstance;
	}
};
std::mutex Cursor::mtx;
Cursor* Cursor::pinstance = nullptr;







int main()
{
	Cursor& c1 = Cursor::getInstance();
}









