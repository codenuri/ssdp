#include <iostream>

class Animal
{
public:
	int age;
	virtual void cry() {} // �����Լ��� ������
						  // �����Լ� ���̺��� �����
						  // ���̺� �ȿ� Ÿ������ ���
						  // dynamic_cast ��밡��
};
class Dog : public Animal
{
public:
	int color;
};
int main()
{
	Animal a;
	Dog    d;

//	Animal* p = &d;
	Animal* p = &a;
	
//	p->age = 10;   // ok
//	p->color = 10; // error

	// Animal* �� p �� ������ Dog ���� ����� �����Ϸ���
	// Dog* �� ĳ�����ؾ� �մϴ�.
	 
	// static_cast : ������ �ð� ĳ����.! ����� ������� ����
	//				 ������ �ð����� p�� ����Ű�� ���� �����Ҽ� ����.
	//				 �����Ҷ� ����ɼ� �����Ƿ�!!
	//				 �׷��� �Ʒ��ڵ�� ������ ����
	Dog* dog = static_cast<Dog*>(p);

	std::cout << dog << std::endl;

//	dog->color = 10; // ���� p�� ����Ű�� ���� Dog �� �ƴϸ�
					// �� �ڵ�� �߸��� �ڵ�
					// ����� ���������� �ɼ� �ֽ��ϴ�.

	// #2. dynamic_cast : ����ð� ĳ����
	//					  ����ð��� p�� ����Ű�� ���� �����ؼ�
	//					  Dog�� �ƴ� ��� 0 ��ȯ

	// �׷���, dynamic_cast ������Ϸ��� "��ü ��򰡿� Ÿ�������� ����ؾ��Ѵ�."
	// C++�� �����Լ� ���̺��� ���
	// ����, dynamic_cast�� �����Լ��� �ִ� Ÿ�Ը� ����

	Dog* dog2 = dynamic_cast<Dog*>(p);

	std::cout << dog2 << std::endl;


}










