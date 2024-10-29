// 방법 #2. strategy 패턴 적용
// => 클래스(vector)가 사용하는 알고리즘(메모리할당/해지)을 다른 클래스로
//    분리하자는 것


// 메모리 할당/해지를 책임지는 "메모리 할당기(allocator)" 를 만들어 봅시다.

template<typename T> struct IAllocator
{
	virtual T* allocate(std::size_t sz) = 0;
	virtual void void deallocate(T* p, std::size_t sz) = 0;

	virtual ~IAllocator() {}
};


template<typename T> class MallocAllocator : public IAllocator<T>
{
public:
	T* allocate(std::size_t sz) override
	{
		return static_cast<T*>(malloc(sizeof(T) * sz));
	}
	void deallocate(T* p, std::size_t sz) override
	{
		free(p);
	}
};


template<typename T>
class vector
{
	T* buff = nullptr;
	int size;

	
public:
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

