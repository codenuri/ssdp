// State - 46 page
#include <iostream>

// ��� #1. ��� ���
// ���� 1. if ���� ��� �����Լ��� �־�� �Ѵ�.
//      2. ���ο� item �� �߰��Ǹ� ��� �����Լ��� �����Ǿ�� �Ѵ�.
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



