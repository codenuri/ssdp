// State - 46 page
#include <iostream>

// ��� #2. ���ϴ� ���� �����Լ���!
class Character
{
	int gold;
	int item;
public:
	void run()    { do_run(); }
	void attack() { do_attack(); }

	virtual void do_run() { std::cout << "run" << std::endl; }
	virtual void do_attack() { std::cout << "attack" << std::endl; }
};

class SuperItem : public Character
{
public:
	void do_run()    override { std::cout << "fast run" << std::endl; }
	void do_attack() override { std::cout << "power attack" << std::endl; }
};

int main()
{
	Character* p = new Character;
	p->run();
	p->attack();

	p = new SuperItem;	// �� �ڵ�� ��ü ��ü�� ���Ӱ� ����� ��
						// ��, ���ۻ� �ƴ϶� ���µ� �����մϴ�.
						// �츮���� �ʿ� �Ѱ��� ������ ��ü��
						// "����(�����ۿ���)" �� ���� ���۸� ��ü �ϴ� ��
	p->run();
	p->attack();

}



