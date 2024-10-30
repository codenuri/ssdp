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
		std::lock_guard<std::mutex> g(mtx);
//		lock_guard<std::mutex> g(mtx); // 1. g의 생성자에서 mtx.lock()
										// 2. 지역변수 g 파괴시 소멸자에서 mtx.unlock()
										// 장점 1. 예외 발생해도 g의 소멸자는 호출하고
										//	      예외 핸들러로 이동
										// 장점 2. 실수할수 없다. g의 소멸자는 항상호출
//		mtx.lock();

		if (sinstance == nullptr)
			sinstance = new Cursor;
	
	//	if (실패) return 0; // 이경우도 g의 소멸자 호출..

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






