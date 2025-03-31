#include <iostream>

// 방법 #2. strategy 패턴 사용
// => 변하는 것(정책, 알고리즘)을 다른 클래스로 분리.

// 메모리 할당기의 인터페이스
template<typename T> struct IAllocator
{
	virtual T* allocate(std::size_t sz) = 0;
	virtual void deallocate(T* p, std::size_t sz) = 0;

	virtual ~IAllocator() {}
};

template<typename T>
class vector
{
	T* ptr;
	std::size_t size;

	IAllocator<T>* ax = nullptr;
public:
	vector(std::size_t  size, IAllocator<T>* p ) 
		: size(size), ax(p)
	{
		ptr = ax->allocate(size);	// 메모리 할당/해지를
									// allocator 객체에 의존
	}
	~vector()
	{
		ax->deallocate(ptr, size);
	}
};
// 이제 다양한 메모리 할당기를 만들면됩니다.
// => 메모리의 할당/해지만 책임지는 클래스
template<typename T>
class MallocAllocator : public IAllocator<T>
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
int main()
{
	MallocAllocator<int> ma;
	vector<int> v(4, &ma);
}
