#include <iostream>
#include <vector>

// #1. 모든 파생 클래스의 공통의 특징은 반드시
//     기반 클래스에도 있어야 한다.
//     문법적인 규칙이 아닌 "디자인 규칙"!!

//     그래야 기반 클래스 포인터로 해당 기능을 사용할수 있다.

// #2. 기반 클래스가 가진 함수중에서
//	   파생 클래스가 override 하는 것은 반드시 virtual 이어야 한다.
//     (문법적 규칙이 아닌 디자인 규칙)

class Shape
{
	int color;
public:
	virtual ~Shape() {}

	virtual void draw() { std::cout << "draw shape\n"; }

	// 아래 함수는 virtual 할까요 ? non-virtual 로 할까요 ?

	// 파생클래스가 override 할이유 없다. - non-virtual
	// virtual 해도 되지만 virtual 은 "느리다."
	void set_color(int c) { color = c; }


	// 면적은 구하는 방법은 도형마다 다르다.
	// => 파생클래스가 override 하게 되므로 virtual 
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
				e->draw(); // 다형성(polymorphism)
						   // => 동일한 표현식이 상황(실제객체의 종류)에
						   //    따라 다르게 동작하는것

				// 객체지향 언어의 3대 특징 : 캡슐화, 상속, 다형성

				// 다형성의 장점
				// => 위 예제에 새로운 도형(Triangle)이 추가되어도
				// => "e->draw()" 는 변하지 않습니다.
				// => OCP 만족
			}
		}
	}
}


