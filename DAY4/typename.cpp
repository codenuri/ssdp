class Test
{
public:
	inline static int data = 10;
	using DWORD = int;
};
int p1 = 0;

template<typename T>
void foo()
{
	// 아래 코드 에서 * 의 의미를 생각해 보세요
//	Test::data* p1;		// 여기서 * 는 곱하기
//	Test::DWORD* p2;	// 여기서 * 는 곱하기 가 아닌 포인터 연산자

	// 핵심 : "클래스이름::이름" 에서 "이름" 은 
	//		  값일수도 있고(static 멤버 데이타)
	//		  타입 일수도 있습니다.
	// "이름"의 정체에 따라 연산자(*등)의 의미가 다릅니다.

	// 아래 2줄을 생각해 보세요
	// "T::이름" 을 dependent name 이라고 합니다. 
	// => 템플릿 인자에 의존하는 이름
	// => C++ 컴파일러는 무조건 값으로 해석
	T::data* p1;	// 곱하기 p1 이므로 ok
//	T::DWORD* p2;	// 곱하기 p2 라고 생각하는데, p2가 없으므로에러

	typename T::DWORD* p2; // DWORD 를 값이 아닌 타입으로 해달라.
							// p2 선언이므로ok.. 
}

int main()
{

}

