#define USING_GUI
#include "cppmaster.h"
#include "ICalc.h"



template<typename T> class AutoPtr
{
	T* obj;
public:
	AutoPtr(T* p = nullptr) : obj(p) { if (obj) obj->AddRef(); }
	AutoPtr(const AutoPtr& ap) : obj(ap.obj) { if (obj) obj->AddRef(); }
	~AutoPtr() { if (obj) obj->Release(); }

	T* operator->() { return obj; }
	T& operator*() { return *obj; }


};
















ICalc* ReloadProxy()
{
	void* addr = ec_load_module("CalcProxy.dll");
	typedef ICalc* (*F)();

	F f = (F)ec_get_function_address(addr, "Create");

	printf("Create함수주소 : %p\n", f);
	return f();
}

#include <memory>	// C++ 표준 스마트 포인터(shared_ptr)을 위해서..
/*
template<typename T> class shared_ptr
{
	T* obj;
public:
	~shared_ptr() { delete obj; }
};
*/

int main()
{
	{
		std::shared_ptr<int> p1(new int); // 실행파일에서 new 했습니다.

	}	// <= 이순간 p1의 소멸자에서 delete 합니다.
		//    실행파일에서 new 한 것을 실행파일 쪽에서 delete 하게 됩니다.


	{
		std::shared_ptr<ICalc> p2(ReloadProxy() );
						// => 이미 빌드되어 있는 DLL 내부의 Create()호출
						// => "new" 의 기계어 코드가 실행되어서 메모리 할당
						// => 그런데, new 의 기계어 코드방식은 컴파일러마다 다를수있음
	}	//<= p2 소멸자 delete !!
		//   그런데, 현재 실행파일의 delete 기계어는 DLL 내부의 new 기계어와
		//   호환 되지 않을수 있음(컴파일러가 다르면)

	{
		AutoPtr<ICalc> p3(ReloadProxy()); 

	}	// <== p3의 소멸자가 "delete" 하는게 아님...
		// <== DLL 내부의 Release() 를 호출..
		//     실제 delete 은 DLL 내부에서
		//     new, delete 를 모두 DLL 내부에서 하므로 안전

}





