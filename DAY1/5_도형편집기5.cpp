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

			// 방법 #1. dynamic_cast로 조사하자.
			if (dynamic_cast<Rect*>(v[k]) != nullptr)
			{
				// 사각형이라고 생각해서 복사본생성
			}
			else if (dynamic_cast<Circle*>(v[k]) != nullptr)
			{
				// 원이라고 생각해서 복사본생성
			}

			// 위 코드는 OCP 만족할수 없다.
			// => Triangle 추가시 코드가 추가되어야 한다.
			// => 대부분의 경우 dynamic_cast 는 좋지 않은 디자인이 된다.
		}
	}
}


