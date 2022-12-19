#include <iostream>
#include <vector>


// 3. 모든 도형의 공통의 특징(draw) 는 반드시 기반 클래스(Shape)
//    에도 있어야 합니다.
//    => 그래야, Shape* 로 모든 도형을 같이 보관했을때 
//       해당 특징을 사용가능합니다.
//    => 문법적 제약이 아닌 디자인 관점

// 4. 기반 클래스 멤버 함수중 파생 클래스가 재정의 하기 되는 것은
//    반드시 가상함수로 설계 되어야 합니다.


class Shape
{
	int color;	// 모든 도형은 색상도 있다
public:
	virtual ~Shape() {}

	// 아래 함수들은 파생 클래스가 재정의 할 필요 없습니다.
	// => virtual 로 할 필요 없습니다.
	int  get_color()      { return color; }
	void set_color(int c) { color = c; }

	// 도형의 면적을 구하는 방법은 도형 마다 다릅니다.
	// => 파생클래스가 재정의하게 됩니다.
	// => virtual 이어야 합니다.
	virtual int get_area() { return -1; }


	virtual void draw() { std::cout << "draw Shape" << std::endl; }
};




class Rect : public Shape
{
public:
	virtual void draw() override { std::cout << "draw Rect" << std::endl; }
};
class Circle : public Shape
{
public:
	virtual void draw() override { std::cout << "draw Circle" << std::endl; }
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
	}
}
