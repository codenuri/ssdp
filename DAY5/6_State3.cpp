#include <iostream>

// 핵심 
// => 아이템이 3개 라면..
// => 모든 동작 함수도 "3개씩" 있어야 한다.
// => "run", "attack", 등 모든 함수를 3개씩 만들자..

struct IState
{
	virtual void run() = 0;
	virtual void attack() = 0;
	virtual ~IState() {}

	// slide(), jump(), fly() 등의 모든 동작함수를 선언
};

// 각 아이템 별로 동작을 따로 설계 합니다.
class NoItem : public IState
{
public:
	void run()    { std::cout << "run" << std::endl; }
	void attack() { std::cout << "attack" << std::endl; }
};

class SuperItem : public IState
{
public:
	void run() { std::cout << "fast run" << std::endl; }
	void attack() { std::cout << "power attack" << std::endl; }
};

class RedItem : public IState
{
public:
	void run() { std::cout << "slow run" << std::endl; }
	void attack() { std::cout << "weak attack" << std::endl; }
};

class Character
{
	// 결국 각 멤버 함수를 3쌍으로 만들어 둔것
	NoItem state1;
	SuperItem state2;
	RedItem state3;

	IState* state = &state1;

	int gold;
	int item;
	
public:
	void run() { state->run(); }
	void attack() { state->attack(); }

	void get_super_item()
	{
		state = &state2;

		// 타이머 설치후 3분뒤에 호출되는 함수에서
		// state = &state1;
	}
};
int main()
{
	Character* p = new Character;
	p->run();
	p->attack();

	p->get_super_item();
	p->run();
	p->attack();

}



