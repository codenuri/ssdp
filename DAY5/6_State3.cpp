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

	void acquire_super_item()
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

	p->acquire_super_item();	// 의미
								// 1. p의 상태(멤버 데이타)는 계속 유지 되지만
								// 2. 이 순간 모든 멤버 함수가 교체 됩니다.
								// 마치 다른 클래스 처럼 보이게 됩니다.
								// "state 패턴" 입니다.	

	p->run();
	p->attack();

}
// 자판기를 생각해 봅시다.
// => 돈을 넣었을때와 넣지 않을때의 모든 동작이 다릅니다.

// => 동작을 2쌍을 준비합니다.

// => "돈이 입력" 되면 "동작을 교체 하고"
// => "음료를 가져가면" 다시 "동작을 교체"

// => 하지만 자판기의 데이타는 계속유지..!!




