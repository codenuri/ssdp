#include <iostream>

// policy base design ( 단위전략 디자인 ) - 42p ~ 

template<typename T>
class vector
{
	T* ptr = nullptr;
	std::size_t sz;
public:
	void resize(std::size_t newsize)
	{
		delete[] ptr;			// 기존 버퍼를 제거하고

		ptr = new T[newsize];	// 새로운 버퍼를 할당

		sz = newsize;
	}
};

int main()
{
	vector<int> v;
	v.resize(10);
}

// 위 코드의 문제점
// => vector 라는 클래스의 메모리 할당 방법을 변경할수 없습니다.
//    (항상 new/delete 로만 할당/해지 됩니다.)
// => C++ 에는 다양한 메모리 할당 방법이 있습니다.
//    (new / malloc / system call(windows api) / memory pooling)