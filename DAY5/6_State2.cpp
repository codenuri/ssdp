#include <iostream>

// 방법 #1. 제어문 
// => 모든 동작 함수에 제어문이 필요 하다.
// => 아이템이 추가되면 모든 함수에 제어문이 추가 되어야 한다.!!
class Character
{
	int gold;
	int item;
public:
	void run() 
	{
		if ( item == 1 )
			std::cout << "run" << std::endl; 
		else if ( item == 2)
			std::cout << "fast run" << std::endl;
	}
	void attack() 
	{ 
		if (item == 1)
			std::cout << "attack" << std::endl; 
		else if (item == 2)
			std::cout << "power attack" << std::endl;
	}
};



int main()
{
	Character* p = new Character;
	p->run();
	p->attack();
}



