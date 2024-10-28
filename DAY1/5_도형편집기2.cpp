// 15page ~ 
#include <iostream>
#include <vector>

class Shape
{
	int color;
public:
	virtual ~Shape() {}
};

class Rect : public Shape
{
public:
	void draw() { std::cout << "draw rect\n"; }
};

class Circle : public Shape
{
public:
	void draw() { std::cout << "draw circle\n"; }
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
//			Rect rc;	// 이렇게 만들면 {} 벗어날때 즉시 파괴 됩니다.
			Rect* p = new Rect; // 계속 사용하려면 이렇게 해야 합니다.
			v.push_back(p);
		}
		else if (cmd == 2)
		{
			v.push_back(new Circle); 
		}
		else if (cmd == 9)
		{
			for (auto e : v)
				e->draw();	// A. error.
		}
	}
}

// 왜 A 부분이 에러일까요 ?
// => 실제 객체는 Rect, Circle 이지만
// => v 에는 Shape* 타입으로 보관
// => Shape 에는 draw 가 없다. 그래서 에러
// 
// 해결책은 뭘까요 ?
// => 다음소스에서
