#include <iostream>
#include <mutex>

// RAII IDioms
// 자원의 획득과 반납은 "생성자/소멸자" 를 통해서 자동으로 되도록 해야 한다!!

// => Resource Acquision Is Initialization
// => 자원이 할당되는 것은 (자원관리객체의) 초기화 과정이다.
//    라는 의미...



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
	Cursor& operator=(const Cursor&) = delete;


	static Cursor* sinstance;
	static std::mutex mtx;
public:

	static Cursor& get_instance()
	{
	
		std::lock_guard<std::mutex> g(mtx);  // C++ 표준에 이미 있습니다.

//		lock_guard<std::mutex> g(mtx);
				// #1. g의 생성자에서 lock
				// #2. g파괴시 소멸자에서 unlock
				// #3. 함수 중간에 return 문이 있거나 예외가 나와도
				//	   g는 안전하게 파괴 된다 - 소멸자 호출되고 unlock
				// #4. 함수 중간에서 unlock 하려면 {} 를 사용하세요
				
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






