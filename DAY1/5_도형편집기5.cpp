#include <iostream>
#include <vector>

// 핵심 #9. template method 디자인 패턴
// => 가장 널리 사용되고 중요한 패턴
// => 내일 부터 계속 등장 합니다.
// => 아래 draw() 함수
// => 모든 파생 클래스에 적용되는 공통의 작업 흐름을 제공하고
//    세부 구현을 가상함수화 해서, 파생 클래스가 변경할수 있게 한다



class Shape
{
	int color = 0;
public:
	virtual ~Shape() {}
	void set_color(int c) { color = c; }
	virtual int get_area() { return -1; }

	// 공통성과 가변성의 분리
	// => 변하지 않은 코드 내부에 "변해야 하는 부분" 이 있다면
	//    변해야 하는 것을 가상함수로 분리해라

	virtual void draw_imp()
	{
		std::cout << "draw Shape\n";
	}

	// 아래 함수는 모든 도형에 적용되는
	// => 그릴때 필요한 전체적인 작업의 순서를 표현하고 있습니다.
	// => "template method" 라고 합니다
	// => 실제 각 단계의 구체적인 작업은 가상함수로 분리해서
	// => 파생 클래스가 override 할 기회 제공
	void draw() 
	{ 
		std::cout << "mutex.lock\n";
		draw_imp();
		std::cout << "mutex.unlock\n";
	}






	virtual Shape* clone() { return new Shape(*this); }
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






