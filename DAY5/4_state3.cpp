#include <iostream>

// 방법 #2. 변하는 것을 가상함수로

class Character
{
	int gold;
	int item = 1;
public:
	void run()    { do_run(); }
	void attack() { do_attack(); }
		
	virtual void do_run()    { std::cout << "run" << std::endl; }
	virtual void do_attack() { std::cout << "attack" << std::endl; }
};


int main()
{
	Character* p = new Character;
	p->run();
	p->attack();
}



