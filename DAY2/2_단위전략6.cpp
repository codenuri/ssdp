#include <iostream>
#include <vector>
#include <memory> // C++ 표준 메모리 할당기

int main()
{
	// 메모리 할당 방법
	// 1. new / delete 를 직접 사용
	// => 아래 처럼 사용시, 메모리 할당 방법을 변경하려면 모든 문장을 변경해야 합니다.
	int* p1 = new int[10];
	delete[] p1;

	int* p2 = new int[10];
	delete[] p2;



	// 2. allocator 사용
	// => 의도 : 메모리 할당 방식을 변경하려면 "할당기" 만 새롭게 만들면 된다.
	// =>       할당기를 사용하는 코드는 변경될 필요 없다.

	std::allocator<int> ax;  // C++ 표준 메모리 할당기
//	MyAlloc<int> ax;  // 사용자가 만든 메모리 할당기!!

	int* p = ax.allocate(10);	// int 를 10개 할당해 달라.
								// 표준 할당기는 "new" 사용해서 할당

	ax.deallocate(p, 10);		// 메모리 해지, 
								// 표준 할당기는 "delete" 사용


}