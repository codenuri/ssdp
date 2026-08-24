#include <iostream>
#include <vector>


class Shape
{
	int color = 0;
public:
	virtual ~Shape() {} 
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

		if      (cmd == 1) v.push_back(new Rect);
		else if (cmd == 2) v.push_back(new Circle);
		else if (cmd == 9)
		{
			for (auto s : v)	// 여기서 s 의 타입은 Shape*
				s->draw();		// Shape 안에 draw()가 없으므로 
								// 이코드에서 에러!
		}
	}
}
// 위 코드는 에러 입니다.
// => 어디서, 왜 에러일까요 ?
// => 해결책을 생각해 보세요 => 다음 소스





