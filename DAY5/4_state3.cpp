#include <iostream>

// 방법 #2. 변하는 것을 가상함수로

class Character
{
	int gold;
	int item = 1;
public:
	void run()    { do_run(); }
	void attack() { do_attack(); }
		
	virtual void do_run()    { std::cout << "run" << std::endl; }
	virtual void do_attack() { std::cout << "attack" << std::endl; }
};

class SuperCharacter : public Character
{
public:
	void do_run()    { std::cout << "fast run" << std::endl; }
	void do_attack() { std::cout << "power attack" << std::endl; }
};

int main()
{
	Character* p = new Character;	// 여기서 캐릭터 객체 생성 - "A"
	p->run();
	p->attack();

	p = new SuperCharacter; // 이 코드는 "A" 의 동작이 변경된 것이 아님
							// 다른 동작을 가진 새로운 객체를 만든것
							// 원하는 것 : 동일 객체의 모든 동작을 변경
							// 현재 코드 : 새로운 객체의 생성(변경)
							// => 동일 객체의 동작만 전체를 변경할수 없을까?
							// => state 패턴. 다음 예제
	p->run();
	p->attack();
}



