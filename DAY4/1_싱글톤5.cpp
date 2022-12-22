#include <iostream>
#include <mutex>

// lock/unlock 을 직접하게 되면 
// "deadlock" 의 가능성이 있습니다.

// 항상 자원의 관리는 생성자/소멸자를 사용해서 관리해야 합니다.
// "RAII" 라는 이름을 가진 기술 ( C++ 진영만의 기술, C++ IDioms)
// => "Resource Acquision Is Initialization"
// => 자원을 획득(mtx.lock) 하게 되는 것은 (자원 관리객체가) 초기화 될때 이다.

// => 구글에서 "C++IDioms" 라고 검색 해보세요.. 1번째 링크.. 

// 디자인 패턴 : 언어에 무관한 객체지향 디자인 기술
// IDioms     : 언어에 특징을 고려한 코딩 테크닉을 지칭하는 용어
//				(C++ IDioms, Java Idioms 등)


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
		std::lock_guard<std::mutex> g(mtx); // C++11 표준에 이미 lock_guard가 
											// 있습니다.

	//	lock_guard<std::mutex> g(mtx); // 생성자에서 "mtx.lock()" 수행
										// 소멸자에서 "mtx.unlock()"
										// 핵심 : 아래 코드에서 예외가 발생해도
										//	      catch 로 이동하기 전에
										//	      g의 소멸자는 호출됨을 보장
										//	      스택풀기(stack unwinding)
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









