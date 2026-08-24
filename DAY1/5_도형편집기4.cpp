#include <iostream>
#include <vector>




class Shape
{
	int color = 0;
public:
	virtual ~Shape() {}

	void set_color(int c) { color = c; }
	virtual int get_area() { return -1; }
	virtual void draw() { std::cout << "draw Shape\n"; }

	virtual Shape* clone() { return new Shape(*this); }
};

class Rect : public Shape
{
public:
	void draw() { std::cout << "draw Rect\n"; }
	Shape* clone() { return new Rect(*this); }
};

class Circle : public Shape
{
public:
	void draw() { std::cout << "draw Circle\n"; }
	Shape* clone() { return new Circle(*this); }
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
				s->draw(); 
			}
		}

		else if (cmd == 8)
		{
			std::cout << "몇 번째 도형을 복제 할까요 >> ";
			int k;
			std::cin >> k;

			// k 번째 만든 도형을 복사한 새로운 도형을 만들어서 v에 추가
			// => 어떻게 구현해야 할까요 ?
			// => k 번째 도형은 어떤 도형일까요 ?

			// 방법 #1. k 번째 도형인 어떤 종류인지 조사하자
			// => OCP 을 만족할수 없는 좋지 않은 디자인
			/*
			if (Rect* r = dynamic_cast<Rect*>(v[k]); r != nullptr)
			{
				v.push_back(new Rect(*r));
			}
			else if (Circle* c = dynamic_cast<Circle*>(v[k]); c != nullptr)
			{
				v.push_back(new Circle(*c));
			}
			*/

			// 방법 #2. 다형성 활용
			// => Don't ask Do It(물어보지(조사하지) 말고 시켜라
			// => k 번째 도형을 조사할 필요 없다.
			// => 그냥, 해당 객체에게 "복사본 좀 만들어줘" 라고 시켜라!
			v.push_back(v[k]->clone());

		}

	}
}






