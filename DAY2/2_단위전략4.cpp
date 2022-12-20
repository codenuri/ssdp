#include <iostream>

// 방법 3. 변하는 것을 다른 클래스로!!!
// => 단, 인터페이스 기반 교체가 아니라 template 인자로 교체

// 클래스가 사용하는 특정정책(동기화, Validation등)을 담은 정책 클래스를 
// 교체하는 2가지 기술

//									실행시간교체여부		성능
// 1. 인터페이스를 설계해서 교체		O					가상함수기반 느리다
// 2. 템플릿 인자로 교체				X					인라인치환가능.빠르다.


// 인터페이스 기반 교체 : strategy 패턴.  디자인 패턴 23개에 포함된 기술
// 
// 템플릿 인자로 교체  : policy base(단위전략)디자인
//						C++ 언어의 고유 기술..
//						디자인 패턴 23개에는 포함 안됨.

// 주의!! STL 의 list 가 아래처럼 되어 있지는 않습니다.
// => STL list 는 동기화 안됩니다.
// => 대신, STL 은 다른 용도로 "단위전략"을 많이 사용합니다.

// 아래 코드는 "webkit" 이라는 웹브라우져 엔진 에서 사용하고 있는 기술입니다.

template<typename T, typename ThreadModel = NoLock > class List
{
	ThreadModel locker;

public:
	void push_front(const T& a)
	{
		locker.lock();

		//...... 

		locker.unlock();
	}
};

// 이제 List 에 전달한 다양한 동기화 클래스를 제공합니다.
class NoLock
{
public:
	inline void lock() {}
	inline void unlock() {}
};

class PthreadLocker
{
	// pthread_mutex_t mt;
public:
	inline void lock()   { std::cout << "mutex lock" << std::endl; }
	inline void unlock() { std::cout << "mutex unlock" << std::endl; }
};
//-------------------------------------------------
List<int, NoLock> st; 

List<int, PthreadLocker> st2;


int main()
{
	st.push_front(10);
}




