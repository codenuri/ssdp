#include <iostream>
#include <vector>

// 핵심 #5. 다형성(Polymorphism)
// => OCP 를 만족하는 좋은 코딩 스타일


// 핵심 #6. 아래 "리팩토링 용어" 를 이해해 보세요
// 
// => "Replace Conditional With Polymorphism"
//    "제어문(if, switch)이 많다면 다형성(가상함수) 로 변경하는 것을 고려하라"






class Shape
{
	int color = 0;
public:
	virtual ~Shape() {}

	void set_color(int c) { color = c; }

	virtual int get_area() { return -1; }

	virtual void draw() { std::cout << "draw Shape\n"; }
};



class Rect : public Shape
{
public:
	void draw() { std::cout << "draw Rect\n"; }
};

class Circle : public Shape
{
public:
	void draw() { std::cout << "draw Circle\n"; }
};
class Triangle : public Shape
{
public:
	void draw() { std::cout << "draw Triangle\n"; }
};
int main()
{
	std::vector<Shape*> v;

	while (1)
	{
		int cmd;
		std::cin >> cmd;

		if (cmd == 1) v.push_back(new Rect);
		else if (cmd == 2) v.push_back(new Circle);
		else if (cmd == 9)
		{
			for (auto s : v)
			{
				s->draw(); // 다형성(Polymorphism)
							// => 동일한 하나의 표현식이
							//    상황(실제 객체가 무엇인가?)에 따라 다르게 동작하는 것

				// 객체지향의 3대 특징 : 캡슐화, 상속, 다형성
			}

		}
	}
}






