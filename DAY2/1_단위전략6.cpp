#include <iostream>
#include <vector>

// 사용자 정의 메모리 할당기(STL 컨테이너용)
// 1. 반드시 템플릿일 필요는 없지만 다양한 타입에 사용하기 위해
//    대부분 템플릿
// 2. 반드시 약속된 함수를 만들어야 한다.
// => 함수 이름과 모양은 "인터페이스" 로 만들지 않고
// => 문서화(표준문서)로 약속
template<typename T>
class debug_alloc
{
public:
	inline T* allocate(std::size_t sz)
	{
		T* p = static_cast<T*>(malloc(sizeof(T) * sz));
		printf("allocate %p, %zu cnts\n", p, sz);
		return p;
	}
	inline void deallocate(T* p, std::size_t sz)
	{
		printf("deallocate %p, %zu cnts\n", p, sz);

		free(p);
	}

	// 위 2개위에 아래 3개가 필요 (관례적인 코드이므로, 그냥 복사해서 사용하면됩니다.)

	using value_type = T;

	debug_alloc() {}
	
	template<typename U> debug_alloc(const debug_alloc<U>&) {}
};



int main()
{
	std::vector<int, debug_alloc<int> > v;

	std::cout << "-----------------" << std::endl;

	v.resize(4);	// 메모리 할당기로 4개 할당

	std::cout << "-----------------" << std::endl;

	v.resize(8);	// 1. 메모리할당기로 8개 할당
					// 2. 4개 내용 -> 8개 로 복사
					// 3. 메모리할당기로 4개는 제거

	std::cout << "-----------------" << std::endl;
}
