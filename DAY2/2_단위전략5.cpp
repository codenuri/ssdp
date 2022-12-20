
// STL 의 원리
template<typename T, typename Alloc = std::allocator<T> >
class vector
{
	T* buff;

	Alloc ax; // 메모리 할당기
			  // 앞으로 vector 의 모든 멤버 함수에서는 메모리 할당/해지가 필요하면
			  // 이 할당기를 사용해야 합니다.
public:
	void resize(int n)
	{
		// 버퍼 크기가 부족해서 다시 할당하려고 합니다.
		// 어떻게 할당할까요 ?
		// C++에서는 메모리를 할당하는 방법이 아주 많이 있습니다.
		// new / malloc / system call / windows api/ 풀링 

		buff = ax.allocate(n); // 규칙 1. 메모리 할당기는 반드시
								//       "allocate" 가 필요 합니다.
		ax.deallocate(buff, n); // 규칙 2. "deallocate" 가 있어야 합니다.
	}
};
// cppreference.com 에 접속해서.. 오른쪽 위 검색창에 "std::vector" 검색해 보세요





