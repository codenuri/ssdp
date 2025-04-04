#include <iostream>

// ��� ������ ����ϴ� �������̽�
struct IState
{
	// ���ؾ� �ϴ� ��� ������ �������̽��� ���
	virtual void run() = 0;
	virtual void attack() = 0;
	virtual ~IState() {}

	// �̿ܿ� jump(), slide(), fly() ���� ��� �����Լ��� ���
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
	// �������� ����(����Լ�)�� �ʿ�
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
		// ���� �������� ȹ��(���º���)�����Ƿ� ���۵� �����մϴ�.
		// ��ġ �ٸ� Ŭ������ ����ϴ� ��ó�� ���̰� �˴ϴ�.
		current = &state2;

		// Ÿ�̸Ӹ� ��ġ�ϰ� 10�ʵڿ� �ٽ� ���¸� �������
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



