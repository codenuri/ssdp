#define USING_GUI
#include "cppmaster.h"
#include "ICalc.h"

int main()
{
	ICalc* calc = load_proxy();	

	int n1 = calc->Add(1, 2);


	delete calc;	
}





