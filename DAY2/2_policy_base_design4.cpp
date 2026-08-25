#include <iostream>


// 방법 #3. policy base design 사용

// "변하는 것(메모리할당/해제 정책) 을 다른 클래스로 분리한것

// strategy 패턴      : 인터페이스를 사용해서 정책 클래스를 교체
// policy base design : template 인자를 사용해서 정책 클래스를 교체




// policy_base_design3.cpp 의 특징
// => 함수 이름을 약속하기 위해서 "인터페이스 사용"
// => 인터페이스는 "항상 가상함수" 로 이름을 약속한다
// => 약간의 오버헤드가 있다

// 핵심 #1. 인터페이스로 함수 이름을 약속하지 말자


template<typename T, typename Alloc>
class vector
{
	T* ptr = nullptr;
	std::size_t sz;

//	malloc_allocator<T> alloc; // 클래스 이름 직접 사용, 강한 결합, 교체 안됨
//	IAllcator<T>* alloc;	   // 인터페이스 사용, 약한 결합, 교체 가능
							   // 단, 가상함수 사용됨.
	Alloc alloc;	// template 인자로 전달 받은 타입 사용

public:
	void resize(std::size_t newsize)
	{
		alloc.deallocate(ptr, sz);

		ptr = alloc.allocate(newsize);

		sz = newsize;
	}
};


template<typename T> class malloc_allocator 
{
public:
	inline T* allocate(std::size_t sz) 
	{
		void* ptr = malloc(sizeof(T) * sz);
		return static_cast<T*>(ptr);
	}
	inline void deallocate(T* p, std::size_t sz)
	{
		free(p);
	}
};

int main()
{
	vector<int, malloc_allocator<int> > v;	
//	vector<int, other_allocator<int> > v;

	v.resize(10);

}
