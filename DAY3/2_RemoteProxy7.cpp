#define USING_GUI
#include "cppmaster.h"
#include "ICalc.h"

// raw pointer 를 대신 하는 클래스를 만들어 봅시다.
// => smart proxy 라는 기술
// => 흔히 "smart pointer" 라고 알려진 기술

template<typename T> 
class sp
{
	T* obj;
public:
	sp(T* p = nullptr) : obj(p) { if (obj != nullptr) obj->AddRef(); }
	sp(const sp& other) : obj(other.obj) { if (obj != nullptr) obj->AddRef(); }
	~sp() { if (obj != nullptr) obj->Release(); }

	// 스마트 포인터는 "포인터를 대신" 해서 사용하므로
	// -> 와 * 를 되도록하기 위해서 연산자 재정의를 하게 됩니다.
	T* operator->() { return obj; }
	T& operator*() { return *obj; }
};

int main()
{
	sp<ICalc> calc1 = load_proxy(); // sp<ICalc> calc1( load_proxy() )
	sp<ICalc> calc2 = calc1;

	// calc1 은 raw pointer 대신 사용하는 것이므로
	// -> 와 * 연산을 지원해야 합니다.
	int n1 = calc1->Add(10, 20);
	int n2 = (*calc1).Sub(10, 20);
}


/*
int main()
{
	ICalc* calc1 = load_proxy();
	calc1->AddRef();	

	ICalc* calc2 = calc1;
	calc2->AddRef();	

	calc2->Release();	
	std::cout << "----------------------\n";

	calc1->Release();	

	std::cout << "----------------------\n";


}
*/

