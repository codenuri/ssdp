#include <iostream>


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


//=============================
// 우주선에 기능을 추가하는 클래스들은 유사한 코드가 많습니다.
// 공통의 기반 클래스를 설계하면 좋습니다.

class Decorator : public Component
{
	// 기능추가를 위해 공통으로 필요한 다양한 멤버들..
	Component* comp;
public:
	Decorator(Component* comp) : comp(comp) {}

	void fire() { comp->fire(); }
};
// 이제 모든 기능 추가 객체는 "Decorator"에서 파생 됩니다.
class LeftMissile : public Decorator
{
public:
	using Decorator::Decorator;

	void fire()
	{
		Decorator::fire();
		std::cout << "Fire Left Missile" << std::endl;
	}
};

class RightMissile : public Decorator
{
public:
	using Decorator::Decorator;

	void fire()
	{
		Decorator::fire();
		std::cout << "Fire Right Missile" << std::endl;
	}
};

int main()
{
	SpaceShip ss;

	LeftMissile lm(&ss);

	RightMissile rm(&lm); 
	rm.fire();

}

