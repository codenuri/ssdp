#include <iostream>
#include <vector>

class NotImplemented : public std::exception {}; // 예외를 위한 클래스.
						// 멤버가 없이 이렇게만 만들어도 좋습니다.
						// 이름 자체를 설명을 하고 있습니다.

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

	// 가상함수     : 재정의하지 않으면 기본 구현을 제공하겠다는 의도!
	// 순수가상함수 : 반드시 재정의 해야 한다고, 강제로 시키는 것

protected:
	virtual void draw_imp() = 0;


public:
	// clone()도 순수 가상함수가 좋습니다. 
	// 그런데, 아래 처럼 하기도 합니다.(Python 등에서...)
	// 1. 재정의 안하고, 사용도 안하면 ok
	// 2. 재정의 안하고, 사용하면 예외 발생
	// 2. 재정의 하고,   사용하면 ok. 
	virtual Shape* clone()
	{
		throw NotImplemented();
	}

	// 아래 함수도 순수 가상함수도 좋지만
	// => 넓이를 구할수 없음(또는 구현 안됨) 을 의미 하는 -1을 반환
	//    하는 경우들도 있습니다.
	virtual int get_area() { return -1; }

};




class Rect : public Shape
{
public:
	virtual void draw_imp() override { std::cout << "draw Rect" << std::endl; }

	// 가상함수 재정의시 반환 타입변경가능합니다
	// => 단, 상속관계의 타입으로만!!
	virtual Rect* clone() override
	{
		return new Rect(*this);
	}
};

// Rect* p1 = new Rect;
// ?     p2 = p1->clone();
// p2를 Shape* 로 받는 것이 편리할까요 ?
//      Rect*  로 받는 것이 편리할까요 ?  => 편합니다. Rect 가 추가한 멤버접근가능
// 사용자 입장에서!!



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






