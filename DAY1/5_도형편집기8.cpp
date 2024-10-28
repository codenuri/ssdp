#include <iostream>
#include <vector>

//예외로 사용하기 위한 타입
class unsupported_operation {};

class Shape
{
	int color;
public:
	virtual ~Shape() {}

	void draw()
	{
		std::cout << "lock mutex\n";
		draw_imp();
		std::cout << "unlock mutex\n";

	}

	void set_color(int c) { color = c; }

	// 가상 함수    : 파생 클래스가 override 하지 않으면 기본 구현제공한다는 의도
	// 순수 가상함수 :파생 클래스에 "반드시 만들라" 고 지시하는 것

protected:
	virtual void draw_imp() = 0;


public:
	// clone 의 경우도 "구현을 제공" 할수는 없습니다.
	// #1. 순수 가상함수로 해도 좋습니다.
	//    => 순수 가상함수가 많아지만, 파생클래스가 지켜야 하는 규칙이 많아집니다.
	// 
	// #2. 아래처럼 할수도 있습니다.
	//    => 기본 구현으로 예외 발생
	//    => C#, Python에서 널리 사용되는 디자인 기법

	// 1. 파생클래스에서 override 하지 않고, 사용도 하지 않으면 ok
	// 2. 파생클래스에서 override 하지 않고, 사용했다면, 예외 발생. runtime error
	// 3. 파생클래스에서 override 하고 사용하면 ok. 
	virtual Shape* clone() { throw unsupported_operation(); }



	// 아래 경우도
	// 1. 순수 가상함수도 나쁘지 않고
	// 2. 예외 던지는 기술도 가능
	// 3. 잘못된 값으로 약속된것을 리턴하는(C기술)도 널리 사용
	virtual int get_area() { return -1; }

};




class Rect : public Shape
{
public:
	void draw_imp() { std::cout << "draw rect\n"; }

	virtual Shape* clone() { return new Rect(*this); }
};

class Circle : public Shape
{
public:
	void draw_imp() { std::cout << "draw circle\n"; }

	virtual Shape* clone() { return new Circle(*this); }
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
				e->draw();
			}
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


