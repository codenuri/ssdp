#include <iostream>
#include <vector>

// 핵심 #3. 모든 도형의 공통의 특징(draw)이 있다면 기반 클래스에도 있어야 한다
// => 그래야 기반 클래스(Shape*) 타입으로 해당 특징을 사용할수 있다
// => 문법적인 규칙이 아닌 디자인 규칙

// 핵심 #4. 기반 클래스 멤버 함수 설계시
// => 파생 클래스가 override 하게 되는 것은 "가상함수로 만들어야 한다"

class Shape
{
	int color = 0;
public:
	virtual ~Shape() {}

	// 아래 함수는 virtual 로 할까요 ? non-virtual 할까요 ?
	// => 파생 클래스가 override 할 필요 없습니다 - non-virtual
	// => virtual 로 해도 되지만 "테이블을 사용하고, 호출시 오버헤드"가 있는
	//   것을 사용할 필요 없습니다.
	void set_color(int c) { color = c;  }

	// 아래 함수는 ?
	// => 모든 도형의 면적 구하는 방법은 다릅니다.
	// => 파생 클래스가 override 해야 합니다.
	// => virtual
	// => 이때 Shape 에 이 함수가 없으면 "Shape*" 로 호출 안됩니다.
	//    모든 도형의 공통의 특징이므로 Shape 에도 만들고
	//    모든 파생 클래스에서 다시 만들도록 해야 합니다.
	virtual int get_area() { return -1; }

	virtual void draw() { std::cout << "draw Shape\n"; }
};



class Rect : public Shape
{
public:
	void draw() { std::cout << "draw Rect\n"; }
};

class Circle : public Shape
{
public:
	void draw() { std::cout << "draw Circle\n"; }
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
				s->draw();		

		}
	}
}






