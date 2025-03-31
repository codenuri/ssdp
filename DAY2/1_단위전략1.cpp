// github.com / codenuri / ssdp 에서 "DAY2.zip" 받으시면됩니다.

#include <iostream>

// policy base design ( 단위전략 디자인 ) - 42p ~ 

// 아래 코드는 C++ 표준의 vector 와 유사하게 설계한 코드

template<typename T>
class vector
{
	T* ptr;
	std::size_t size;
public:
	vector(std::size_t  size) : size(size) 
	{
		ptr = new T[size];
	}
	~vector()
	{
		delete[] ptr;
	}
};

int main()
{
	vector<int> v(4);
}

// 위 코드의 문제점
// => vector 라는 클래스의 메모리 할당 방법을 변경할수 없습니다.
//    (항상 new/delete 로만 할당/해지 됩니다.)
// 
// => C++ 에는 다양한 메모리 할당 방법이 있습니다.
//    (new / malloc / system call(windows api) / memory pooling)