#include <iostream>

class Animal
{
public:
	int age;
};

class Dog : public Animal
{
public:
	int color;
};

int main()
{
	Animal a;
	Dog d;

//	Animal* p = &d;	
	Animal* p = &a;

	std::cout << p << std::endl;

	// static_cast vs dynamic_cast
	// static_cast : ������ �ð� ĳ����
	//				 �����Ϸ��� p�� ����Ű�� ��ü�� �����Ҽ� ����.
	//				 ���� �Ʒ��ڵ�� �׻� ����
	//				 ��ȯ�� p1���� color ������ �߸��� �ڵ�
	Dog* p1 = static_cast<Dog*>(p);

	std::cout << p1 << std::endl;

//	p1->color = 10; // �߸��� �ڵ�.���� ����ϸ� �ȵ˴ϴ�

	
	// dynamic_cast : ���� �ð� ĳ����
	// => ����� p�� ����Ű�� ���� Dog ��� ����
	// => Dog �� �ƴϸ� 0 ��ȯ
	// => ��, �����Լ��� ���� Ÿ�Ը� ����Ҽ� �ִ�.
	//   (�����Լ� ���̺��� ����ؼ� �����ϹǷ�)

	Dog* p2 = dynamic_cast<Dog*>(p);

	std::cout << p2 << std::endl;
}











