#include <iostream>

// vector 의 메모리 할당 방법을 사용자가 변경할수 있도록 만들어 봅시다

// 방법 #1. template method 패턴





template<typename T>
class vector
{
	T* ptr = nullptr;
	std::size_t sz;
public:
	void resize(std::size_t newsize)
	{
//		delete[] ptr;			
		deallocate(ptr, sz);

//		ptr = new T[newsize];	
		ptr = allocate(newsize);

		sz = newsize;
	}

	// 메모리 할당/해지 를 책임지는 가상함수
	virtual T* allocate(std::size_t sz)
	{
		return new T[sz];
	}
	virtual void deallocate(T* p, std::size_t sz)
	{
		delete[] p;
	}
};

// 위 설계의 의도
// => 메모리 할당/해지 방법을 변경하려면 "파생클래스를 만들어서"
// => 약속된 가상함수를 override
template<typename T> class malloc_vector : public vector<T>
{
public:
	T* allocate(std::size_t sz) override
	{
		void* ptr = malloc(sizeof(T) * sz);
		return static_cast<T*>(ptr);
	}
	void deallocate(T* p, std::size_t sz) override
	{
		free(p);
	}
};
int main()
{
//	vector<int> v;
	malloc_vector<int> v;
	v.resize(10);	
}
