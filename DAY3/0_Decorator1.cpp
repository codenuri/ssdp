// Decorator - 65 page
#include <iostream>

class SpaceShip // 우주 비행선
{
public:
	void fire()	{ std::cout << "Fire Missile" << std::endl; }
};

// 상속을 사용한 기능의 추가
// => 객체에 대한 기능 추가가 아닌 클래스에 기능을 추가 한것
class LeftMissile : public SpaceShip
{
public:
	void fire()
	{
		SpaceShip::fire(); // 기존의 기능을 사용
		std::cout << "Fire Left Missile" << std::endl; // 새로운 기능추가
	}
};
int main()
{
	SpaceShip ss;
	ss.fire();

	LeftMissile lm; // 기존에 존재 하던 ss 라는 객체에 기능이 추가된것이 아니라
					// 기능이 추가된 새로운 객체(우주선)을 만든것!!
	lm.fire();
}

