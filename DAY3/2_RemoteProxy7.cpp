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

	calc2->Release();	
	std::cout << "----------------------\n";

	calc1->Release();	

	std::cout << "----------------------\n";


}
*/

