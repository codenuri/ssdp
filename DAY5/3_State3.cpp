// State - 46 page
#include <iostream>

// 방법 #2. 변하는 것을 가상함수로!
class Character
{
	int gold;
	int item;
public:
	void run()    { do_run(); }
	void attack() { do_attack(); }

	virtual void do_run() { std::cout << "run" << std::endl; }
	virtual void do_attack() { std::cout << "attack" << std::endl; }
};

class SuperItem : public Character
{
public:
	void do_run()    override { std::cout << "fast run" << std::endl; }
	void do_attack() override { std::cout << "power attack" << std::endl; }
};

int main()
{
	Character* p = new Character;
	p->run();
	p->attack();

	p = new SuperItem;	// 이 코드는 객체 자체를 새롭게 만드는 것
						// 즉, 동작뿐 아니라 상태도 변경합니다.
						// 우리에게 필요 한것은 동일한 객체가
						// "상태(아이템여부)" 에 따라 동작만 교체 하는 것
	p->run();
	p->attack();

}



