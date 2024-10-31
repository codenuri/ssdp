// typename.cpp

struct Test
{
	using dword = int; // typedef int dword;
	inline static int value = 10;
};
int p1 = 0;

template<typename T>
void foo(T a)
{
	// 아래 2줄에서 * 의 의미를 생각해 보세요
	// "클래스이름::이름" 에서 "이름" 은 2가지 의미가 가능합니다.
	// 1. 값
	// 2. 타입
	// => 이름의 의미에 따라 연산자 해석방식이 변경됩니다.
	// => 컴파일러는 Test 선언을 통해서 의미를 해석할수 있습니다.
//	Test::value * p1;	// 곱하기 의미. 0 * p1
//	Test::dword * p2;	// 포인터 변수선언. 포인터 연산자. int* p2

	// dependent name(의존이름)
	// => 템플릿 인자 T에 의존해서 꺼내는 이름 "T::이름"
	// => T 를 알수없으므로 조사할수없다.
	// => 그래서 "T::이름" 을 무조건 값으로 해석하기로 약속.
	T::value * p1;	// "값인데 * p1" 인데, p1이 전역변수. ok
//	T::dword * p2;  // 곱하기로 해석해야 하는데, p2가 없는데.. error

	typename T::dword* p2; // dword 를 값이 아닌 타입으로 해석해 달라.
						   // 곱하기가 아닌 포인터 변수의 선언이므로
						   // p2를 이 순간 만드는 것. ok
}
int main()
{
}