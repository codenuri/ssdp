#include <iostream>
#include <cstdlib> // malloc

// 방법 #2. strategy 패턴 적용
// => 클래스(vector)가 사용하는 알고리즘(메모리할당/해지)을 다른 클래스로
//    분리하자는 것


// 장점 
// => 메모리 할당기(할당정책을 담은 클래스)는 vector 뿐 아니라 
//    다른 컨테이너(list, set, map 등) 에도 사용가능합니다.

// 단점 
// => 메모리 할당을 할때 사용하는 함수가 가상함수 입니다.
// => 가상함수를 약간의 오버헤드가 있습니다.


// 메모리 할당/해지를 책임지는 "메모리 할당기(allocator)" 를 만들어 봅시다.

template<typename T> struct IAllocator
{
	virtual T* allocate(std::size_t sz) = 0;
	virtual void deallocate(T* p, std::size_t sz) = 0;

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

	IAllocator<T>* alloc = nullptr;

public:
	vector(int sz, IAllocator<T>* a) : size(sz), alloc(a)
	{
		buff = alloc->allocate(sz);
		//....
	}
	~vector()
	{
		alloc->deallocate(buff, size);
		//....
	}
};

int main()
{ 
//	vector<int> v(4);
	vector<int> v(4, new MallocAllocator<int>() );

	// 이제 메모리 할당기는 다른 컨테이너에도 사용가능합니다.
//	list<int> s(4, new MallocAllocator<int>() );
}

