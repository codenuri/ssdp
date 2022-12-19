#include <iostream>
#include <vector>


class Shape
{
public:
	virtual ~Shape() {}
};

class Rect : public Shape
{
public:
	void draw() { std::cout << "draw Rect" << std::endl; }
};
class Circle : public Shape
{
public:
	void draw() { std::cout << "draw Circle" << std::endl; }
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
		//	Rect rc;			// rc는 수명이 정해져 있습니다. {} 벗어날때..
			Rect* p = new Rect; // 원할때 까지 계속 사용하려면 이 방법이 유일합니다.
			v.push_back(p);
		}
		else if (cmd == 2)
		{
			v.push_back(new Circle);
		}
		else if (cmd == 9)
		{
			for (auto p : v)	// 여기서 p는 Shape* 입니다
				p->draw();		// error. 그런데, Shape 안에는 draw()가 없습니다.
		}
	}
}
// 왜 위 코드가 에러 일까요 ?
// 해결책은 뭘까요 ?
// 1. Shape* 타입인 p를 Rect* 나 Circle*로 캐스팅하자!!
// => 그런데, Rect인지 Circle 인지 알수 없다.
// => 물론, dynamic_cast로 조사 가능하지만 좋지 않다 => 이유는 다음 시간

// 2. Shape 에도 draw()를 넣자!! <==== 답!!!


