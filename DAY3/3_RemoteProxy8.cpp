#define USING_GUI
#include "cppmaster.h"
#include "ICalc.h"

// RemoteProxy7.cpp
// => 어렵지는 않지만
// => 사용자가 직접 참조계수를 관리해야 하므로 "단순 코드의 반복"
// => 그리고, "실수 할수 있다" AddRef()/Release() 를 실수로 호출 안함

// 해결책
// "Raw Pointer" 를 직접 사용하지 말고 "대신 사용할것" 을 만들어 봅시다 - proxy 패턴
// => 스마트 포인터 도입

template<typename T>
class sp
{
	T* obj;
public:
	sp(T* p = nullptr) : obj(p) 
	{ 
		if (obj != nullptr) obj->AddRef(); 
	}

	sp(const sp& other) : obj(other.obj) 
	{
		if (obj != nullptr) obj->AddRef();
	}
	~sp() 
	{
		if (obj != nullptr) obj->Release();
	}

	// 모든 스마트 포인터의 핵심 기술
	// -> 와 * 연산자를 재정의 해서 Raw Pointer 처럼 사용가능하게 한다.
	T* operator->() { return obj; }
	T& operator*() { return *obj; }
};

int main()
{
	sp<ICalc> calc1 = load_proxy(); // sp<ICalc> calc1(load_proxy()); 
	sp<ICalc> calc2 = calc1;

	int n1 = calc1->Add(1, 2);
	int n2 = calc2->Sub(1, 2);

	std::cout << n1 << ", " << n2 << std::endl;

}

/*
int main()
{
	ICalc* calc1 = load_proxy();
	calc1->AddRef();		

	ICalc* calc2 = calc1;
	calc2->AddRef();		
	calc1->Release();
	calc2->Release();
}
*/






