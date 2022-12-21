// Decorator - 65 page
#include <iostream>

class SpaceShip // 우주 비행선
{
public:
	void fire() { std::cout << "Fire Missile" << std::endl; }
};


// 상속을 사용한 기능의 추가 : 클래스에 정적(코드작성시)으로 기능을 추가
// 포함을 사용한 기능의 추가 : 클래스가 아닌 객체에 동적으로 기능을 추가할수 있다.

class LeftMissile 
{
	SpaceShip* ship; // 핵심 : 포인터 또는 참조로 포함
					 //       (값 타입이면 안됩니다.)
					// 이미 생성되어 있는 우주선 객체를 가리키겠다는
					// 의도!!
public:
	LeftMissile(SpaceShip* s) : ship(s) {}

	void fire()
	{
		ship->fire();	// 이미 생성되어 있던 객체의 기능을 사용하고
		std::cout << "Fire Left Missile" << std::endl; // 새로운 기능 추가
	}
};

int main()
{
	SpaceShip ss;
	ss.fire();

	LeftMissile lm(&ss); // lm 객체는 이미 존재하던 "ss" 객체에 기능을 추가하는
						 // 역활을 하는 객체 입니다.
	lm.fire();
}

