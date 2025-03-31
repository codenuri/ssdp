#include <iostream>

class Animal
{
public:
	// non-virtual : �⺻ ���ε��� static binding ����
	void cry1() { std::cout << "Animal Cry1" << std::endl; }

	// virtual : dynamic binding �ش޶�� �ǹ�
	virtual void cry2() { std::cout << "Animal Cry2" << std::endl; }
};

class Dog : public Animal
{
public:
	void cry1() { std::cout << "Dog Cry1" << std::endl; }

	virtual void cry2() { std::cout << "Dog Cry2" << std::endl; }
};

int main()
{
	Dog d;
	Animal* p = &d;

	p->cry1();	// static binding. ������ Ÿ������ ����
	p->cry2();	// dynamic binding. ��ü Ÿ������ ����(����ð� ����)
}


