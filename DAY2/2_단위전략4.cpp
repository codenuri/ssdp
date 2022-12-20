#include <iostream>

// 방법 3. 변하는 것을 다른 클래스로!!!
// => 단, 인터페이스 기반 교체가 아니라 template 인자로 교체

template<typename T, typename T2> class List
{
	T2 locker;
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




