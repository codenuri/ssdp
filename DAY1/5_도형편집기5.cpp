#include <iostream>
#include <vector>

class Shape
{
	int color;
public:
	virtual ~Shape() {}

	virtual void draw() { std::cout << "draw shape\n"; }

	void set_color(int c) { color = c; }

	virtual int get_area() { return 0; }
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

	while (1)
	{
		int cmd;
		std::cin >> cmd;

		if (cmd == 1)
		{
			v.push_back(new Rect);
		}
		else if (cmd == 2)
		{
			v.push_back(new Circle);
		}
		else if (cmd == 9)
		{
			for (auto e : v)
			{
				e->draw(); 
			}
		}

		else if (cmd == 8)
		{
			std::cout << "몇번째 도형을 복제 할까요 >> ";

			int k;
			std::cin >> k;

			// k번째 도형의 복사본을 생성해서 v에 추가합니다.
			// 어떻게 해야 할까요 ? k번째 도형은 어떤 타입일까요 ?
		}
	}
}


