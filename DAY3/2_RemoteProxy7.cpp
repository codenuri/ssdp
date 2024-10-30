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
};


int main()
{
	sp<ICalc> calc1 = load_proxy(); // sp<ICalc> calc1( load_proxy() )
	sp<ICalc> calc2 = calc1;
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




