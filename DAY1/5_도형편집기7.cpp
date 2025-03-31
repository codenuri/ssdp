#include <iostream>
#include <vector>

// #9. template method 패턴
// => 기반 클래스에 전체적인 변하지 않은 흐름을 담은 코드를 제공하고
// => 변해야 하는 부분만 가상함수로 분리해서
// => 파생 클래스가 override 할 기회를 제공한다.
// => 아래 예제에서 Shape::draw() 가 template method !!

class Shape
{
	int color = 0;
public:
	virtual ~Shape() {}

	void set_color(int c) { color = c; }


	virtual int get_area() { return -1; }

	// 공통성과 가변성의 분리
	// => 변하지 않은 코드 내부의 변해야 하는 부분은 분리되어야 한다.
	// => 변해야 하는 코드를 가상함수로 분리 한다.
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
			std::cout << "몇번째 도형을 복제 할까요 ?";

			int k;
			std::cin >> k;

			v.push_back(v[k]->clone()); 

		}
	}
}

