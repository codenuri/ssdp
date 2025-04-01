#include <iostream>
#include <vector>

// STL 에서 사용할 사용자 정의 allocator 만들기
// #1. 반드시 template 일 필요는 없지만, 범용적으로 사용하기 위해
//     대부분 템플릿으로 설계

// #2. 약속된 함수를 만들어야 합니다

template<typename T>
class debug_alloc
{
public:
	inline T* allocate(std::size_t sz)
	{
		T* p = static_cast<T*>(malloc(sizeof(T) * sz));
		printf("allocate %p %zu\n", p, sz);
		return p;
	}
	inline void deallocate(T* p, std::size_t sz)
	{
		printf("deallocate %p %zu\n", p, sz);
		free(p);
	}
	// 위 2개 함수 외에 아래 3개가 더 필요 합니다
	// => 관례적인 코드이고, 무조건 아래처럼 만들면 됩니다.
	using value_type = T;

	debug_alloc() {}

	template<typename U> debug_alloc(const debug_alloc<U>&) {}
			// => generic 생성자라는 개념.. 
			// => 항상 위처럼 만들면 됩니다.
};



int main()
{
//	std::vector<int> v; // std::vector<int, std::allocator<T>> v;

	std::vector<int, debug_alloc<int> > v;

	std::cout << "-----------------" << std::endl;

	v.resize(5);

	std::cout << "-----------------" << std::endl;
}
