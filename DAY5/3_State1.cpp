﻿// State - 46 page
#include <iostream>

// 게임의 캐릭터를 생각해 봅시다.
// Item 획득에 따라 기존 캐릭터의 다양한 동작을 변경하고 싶다.
class Character
{
	int gold;
	int item;
public:
	void run()    { std::cout << "run" << std::endl; }
	void attack() { std::cout << "attack" << std::endl; }
};
int main()
{
	Character* p = new Character;
	p->run();
	p->attack();
}



