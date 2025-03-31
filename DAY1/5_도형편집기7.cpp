#include <iostream>
#include <vector>

// #9. template method ����
// => ��� Ŭ������ ��ü���� ������ ���� �帧�� ���� �ڵ带 �����ϰ�
// => ���ؾ� �ϴ� �κи� �����Լ��� �и��ؼ�
// => �Ļ� Ŭ������ override �� ��ȸ�� �����Ѵ�.
// => �Ʒ� �������� Shape::draw() �� template method !!

class Shape
{
	int color = 0;
public:
	virtual ~Shape() {}

	void set_color(int c) { color = c; }


	virtual int get_area() { return -1; }

	// ���뼺�� �������� �и�
	// => ������ ���� �ڵ� ������ ���ؾ� �ϴ� �κ��� �и��Ǿ�� �Ѵ�.
	// => ���ؾ� �ϴ� �ڵ带 �����Լ��� �и� �Ѵ�.
protected:
	virtual void draw_imp()
	{
		std::cout << "draw shape\n";
	}

public:
	void draw() 
	{ 
		std::cout << "mutex lock\n";

		draw_imp();

		std::cout << "mutex unlock\n";
	}




	virtual Shape* clone() { return new Shape(*this); }
};



class Rect : public Shape
{
public:
	void draw_imp() override { std::cout << "draw rect\n"; }

	Shape* clone() override { return new Rect(*this); }
};

class Circle : public Shape
{
public:
	void draw_imp() override { std::cout << "draw circle\n"; }

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

			v.push_back(v[k]->clone()); 

		}
	}
}

