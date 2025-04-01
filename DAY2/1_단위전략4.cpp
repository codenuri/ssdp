#include <iostream>

// 방법 #3. policy base design (단위전략 디자인 기술)
// => 변하는 것(정책, 알고리즘)을 다른 클래스로 분리하는데

// => 교체 할때 인터페이스 기반이 아니라 템플릿 인자로 전달하는 것
// => 가상함수의 오버헤드가 없고, 인라인 치환등의 특징을 활용할수있다

// => 이때 인터페이스가 없으므로 함수이름(allocate, deallocate) 은
//    문서화해서 약속되어야 한다.



// std::allocator<T>  : C++ 표준이 제공하는 메모리 할당기
//						allocate/deallocate 가 이미 있고
//						new, delete 사용합니다.

template<typename T, typename Allocator = std::allocator<T> >
class vector
{
	T* ptr;
	std::size_t size;

	Allocator ax;

public:
	vector(std::size_t  size) : size(size)
	{
		ptr = ax.allocate(size);	
	}
	~vector()
	{
		ax.deallocate(ptr, size);
	}
};
template<typename T>
class MallocAllocator 
{
public:
	inline T* allocate(std::size_t sz) 
	{
		return static_cast<T*>(malloc(sizeof(T) * sz));
	}
	inline void deallocate(T* p, std::size_t sz)
	{
		free(p);
	}
};
int main()
{
//	vector<int, MallocAllocator<int> > v(4);

	vector<int > v(4);
}
