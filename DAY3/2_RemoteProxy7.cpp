#define USING_GUI
#include "cppmaster.h"
#include "ICalc.h"

// 6번예제처럼 포인터를 직접 사용하면
// => 규칙이 어렵지는 않지만
// 1. 지루한 코드가 반복되고
// 2. 실수할수 있습니다. ( 실수로 Release(), AddRef() 호출 생략)

// Proxy 패턴 : 기존 것을 사용하지 말고, 대신할 것을 만들자는 것
//			   "진짜 포인터"를 사용하지 말고 "대신할 것" 을 만들어서 사용합니다

template<typename T> class sp
{
	T* obj;
public:
	sp(T* p = nullptr) : obj(p) { if (obj != nullptr) obj->AddRef(); }

	sp(const sp& other) : obj(other.obj) { if (obj != nullptr) obj->AddRef(); };

	~sp() { if (obj != nullptr) obj->Release(); }

	// sp 를 진짜 포인터 처럼 -> 와 * 를 사용할수 있게 해야 한다.
	T* operator->() { return obj; }
	T& operator*() { return *obj; }
};
// 위 sp 가 C++ 진영에서 유명한 "스마트 포인터" 입니다.
// 스마트 포인터는 "smart proxy" 입니다.
// 즉, proxy 패턴 ( 포인터의 대행자 )

// 실제 "안드로이드 내부 소스에 sp" 가 있습니다.

int main()
{
	sp<ICalc> calc1 = load_proxy(); // sp<ICalc> calc1( load_proxy() )
	sp<ICalc> calc2 = calc1;

	int n = calc1->Add(10, 20); // calc1은 포인터를 대신하므로
								// -> 와 * 연산이 되야 합니다.
								// "연산자 재정의" 문법으로 만들면 됩니다.

	std::cout << n << std::endl;
}

/*
int main()
{
	ICalc* calc1 = load_proxy();
	calc1->AddRef(); 

	ICalc* calc2 = calc1;
	calc2->AddRef(); 
	calc1->Release(); 

	std::cout << "-----------\n";
	calc2->Release();	
	std::cout << "-----------\n";

}
*/




