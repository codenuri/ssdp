#include <iostream>

// 동일한 객체의 "멤버함수 전체를 변경하고 싶다면"
// 멤버 함수를 인터페이스로 설계 하세요
struct IAction
{
	virtual void run() = 0;
	virtual void attack() = 0;
	virtual ~IAction() {}

	// slide(), jump(), fly() 등의 모든 함수..
};

// 이제 상태(어떤 아이템을 획득했는가)에 따른 동작을 정의하는 클래스를 만드세요
// 핵심 : 멤버 데이타는 없고 동작만 정의 합니다.
class NoItem : public IAction
{
public:
	void run() override { std::cout << "run\n"; }
	void attack() override { std::cout << "attack\n"; }
};
class SuperItem : public IAction
{
public:
	void run() override { std::cout << "fast run\n"; }
	void attack() override { std::cout << "power attack\n"; }
};

class BadItem : public IAction
{
public:
	void run() override { std::cout << "slow run\n"; }
	void attack() override { std::cout << "weak attack\n"; }
};
// 위 코드의 의미 : Character 가 사용할 모든 멤버 함수를 여러개를 준비한것

class Character
{
	// 결국 아래 3개는 3쌍의 멤버 함수를 가지고 있는것
	NoItem ni;
	SuperItem si;
	BadItem bi;

	int gold;
	int item;
	IAction* action = &ni;
public:
	void acquire_superitem()
	{
		// 모든 멤버 함수의 교체
		action = &si;
		// 타이머를 설치해서 주어진 시간후 timeout 호출되게
	}
	void acquire_baditem()
	{
		action = &bi;
	}
	// 아이템 지속시간 경과
	void timeout()
	{
		action = &ni;
	}


	void run() { action->run(); }
	void attack() { action->attack(); }
};
int main()
{
	Character* p = new Character;
	p->run();
	p->attack();
	
	p->acquire_superitem(); // 아이템 획득, 이제 동작이 모두 변경됩니다.
	p->run();
	p->attack();
	
	p->timeout(); // 아이템 획득후 지속시간 경과
	p->run();
	p->attack();

}



