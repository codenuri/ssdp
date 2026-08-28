#include <iostream>

// 방법 #1. Item 에 따라 다른 동작을 구현하기 위해 조건문 사용
// => 모든 동작함수에 if 문이 필요 하다
// => 새로운 아이템이 추가되면 모든 동작 함수의 if 문이 수정된다.
// => OCP 위반

class Character
{
	int gold;
	int item = 1;
public:
	void run() 
	{ 
		if ( item == 1 )
			std::cout << "run" << std::endl; 
		else if (item == 2)
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



