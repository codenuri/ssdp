// 1_State1 - 182 page
#include <iostream>

// 아이템의 획득 상태에 따라 캐릭터의 동작은 변경되어야 합니다.
// 방법 1. 제어문

class Charater
{
	int gold;
	int item;
public:
	void run() 
	{
		if( item == 1 )
			std::cout << "run" << std::endl; 
		else if( item == 2)
			std::cout << "fast run" << std::endl;
	}

	void attack() 
	{
		if ( item == 1)
			std::cout << "attack" << std::endl; 
		else if ( item == 2)
			std::cout << "power attack" << std::endl;
	}
};




int main()
{
	Charater* p = new Charater;
	p->run();
	p->attack();
}



