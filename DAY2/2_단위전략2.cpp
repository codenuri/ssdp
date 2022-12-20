#include <iostream>
// list 에 앞에 넣는 코드는 변하지 않지만
// 동기화 여부는 변할수 있어야 한다.
// 
// 방법 1. 변하는 것을 가상함수로!! - template method

// 특징(단점) : 동기화 관련 코드를 ThreadSafeList 가 포함하고 있다.
//             vector, stack, queue 등도 동일하게 디자인 하면
//				동기화 관련 코드의 중복이 발생한다!


template<typename T> class List
{
public:
	void push_front(const T& a)
	{
		lock();
		//...... 
		unlock();
	}
	virtual void lock() {}
	virtual void unlock() {}
};

// List 에 동기화 정책을 변경하려면 파생 클래스를 만들어서
// lock/unlock 을 재정의 한다.!
template<typename T> class ThreadSafeList : public List<T>
{
	// pthread_mutex_t mtx;
public:
	virtual void lock() override
	{
		std::cout << "mutex lock" << std::endl;
	}
	virtual void unlock() override
	{
		std::cout << "mutex unlock" << std::endl;
	}
};

//List<int> st; 
ThreadSafeList<int> st;

int main()
{
	st.push_front(10);
}




