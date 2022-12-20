#include <iostream>
#include <vector>

// STL 컨테이너가 사용할수 있는 사용자 정의 메모리 할당기 만들기
// => 1. allocate/deallocate 를 반드시 만들어야 합니다.
// => 2. 추가로 3개의 멤버가 더 필요 합니다.(관례적인 코드들..)
template<typename T> 
class log_alloc
{
public:
	T* allocate(std::size_t sz)
	{
		void* p = malloc(sizeof(T) * sz);
		
		printf("allocate : %d cnt, %p\n", sz, p);

		return static_cast<T*>(p);
	}

	void deallocate(T* p, std::size_t sz)
	{
		printf("deallocate : %d cnt, %p\n", sz, p);
		free(p);
	}

	// 관례적으로 아래 3개도 필요 합니다.
	log_alloc() {}
	typename T value_type;

	template<typename U> log_alloc(const std::log_alloc<U>&) {}
};
int main()
{
	std::vector<int, log_alloc<int> > v;

	std::cout << "=================" << std::endl;

	v.resize(5);
	std::cout << "=================" << std::endl;

	v.resize(10);
	std::cout << "=================" << std::endl;
}

