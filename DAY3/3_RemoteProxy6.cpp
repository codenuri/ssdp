#define USING_GUI
#include "cppmaster.h"
#include "ICalc.h"

int main()
{
	ICalc* calc = load_proxy();	// DLL 내부에서 new 를 하고 있습니다.
								// 사용후에는 delete 해야 하지 않을까요 ?


	int n1 = calc->Add(10, 20);
	int n2 = calc->Sub(10, 20);

	std::cout << n1 << ", " << n2 << std::endl;

	delete calc; // 이렇게 해도 될까요 ? 안전한가요 ?
				// 안됩니다.
				// DLL 만들때 컴파일러와
				// exe 만들때 컴파일러가 다를수 있습니다.

}







