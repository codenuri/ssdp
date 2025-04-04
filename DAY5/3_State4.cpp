#include <iostream>

// 모든 동작을 약속하는 인터페이스
struct IState
{
	// 변해야 하는 모든 동작을 인터페이스로 약속
	virtual void run() = 0;
	virtual void attack() = 0;
	virtual ~IState() {}

	// 이외에 jump(), slide(), fly() 등이 모든 동작함수를 약속
};


class NoItem : public IState
{
public:
	void run() { std::cout << "run" << std::endl; }
	void attack() { std::cout << "attack" << std::endl; }
};

class SuperItem : public IState
{
public:
	void run() { std::cout << "fast run" << std::endl; }
	void attack() { std::cout << "power attack" << std::endl; }
};

class BadItem : public IState
{
public:
	void run() { std::cout << "slow run" << std::endl; }
	void attack() { std::cout << "weak attack" << std::endl; }
};

class Character
{
	// 여러벌의 동작(멤버함수)가 필요
	NoItem state1;
	SuperItem state2;
	BadItem state3;

	IState* current = &state1;

	int gold;
	int item;
public:
	void run() { current->run(); }
	void attack() { current->attack(); }

	void acquire_super_item()
	{
		// 이제 아이템을 획득(상태변경)했으므로 동작도 변경합니다.
		// 마치 다른 클래스를 사용하는 것처럼 보이게 됩니다.
		current = &state2;

		// 타이머를 설치하고 10초뒤에 다시 상태를 원래대로
//		current = &state1;
	}
};
int main()
{
	Character* p = new Character;
	p->run();
	p->attack();

	p->acquire_super_item();
	p->run();
	p->attack();

}



