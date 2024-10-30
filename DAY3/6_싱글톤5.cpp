#include <iostream>
#include <mutex>

// 함수의 마지막 부분에서 자원 반납을 하면
// 1. 중간에 예외 발생시, 함수 아래 부분이 실행 안됨
// 2. 실수 할수 있음. "if (실패) return"  자원 반납안하고 돌아감.

// RAII IDioms
// => 자원의 할당과 해지는 생성자/소멸자에 의존해야 합니다.

template<typename T> class lock_guard
{
	T& mtx;
public:
	lock_guard(T& m) : mtx(m) { mtx.lock(); }
	~lock_guard()			  { mtx.unlock(); }
};



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
		lock_guard<std::mutex> g(mtx);

//		mtx.lock();

		if (sinstance == nullptr)
			sinstance = new Cursor;

//		mtx.unlock();

		return *sinstance;
	}






};
Cursor* Cursor::sinstance = nullptr;
std::mutex Cursor::mtx;


int main()
{
	Cursor& c1 = Cursor::get_instance();

}






