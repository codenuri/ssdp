template<typename T> class List
{
	// 다양한 멤버 데이타들..
public:
	void push_front(const T& a)
	{
		// mutex lock
		//...... list 의 앞쪽에 추가하는 코드
		// mutex unlock
	}
};
List<int> st; // 전역변수는 멀티스레드에 안전하지 않습니다.

int main()
{
	// mutex lock
	st.push_front(10);
	// mutex unlock
}




