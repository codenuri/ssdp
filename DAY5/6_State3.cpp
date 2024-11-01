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
	// character 멤버 복사
};




class Character
{
	int gold;
	int item;
public:
	void run() { std::cout << "run" << std::endl; }
	void attack() { std::cout << "attack" << std::endl; }
};
int main()
{
	Character* p = new Character;
	p->run();
	p->attack();
}



