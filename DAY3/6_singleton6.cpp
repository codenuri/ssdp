#include <iostream>
#include <mutex>

// RAII
// => 자원 관리는 직접하지 말라!
// => 생성자와 소멸자로 관리하라
// => C++ IDioms 중 가장 중요한 개념

// Resource Acquision Is Initialization 이라는 기술
// 자원을 획득하는 것은 (자원 관리객체) 가 초기화 되는 때 이다
// => 자원의 해지가 아닌 자원의 획득을 강조하는 용어
// => 생성자에서 자원 획득하면 당연히 소멸자 에서 자원해지는 필수 이다 라는 관점


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
		{
			std::lock_guard<std::mutex> g(mtx);
			//lock_guard<std::mutex> g(mtx);	// 1. g 의 생성자에서 mtx.lock() 수행
			//		mtx.lock();						// 2. g 의 소멸자에서 mtx.unlock() 수행
													// 3. 함수 수행중 예외, return 등의 발생해도 
													//    지역변수는 파괴 됩니다
													//    즉, 왠만하면 g의 소멸자 호출은 보장 됩니다.
			if (sinstance == nullptr)
			{
				sinstance = new Cursor;
			}
			//		mtx.unlock();
		}
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








