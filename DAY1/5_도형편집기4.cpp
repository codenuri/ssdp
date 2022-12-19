#include <iostream>
#include <vector>

// 5. 다형성
// => 동일한 표현식이 상황에 따라(실제 객체) 다르게 동작하는것
// => OCP 를 만족하는 아주 좋은 코딩 스타일!!
// => 항상 다형성을 많이 사용하세요!!

class Shape
{
	int color;	
public:
	virtual ~Shape() {}

	int  get_color() { return color; }
	void set_color(int c) { color = c; }

	virtual int get_area() { return -1; }


	virtual void draw() { std::cout << "draw Shape" << std::endl; }
};




class Rect : public Shape
{
public:
	virtual void draw() override { std::cout << "draw Rect" << std::endl; }
};
class Circle : public Shape
{
public:
	virtual void draw() override { std::cout << "draw Circle" << std::endl; }
};

class Triangle : public Shape
{
public:
	virtual void draw() override { std::cout << "draw Triangle" << std::endl; }
};

int main()
{
	std::vector<Shape*> v;

	while (1)
	{
		int cmd;
		std::cin >> cmd;

		if (cmd == 1)       v.push_back(new Rect);
		else if (cmd == 2)	v.push_back(new Circle);

		else if (cmd == 9)
		{
			for (auto p : v)
				p->draw();	// 다형성(Polymorphism)
							// => 동일한 표현식이 상황에 따라(실제 객체)
							//    다르게 동작하는 것

			// 객체지향 언어특징 : 캡슐화, 상속, 다형성
		}
	}
}
