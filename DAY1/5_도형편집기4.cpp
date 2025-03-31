#include <iostream>
#include <vector>

// #3-2. 해결책 2. 다형성 활용

// => 모든 도형(파생 클래스)의 공통의 특징은 반드시 Shape 에도 있어야 한다.
//    문법적인 제약이 아닌 디자인 원칙
//    그래야만, Shape* 로 해당 특징을 사용할수 있다.

// #4. 기반 클래스 함수중에서 파생 클래스가 override 하는 것은
//     가상함수로 만들어야 한다.

class Shape
{
	int color = 0;
public:
	virtual ~Shape() {}

	// 아래 함수는 가상으로 할까요? 비가상으로 할까요 ?
	// => 파생 클래스가 override 할 이유 없습니다.
	// => non-virtual
	void set_color(int c) { color = c; }

	// => 아래 함수는 파생 클래스가 override 하게 됩니다.
	// => 면적을 구하는 것은 각 도형이 다르므로!!
	// => virtual 이어야 합니다.
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
	}
}

