#include <iostream>
#include <vector>

// STL 컨테이너에 전달할 메모리 할당기 만들기
// 1. 반드시 template 으로 할 필요는 없지만
//    "다양한 타입에 대해서 메모리 할당이 필요 하므로" 관례상 template 으로

// 2. C++ 표준에서 약속되어 있는 멤버 함수를 만들고, 메모리 할당/해지 방법 구현
template<typename T> class debug_alloc
{
public:
	T* allocate(std::size_t sz)
	{
		void* ptr = malloc(sizeof(T) * sz);
		printf("[allocate] %p, %u\n", ptr, sz);
		return static_cast<T*>(ptr);
	}
	void deallocate(T* ptr, std::size_t sz)
	{
		free(ptr);
		printf("[deallocate] %p, %u\n", ptr, sz);
	}

	// C++ 표준 할당기를 만들때는 아래 3개도 필요
	// => 관례적인 코드이므로 그냥 복사해서 사용하면됩니다.
	using value_type = T;

	debug_alloc() {}  // 디폴트 생성자
	template<typename U> debug_alloc(const debug_alloc<U>&) {}//generic 생성자
};






int main()
{
//	std::vector<int> v; // std::vector<int, std::allocator<T>> v 와 동일
	
	std::vector<int, debug_alloc<int>> v;

	std::cout << "-----------------" << std::endl;

	v.resize(5);	// 1. 새로운 메모리 할당
					// 2. 기존 메모리 내용 => 새로운 메모리에 복사
					// 3. 기존 메모리 제거
					// => 위 작업을 할때 debug_alloc 의 멤버 함수 사용

	std::cout << "-----------------" << std::endl;
	v.resize(10);
	std::cout << "-----------------" << std::endl;

}


