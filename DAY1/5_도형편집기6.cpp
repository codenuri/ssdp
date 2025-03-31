#include <iostream>
#include <vector>


// #6. ������ �����̶� ?
// => 1994�� �߰��� å�� ����
// => 4���� ���ڰ� C++ ���¼ҽ� �м��� ��� �����ϴ� �ڵ� ����� 
//    "�̸��� �ο�" �Ѱ�
// 
// => 23���� �̸�

// => 4���� ������(Gang's Of Four) ��� �ǹ̷� GOF ��� �մϴ�.
//    GOF �� ������ ����

// #7. prototype ����
// => ���� ��ü�� �����ؼ� ���ο� ��ü�� ����� ���
// => clone() �����Լ�
// => ���� ���� ������ ����ϳ� ���� �˴ϴ�.


// #8. �����丵 ������ �ִ� ��� �Դϴ�. �ǹ̸� ���� �غ�����

// => "Replace Conditional With Polymorphism"
// => "����� �ڵ忡 ���(if, switch)�� �ִٸ� ������(�����Լ�)
//    �� �����ϴ� ���� ������ ����"
//    "����������3.cpp" �� "����������4.cpp" �� �����ض�



class Shape
{
	int color = 0;
public:
	virtual ~Shape() {}

	void set_color(int c) { color = c; }


	virtual int get_area() { return -1; }

	virtual void draw() { std::cout << "draw shape\n"; }

	// �ڽ��� ���纻�� ����� �����Լ��� ���� �����ϰ� Ȱ�� �˴ϴ�.
	virtual Shape* clone() { return new Shape(*this); }
};



class Rect : public Shape
{
public:
	void draw() override  { std::cout << "draw rect\n"; }

	Shape* clone() override { return new Rect(*this); }
};

class Circle : public Shape
{
public:
	void draw() override { std::cout << "draw circle\n"; }

	Shape* clone() override { return new Circle(*this); }
};

int main()
{
	std::vector<Shape*> v;

	while (true)
	{
		int cmd;
		std::cin >> cmd;

		if (cmd == 1) v.push_back(new Rect);
		else if (cmd == 2) v.push_back(new Circle);

		else if (cmd == 9)
		{
			for (auto s : v)
				s->draw();	
		}
		else if (cmd == 0)
		{
			std::cout << "���° ������ ���� �ұ�� ?";

			int k;
			std::cin >> k;

			// k��° ������ �������� ���� v�� �߰��մϴ�.
			// ��� �����ؾ� �ұ�� ?
			// k��° ������ � �����ϱ�� ?
			
			// �ذ�å #1. Ÿ�� ���� !!
			// => OCP �� �������� ���ϴ� ���� ������..
			/*
			if (dynamic_cast<Rect*>(v[k]) != nullptr)
			{
				v.push_back(new Rect(*(static_cast<Rect*>(v[k])));
			}
			else if((dynamic_cast<Circle*>(v[k]) != nullptr)
			{
				v.push_back(new Circle((*(static_cast<Rect*>(v[k])));
			}
			*/

			// �ذ�å #2. ������ Ȱ�� - ���� �ڵ�
			v.push_back(v[k]->clone()); // ok ������
										// OCP ����
										// ���ο� ���� �߰��ص� 
										// �ڵ� ���� �ȵ�.
										
			// java ���������� �� �����
			// "don't ask, do it" �̶�� �մϴ�. 
			// 
			// �ǹ̸� ������ ������
		}
	}
}

