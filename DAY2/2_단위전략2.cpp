// list 에 앞에 넣는 코드는 변하지 않지만
// 동기화 여부는 변할수 있어야 한다.
// 
// 방법 1. 변하는 것을 가상함수로!! - template method

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

List<int> st; 

int main()
{
	st.push_front(10);
}




