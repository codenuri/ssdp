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

// 아래 3개의 패턴은 Diagram 이 완전히 동일합니다.
// => 코드도 거의 유사합니다
// => 의도가 약간 다릅니다.

// strategy : 객체가 사용하는 "알고리즘의 교체"
//			  외부에서 알고리즘을 주입. e.set_validator(알고리즘)

// state : 객체의 모든 동작을 교체(멤버 함수 전체 교체)
//         마치 다른 클래스 처럼 보인다.
//		   위부에서는 객체의 상태만 변경하면, 내부적으로 상태에 맞는 동작결정

// builder : 복잡한 객체를 만들때, 
//			 만드는 방법과 각 단계의 결과를 다르게 하기 위해서 사용


// 자판기를 생각해 봅시다.
// => 커피선택버튼, 환불버튼, 카드 결제처리 기능등이 있습니다.
// => 그런데, "돈을 넣은 상태", "넣지 않은 상태" 에 따라 모든 동작이 다릅니다.
// => 그래서, 상태에 따는 "멤버함수를 별개로 만들어 놓아야 합니다"



