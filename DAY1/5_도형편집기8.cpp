#include <iostream>
#include <vector>

class NotImplemented : public std::exception {};

class Shape
{
	int color;
public:
	virtual ~Shape() {}

	int  get_color() { return color; }
	void set_color(int c) { color = c; }



public:
	void draw()
	{
		std::cout << "mutex lock" << std::endl;
		std::cout << "graphic 객체 설정" << std::endl;

		draw_imp();
		std::cout << "mutex unlock" << std::endl;
	}


protected:
	virtual void draw_imp() = 0;


public:
	virtual Shape* clone()
	{
		throw NotImplemented();
	}


	virtual int get_area() { return -1; }

};




class Rect : public Shape
{
public:
	virtual void draw_imp() override { std::cout << "draw Rect" << std::endl; }

	virtual Rect* clone() override
	{
		return new Rect(*this);
	}
};


class Circle : public Shape
{
public:
	virtual void draw_imp() override { std::cout << "draw Circle" << std::endl; }

	virtual Circle* clone() override
	{
		return new Circle(*this);
	}
};



int main()
{
	std::vector<Shape*> v;

	while (1)
	{
		int cmd;
		std::cin >> cmd;

		// 생각해 볼 문제

		// 1. 객체의 생성 과정을 OCP 를 만족하도록 할수 없을까?
		// => 새로운 도형이 추가되어도 아래 코드가 수정(추가)되지 않도록!!
		// => 추상 팩토리 패턴을 사용하면 됩니다(목요일날 배우게 됩니다.)

		// 2. Undo/Redo 기능을 넣으려면 어떻게 해야 할까 ??
		// => Command 패턴을 알면 됩니다.
		// => 목요일에 직접 구현합니다.

		if (cmd == 1)       v.push_back(new Rect);
		else if (cmd == 2)	v.push_back(new Circle);

		else if (cmd == 9)
		{
			for (auto p : v)
				p->draw();
		}
		else if (cmd == 8)
		{
			std::cout << "몇번째 도형을 복제 할까요 >> ";

			int k;
			std::cin >> k;

			v.push_back(v[k]->clone());

		}
	}
}






