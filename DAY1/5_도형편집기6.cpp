#include <iostream>
#include <vector>



class Shape
{
	int color = 0;
public:
	virtual ~Shape() {}

	void set_color(int c) { color = c; }


	virtual int get_area() { return -1; }

	virtual void draw() { std::cout << "draw shape\n"; }

	// 자신의 복사본을 만드는 가상함수는 아주 유용하게 활용 됩니다.
	virtual Shape* clone() { return new Shape(*this); }
};



class Rect : public Shape
{
public:
	void draw() override  { std::cout << "draw rect\n"; }

	Shape* clone() override { return new Rect(*this); }
};

class Circle : public Shape
{
public:
	void draw() override { std::cout << "draw circle\n"; }

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

			// k번째 도형을 복제본을 만들어서 v에 추가합니다.
			// 어떻게 구현해야 할까요 ?
			// k번째 도형은 어떤 도형일까요 ?
			
			// 해결책 #1. 타입 조사 !!
			// => OCP 를 만족하지 못하는 나쁜 디자인..
			/*
			if (dynamic_cast<Rect*>(v[k]) != nullptr)
			{
				v.push_back(new Rect(*(static_cast<Rect*>(v[k])));
			}
			else if((dynamic_cast<Circle*>(v[k]) != nullptr)
			{
				v.push_back(new Circle((*(static_cast<Rect*>(v[k])));
			}
			*/

			// 해결책 #2. 다형성 활용 - 좋은 코드
			v.push_back(v[k]->clone()); // ok 다형성

			// java 진영에서는 위 기술을
			// "don't ask, do it" 이라고 합니다. 
			// 
			// 의미를 생각해 보세요
		}
	}
}

