#include <memory>
#include "ICalc.h"

int main()
{
	// C++ 표준에 이미 C++ 표준 스마트 포인터가 있는데
	// 이것 사용하면 안되나요 ?
	std::shared_ptr<ICalc> sp1( load_proxy() );
				// => sp1 이 내부적으로 proxy 포인터 보관하다가
				// => sp1 이 파괴될때 소멸자에서 
				// => "delete" 합니다.
				// => 결국 DLL 에서 new 했는데, exe 가 delete 한것!!
				// => 안전하지 않음

	sp<ICalc> sp2(load_proxy());
				// => sp2 파괴시 소멸자 호출
				// => sp2 소멸자에서 "delete 가 아니 Release() 호출" 
				// => Release() 는 DLL 내부에 있고
				// => 여기서 delete 수행
				// => 즉, DLL 에서 new 를 한것을 DLL 내부에서 delete 한것
				// => 안전!!

	// 그래서 C++표준이 스마트 포인터를 제공하지만
	// 대부분의 오픈소스가 위와 같은 이유로 자신만의 스마트 포인터 제공합니다

}