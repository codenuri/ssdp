#include <iostream>
#include <cstdlib> 

// 방법 #3.


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


template<typename T, typename Alloc>
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

	vector<int, MallocAllocator<int>> v(4);


}

