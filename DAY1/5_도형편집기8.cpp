#include <iostream>
#include <vector>

// 예외 전용 클래스
class unsupported_operation {};

class Shape
{
	int color = 0;
public:
	virtual ~Shape() {}

	void set_color(int c) { color = c; }



	


public:
	void draw()
	{
		std::cout << "mutex lock\n";
		draw_imp();
		std::cout << "mutex unlock\n";
	}

	// 가상함수 : 파생 클래스가 override 하지 않으면 기본 구현 제공한다는 의미
	// 순수 가상함수 : 파생 클래스가 반드시 override 해서 구현 제공하라는 의미

protected:
	virtual void draw_imp() = 0;

public:
	// clone 의 경우
	// #1. 아래 처럼 만들어도 좋은 코드 이고!!
//	virtual Shape* clone() = 0;

	// #2. 아래 처럼 할수도 있습니다.(C#, Python 에서 널리 사용하는 기술)
	// => 기본 구현으로 예외 발생
	// => 의도!
	// 1. 파생 클래스가 override 한경우 사용하면 ok
	// 2. 파생 클래스가 override 하지 않았는데 사용하면 예외 발생
	// 3. 파생 클래스가 override 하지 않았는데 사용하지도 않으면 ok
	// => 즉, 사용할 도형만 override 해라!
	virtual Shape* clone() { throw unsupported_operation();  }

	// 아래 가상함수도
	// =>  =0 또는 기본 구현이 예외 전달로 해도 됩니다.
	// => 또는 C언어 처럼 잘못된 값을 반환하는 기본 구현을 사용하기도 합니다
	// => get_area()의 반환값이 -1 이면 면적 구할수 없다! 라고 매뉴얼로 작성
	virtual int get_area() { return -1; }
};



class Rect : public Shape
{
public:
	void draw_imp() override { std::cout << "draw rect\n"; }

	Shape* clone() override { return new Rect(*this); }
};

class Circle : public Shape
{
public:
	void draw_imp() override { std::cout << "draw circle\n"; }

	Shape* clone() override { return new Circle(*this); }
};

int main()
{
	std::vector<Shape*> v;

	while (true)
	{
		int cmd;
		std::cin >> cmd;

		// #1. 이 예제에 Undo/Redo 를 추가하려면 어떻게 해야 할까요 ?
		// => Command 패턴을 적용하면 됩니다. ( 내일 또는 목요일 )
		// 
		// #2. Triangle 추가시 아래 if 문은 변경(추가)되어야 합니다.
		// => 객체의 생성을 OCP 를 만족하게 할수 없을까요 ?
		// => factory 패턴을 사용하면 해결할수 있습니다(목요일에..)

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

			v.push_back(v[k]->clone());

		}
	}
}

