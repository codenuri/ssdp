#include <iostream>
#include <mutex>

// RAII
// => 자원 관리는 직접하지 말라!
// => 생성자와 소멸자로 관리하라
// => C++ IDioms 중 가장 중요한 개념



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

		// 함수 중간에서 
		// 1. 예외가 나오면 - catch 로 이동. 아래 mtx.unlock() 실행안됨
		// 2. 나중에 추가한 코드에서 실수가 있었다
		// if ( 어떤 이유로 ) { return 돌아갈래;}
		// => 이런 이유로 RAII 가 필요합니다.

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








