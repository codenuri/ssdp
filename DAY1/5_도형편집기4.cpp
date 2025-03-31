#include <iostream>
#include <vector>

// #3-2. �ذ�å 2. ������ Ȱ��

// => ��� ����(�Ļ� Ŭ����)�� ������ Ư¡�� �ݵ�� Shape ���� �־�� �Ѵ�.
//    �������� ������ �ƴ� ������ ��Ģ

class Shape
{
	int color = 0;
public:
	virtual ~Shape() {}

	void draw() { std::cout << "draw shape\n"; }
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
	}
}

