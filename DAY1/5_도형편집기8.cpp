#include <iostream>
#include <vector>

// 생각해볼 문제

class unsupported_operation {};

class Shape
{
	int color = 0;
public:
	virtual ~Shape() {}
	void set_color(int c) { color = c; }

	void draw()
	{
		std::cout << "mutex.lock\n";
		draw_imp();
		std::cout << "mutex.unlock\n";
	}
	virtual void draw_imp() = 0;

	virtual Shape* clone() { throw unsupported_operation(); }

	virtual int get_area() { return -1; }

};

class Rect : public Shape
{
public:
	void draw_imp() override { std::cout << "draw Rect\n"; }
	Shape* clone()  override { return new Rect(*this); }
};

class Circle : public Shape
{
public:
	void draw_imp() override { std::cout << "draw Circle\n"; }
	Shape* clone()  override { return new Circle(*this); }
};

int main()
{
	std::vector<Shape*> v;

	while (1)
	{
		int cmd;
		std::cin >> cmd;

		// #1. 객체의 생성을 OCP 를 만족하게 할수 없을까 ?
		//     => 새로운 도형이 추가되어도 아래 코드가 수정되지 않도록
		//	   => factory 패턴을 배우면 됩니다.(목요일 오전에 설명)

		// #2. Undo/Redo 기능을 추가하려면 어떻게 해야 할까 ?
		//	   => command 패턴을 배우면 됩니다(수요일 또는 목요일 설명)

		if (cmd == 1) v.push_back(new Rect);
		else if (cmd == 2) v.push_back(new Circle);
		else if (cmd == 9)
		{
			for (auto s : v)
			{
				s->draw(); // 다형성, OCP 만족, 새로운 도형 추가시 코드수정안됨
			}
		}

		else if (cmd == 8)
		{
			std::cout << "몇 번째 도형을 복제 할까요 >> ";
			int k;
			std::cin >> k;

			v.push_back(v[k]->clone()); // 다형성, OCP 만족, 새로운 도형 추가시 코드수정안됨

		}

		else if (cmd == -1) break;
	}

	for (auto s : v)
		delete s;
}






