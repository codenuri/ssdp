#include <iostream>
#include <vector>

class unsupported_operation {};

class Shape
{
	int color = 0;
public:
	virtual ~Shape() {}
	void set_color(int c) { color = c; }

	void draw()
	{
		std::cout << "mutex.lock\n";
		draw_imp();
		std::cout << "mutex.unlock\n";
	}

	// 가상함수 : 파생클래스가 구현을 만들지 않으면 기본 구현을 제공하겠다는 것
	//			  => 반드시 다시 만들 필요 없다
	// 
	// 순수 가상함수 : 파생 클래스에게 반드시 만들라고 지시 하는 것
	//			  => 반드시 만들어야 한다

//	virtual void draw_imp() { std::cout << "draw Shape\n";} // 이 코드 보다
	virtual void draw_imp() = 0;		// 이 코드가 현재 예제에서는 좋다


	// clone 구현 방법
	// #1. 아래 처럼 반드시 만들라고 시켜도 되고
	// => 순수 가상함수가 많아지면 파생 클래스 설계자가 해야할 일이 많아진다
	//    (하지만 나쁜 것은 아니다.. 코딩이 많을뿐 나쁜 디자인은 절대 아님)
	// virtual Shape* clone() = 0;


	// #2. 예외 발생 버전도 가능
	// => 파생 클래스가 override 하지 않고, 사용도 하지 않으면 - ok
	// => 파생 클래스가 override 하지 않고, 사용하면 - exception 발생
	// => 파생 클래스가 override 하고,     사용하면 - ok. 

	virtual Shape* clone() { throw unsupported_operation(); }


	// get_area() 구현
	// 1. =0 으로 해서 파생 클래스가 반드시 만들게 해도 되고
	// 2. 기본 구현을 예외 발생 버전 으로 해도 되고
	// 3. C 언어 스타일로, 기본 구현은 면적 없음을 의미하는 값 반환후
	//    도움말 등으로 설명
	virtual int get_area() { return -1; }

};






class Rect : public Shape
{
public:
	void draw_imp() { std::cout << "draw Rect\n"; }
	Shape* clone() { return new Rect(*this); }
};

class Circle : public Shape
{
public:
	void draw_imp() { std::cout << "draw Circle\n"; }
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

			v.push_back(v[k]->clone());

		}

	}
}






