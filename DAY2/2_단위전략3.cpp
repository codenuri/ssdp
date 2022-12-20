#include <iostream>

// 방법 2. 변하는 것을 다른 클래스로!!
// 장점 : 동기화 정책(PthreadLocker)를 다른 클래스(vector, stack, queue등)
//       에서도 사용가능하다.

// 단점 : 동기화 정책을 담은 lock/unlock 이 가상함수 이다. 느리다
//		  좀더 빠른 다른 방법은 없을까 ??? 




// 동기화 정책은 교체 가능해야 하므로 인터페이스 설계
struct ISync
{
	virtual void lock() = 0;
	virtual void unlock() = 0;
	virtual ~ISync() {}
};

template<typename T> class List
{
	ISync* psync = nullptr;
public:
	void set_sync_object(ISync* p) { psync = p; }

	void push_front(const T& a)
	{
		if (psync)
			psync->lock();
		//...... 
		if (psync)
			psync->unlock();

	}
};

// 이제 다양한 환경에 맞는 다양한 동기화 정책을 제공하면 됩니다.
class PthreadLocker : public ISync
{
	// pthread_mutex_t mt;
public:
	virtual void lock()   { std::cout << "mutex lock" << std::endl; };
	virtual void unlock() { std::cout << "mutex unlock" << std::endl; };
};
List<int> st; 

int main()
{
	PthreadLocker locker;
	st.set_sync_object(&locker);

	st.push_front(10);
}





