// 방법 #1. template method 패턴 사용
// => 변하는 것(메모리 할당/해지 방법)을 가상함수로 분리하자는 것

template<typename T>
class vector
{
	T* buff = nullptr;
	int size;
public:
	virtual T* allocate(std::size_t sz)           { return new T[sz]; }
	virtual void deallocate(T* p, std::size_t sz) { delete[] p; }


	vector(int sz) : size(sz)
	{
		buff = new T[size];
		//....
	}
	~vector()
	{
		delete[] buff;
		//....
	}
};

int main()
{
	vector<int> v(4);
}


