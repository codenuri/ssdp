#include <iostream>


// 방법 #2. strategy 패턴 사용
// => 메모리 할당/해지 전략을 별도의 클래스로 분리

// 장점 : vector 뿐 아니라 다양한 컨테이너에서 할당기 사용가능하다.

// 아래 코드는
// 컨테이너가
// => 메모리 할당/해지 방식을 변경할수 있고
// => 할당기도 모든 컨테이너에서 사용가능하다..

// 그런데.. 한가지 개선점은!!!
// => vector 는 표준 라이브러리이다. 성능이 매우 중요하다


// 모든 메모리 할당기가 지켜야 하는 규칙
template<typename T> struct IAllocator
{
	virtual T* allocate(std::size_t sz) = 0;
	virtual void deallocate(T* ptr, std::size_t sz) = 0;

	virtual ~IAllocator() {}
};


template<typename T>
class vector
{
	T* ptr = nullptr;
	std::size_t sz;

	//------------------------------------
	IAllocator<T>* alloc = nullptr;
public:
	void set_allocator(IAllocator<T>* a) { alloc = a; }
	//------------------------------------

	void resize(std::size_t newsize)
	{
		// 이제 메모리 할당/해지는 "메모리 할당기" 를 사용하면 됩니다.
		alloc->deallocate(ptr, sz);

		ptr = alloc->allocate(newsize);

		sz = newsize;
	}
};

// 이제 다양한 메모리 할당/해지 정책을 가진 "할당기" 만 만들면 됩니다.
template<typename T> class malloc_allocator : public IAllocator<T>
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
	vector<int> v;
	malloc_allocator<int> ma;
	v.set_allocator(&ma);	// v 에게 메모리 할당기 연결
							// 앞으로 메모리 할당이 필요 하면 이것 사용하라는것

	v.resize(10);	

	// 다른 컨테이너에서도 동일 할당기 사용가능
//	list<int> s;
//	s.set_allocator(&ma);
}
