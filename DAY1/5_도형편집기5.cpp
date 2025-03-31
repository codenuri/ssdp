#include <iostream>
#include <vector>

// #5. ������(Polymorphism) �̶�� ���!
// => �ᱹ, �����Լ��� ������ ��
// => OCP �� �����ϴ� ����(main �ּ� ����)
// => C++���� �����Լ��� ���� Ŭ������ "polymorphic type" �̶�� �մϴ�.


class Shape
{
	int color = 0;
public:
	virtual ~Shape() {}

	void set_color(int c) { color = c; }


	virtual int get_area() { return -1; }

	virtual void draw() { std::cout << "draw shape\n"; }
};



class Rect : public Shape
{
public:
	void draw() { std::cout << "draw rect\n"; }
};

class Circle : public Shape
{
public:
	void draw() { std::cout << "draw circle\n"; }
};

class Triangle : public Shape
{
public:
	void draw() { std::cout << "draw triangle\n"; }
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
				s->draw();	// ������ �Ѱ��� ������(ǥ����)
							// ��Ȳ(������ü�� ����)�� ���� �ٸ��� ����
							// ������(polymorphism) �̶�� �մϴ�.

							// Triangle Ŭ������ �߰��Ǿ 
							// �� �ڵ�� ������ �ʿ� �����ϴ�.
							// OCP �� �����ϴ� ���� ������ �Դϴ�.
							// "3.cpp" �ڵ��� if �� ���� ������

			// ��ü���� ����� 3�� Ư¡ : ĸ��ȭ(private), ���, ������
		}
	}
}

