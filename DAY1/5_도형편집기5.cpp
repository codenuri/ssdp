#include <iostream>
#include <vector>

// #5. 다형성(Polymorphism) 이라는 용어!
// => 결국, 가상함수를 만들라는 것
// => OCP 를 만족하는 설계(main 주석 참고)
// => C++에서 가상함수를 가진 클래스를 "polymorphic type" 이라고 합니다.


class Shape
{
	int color = 0;
public:
	virtual ~Shape() {}

	void set_color(int c) { color = c; }


	virtual int get_area() { return -1; }

	virtual void draw() { std::cout << "draw shape\n"; }
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

class Triangle : public Shape
{
public:
	void draw() { std::cout << "draw triangle\n"; }
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
				s->draw();	// 동일한 한개의 문장이(표현식)
							// 상황(실제객체의 종류)에 따라 다르게 동작
							// 다형성(polymorphism) 이라고 합니다.

							// Triangle 클래스가 추가되어도 
							// 이 코드는 수정될 필요 없습니다.
							// OCP 를 만족하는 좋은 디자인 입니다.
							// "3.cpp" 코드의 if 와 비교해 보세요

			// 객체지향 언어의 3대 특징 : 캡슐화(private), 상속, 다형성
		}
	}
}

