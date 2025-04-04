// State - 46 page
#include <iostream>

// 방법 #1. 제어문 사용
// 단점 1. if 문이 모든 동작함수에 있어야 한다.
//      2. 새로운 item 이 추가되면 모든 동작함수가 수정되어야 한다.
class Character
{
	int gold;
	int item;
public:
	void run() 
	{ 
		if ( item == 1)
			std::cout << "run" << std::endl; 
		else if ( item == 2 )
			std::cout << "fast run" << std::endl;
	}

	void attack() { std::cout << "attack" << std::endl; }
};
int main()
{
	Character* p = new Character;
	p->run();
	p->attack();
}



