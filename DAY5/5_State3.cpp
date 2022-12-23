// 1_State1 - 182 page
#include <iostream>

// 방법 2. 변하는 것을 가상함수로!!

class Charater
{
	int gold;
	int item;
public:
	void run()    { do_run(); }
	void attack() { do_attack(); }

	virtual void do_run() { std::cout << "run" << std::endl; }
	virtual void do_attack() { std::cout << "attack" << std::endl; }
};

class RedItem : public Charater
{
public:
	virtual void do_run() override    { std::cout << "fast run" << std::endl; }
	virtual void do_attack() override { std::cout << "super power attack" << std::endl; }
};

int main()
{
	Charater* p = new Charater;
	p->run();
	p->attack();

	p = new RedItem; // 아이템 획득 ?
					 // => 기존 캐릭터 객체의 동작이 변경된 것이 아니라
					 // => 변경된 동작을 가진 새로운 캐릭터를 만든것
					 // => 동작 뿐 아니라 상태(지금까지 획득한 gold등)도 변경
					 // => 상태는 유지 하면서 동작만 바꿀수 없을까 ?
	p->run();
	p->attack();
}



