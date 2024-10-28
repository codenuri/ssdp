#include <iostream>
#include <vector>


// 최종 버전
// => 코드 정리 & 생각해볼 문제


class unsupported_operation {};

class Shape
{
	int color = 0;

protected:
	Shape() {}

public:
	virtual ~Shape() {}

	void draw()
	{
		std::cout << "lock mutex\n";
		draw_imp();
		std::cout << "unlock mutex\n";

	}
	void set_color(int c) { color = c; }

protected:
	virtual void draw_imp() = 0;


public:
	virtual Shape* clone() { throw unsupported_operation(); }

	virtual int get_area() { return -1; }

};




class Rect : public Shape
{
public:
	void draw_imp() override { std::cout << "draw rect\n"; }

	Shape* clone()  override { return new Rect(*this); }
};

class Circle : public Shape
{
public:
	void draw_imp() override  { std::cout << "draw circle\n"; }

	Shape* clone() override  { return new Circle(*this); }
};

int main()
{
	std::vector<Shape*> v;

	while (1)
	{
		int cmd;
		std::cin >> cmd;

		// 생각해 볼 문제 #1. 객체의 생성을 OCP를 만족하게 할수 없을까 ?
		// => Triangle 을 추가되어도 아래 코드가 변경되지 않게!!
		// => 팩토리 패턴을 사용하면 됩니다. (목요일날 만들게 됩니다.)

		// 생각해 볼 문제 #2. Undo/Redo 기능을 추가하려면 어떻게 해야 할까 ?
		// => Command 패턴을 배우면 됩니다.
		// => Undo/Redo 할때 사용하는 패턴!!
		// => 목요일날 만들게 됩니다.

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
				e->draw(); // 다형성, OCP 만족
			}
		}
		else if (cmd == 8)
		{
			std::cout << "몇번째 도형을 복제 할까요 >> ";

			int k;
			std::cin >> k;

			v.push_back(v[k]->clone()); // 다형성, OCP 만족

		}
	}
}


