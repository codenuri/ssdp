// 1_State1 - 182 page
#include <iostream>

// 방법 3. 변하는 것을 다른 클래스 로!!

// 아이템 획득에 따라 변해야 하는 모든 동작을 정의한 인터페이스
struct IAction
{
	virtual void run() = 0;
	virtual void attack() = 0;
	virtual ~IAction() {}

	// 이외에도 "jump(), slide(), fly()" 등 다양한 동작들을 포함.
};


class Charater
{
	int gold;
	int item;
	IAction* action = nullptr;
public:
	void set_action(IAction* p) { action = p; }
	
	// 캐릭터의 모든 동작은 "동작을 정의한 Action 객체" 에 의존 합니다.
	// => action 객체에 따라 캐릭터의 모든 동작은 변경되지만
	// => "상태(멤버 데이타)" 는 유지 합니다.
	// => "클래스의 대부분의 멤버 함수"를 교체 하는 것
	void run() { action->run(); }
	void attack() { action->attack(); }
};

// 아이템에 따른 동작을 정의한 클래스들
class NoItem : public IAction
{
public:
	virtual void run()    override { std::cout << "run" << std::endl; }
	virtual void attack() override { std::cout << "attack" << std::endl; }
};

class RedItem : public IAction
{
public:
	virtual void run()    override { std::cout << "fast run" << std::endl; }
	virtual void attack() override { std::cout << "attack" << std::endl; }
};

class StarItem : public IAction
{
public:
	virtual void run()    override { std::cout << "fast run" << std::endl; }
	virtual void attack() override { std::cout << "power attack" << std::endl; }
};

int main()
{
	NoItem ni;
	RedItem ri;
	StarItem si;

	Charater* p = new Charater;
	p->set_action(&ni);
	p->run();
	p->attack();

	p->set_action(&si); // 캐릭터의 동작을 변경합니다.
						// => 하지만 상태는 유지 됩니다.
						// => 마치 다른 클래스를 사용하는 효과를 보게 됩니다.
	p->run();
	p->attack();

}



