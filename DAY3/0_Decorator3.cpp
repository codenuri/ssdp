#include <iostream>


// 객체의 기능 추가는 재귀적으로 계속 할수있어야 합니다.
// => 기능이 추가된 객체에 다시 기능 추가!!

// 객체와 기능 추가 객체(Decorator)의 공통의 기반 클래스

struct Component
{
	virtual void fire() = 0;
	virtual ~Component() {}
};

class SpaceShip : public Component
{
public:
	void fire() { std::cout << "Fire Missile" << std::endl; }
};


class LeftMissile : public Component
{
	Component* ship;
public:
	LeftMissile(Component* s) : ship(s) {}

	void fire()
	{
		ship->fire();	
		std::cout << "Fire Left Missile" << std::endl;
	}
};

class RightMissile : public Component
{
	Component* ship;
public:
	RightMissile(Component* s) : ship(s) {}

	void fire()
	{
		ship->fire();
		std::cout << "Fire Right Missile" << std::endl;
	}
};

int main()
{
	SpaceShip ss;
//	ss.fire();

	LeftMissile lm(&ss);
//	lm.fire();

//	RightMissile rm(&ss);
	RightMissile rm(&lm); // 되면 좋지 않을까요 ?
						  // 기능이 추가된 객체에 다시 기능 추가.
	rm.fire();

}

