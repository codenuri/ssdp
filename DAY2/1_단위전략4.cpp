#include <iostream>
#include <cstdlib> 

// 방법 #3. 단위전략(Policy Base Design)
// => 정책클래스를 "인터페이스"를 사용해서 교체 하는것이 아니라
// => template 인자로 교체하는 기술


template<typename T> class MallocAllocator 
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


// std::allocator<T> : C++ 표준이 제공하는 메모리 할당기
//						new/delete 로 메모리 할당.
template<typename T, typename Alloc = std::allocator<T> >
class vector
{
	T* buff = nullptr;
	int size;

//	MallocAllocator<int> ax; // 강한 결합. 교체 안됨
	Alloc ax;				 // 템플릿 인자로 전달된 타입 사용
							 // 즉, 템플릿 인자로 정책 클래스 교체
public:
	vector(int sz) : size(sz)
	{
		buff = ax.allocate(sz); // 인라인 함수 이므로 "인라인 치환"
								// 성능저하 없음. 아주 빠르다.
		//....
	}
	~vector()
	{
		ax.deallocate(buff, size);
		//....
	}
};

int main()
{

//	vector<int, MallocAllocator<int>> v(4);

	vector<int> v(4);


}



// strategy vs policy base design
// => 모두 클래스가 사용하는 어떤 정책을 "다른 클래스로 분리" 하자는 것

// => 그런데, 정책 클래스를 어떻게 교체 가능하게 할것인가 ?
// 
// strategy           : 인터페이스를 만들어서 교체 가능하게 하자는 것
// policy base design : template 인자를 사용해서 교체 가능하게 하자.

//						성능				유연성
// 인터페이스 기반 :		가상함수			실행시간 교체 가능
//						약간의 오버헤드	edit.set_validator(&v1)
//						느리다.			edit.set_validator(&v2)
// 
// template 인자  :		가상함수아니고		실행시간 교체 안됨.
//						인라인 치환도 가능	객체 생성시 이미 정책이 결정
//						빠르다.				실행시 교체는 안됨.
//											vector<int, MallocAllocator<int>> 

// 디자인 패턴 : 다양한 객체지향 언어로 모두 구현 가능한 범용적 디자인 ( 23개 )
//				(template method, strategy ... )
// 
// IDioms     : 각 언어의 특징을 고려한 디자인 기술
//				(policy base design ....)
//			    C++ IDioms, Java IDioms, C# IDioms

// 구글 "C++ IDioms" 검색