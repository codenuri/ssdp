#include <cstdlib>

// C++ 에서는 다양한 메모리 할당 방법이 있습니다.

int main()
{
	// #1. new/delete
	int* p1 = new int;
	delete p1;


	// #2. malloc/free
	int* p2 = static_cast<int*>(malloc(sizeof(int)));
	free(p2);


	// #3. system call 을 직접 사용하는 방법
	// => 힙할당, 공유 메모리 사용등
	// linux : brk(), mmap()
	// windows : HeapAlloc(), VirtualAlloc()


	// #4. pooling 기법등..
	// => 메모리 할당/해지를 빠르고 효율적(메모리 fragmentation 방지)하기 위한 기술
}