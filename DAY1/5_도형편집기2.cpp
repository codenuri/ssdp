#include <iostream>
#include <vector>

// #3. 아래 코드가 에러가 나오는 이유!!
// Shape* 인 s 로는 Shape 에서 파생된 멤버만 접근가능한데,
// Shape 에는 draw() 가없다.
// 해결책은 "다음 소스" 에서

class Shape
{
	int color = 0;
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

	while (true)
	{
		int cmd;
		std::cin >> cmd;

		if      (cmd == 1) v.push_back(new Rect);
		else if (cmd == 2) v.push_back(new Circle);
		else if (cmd == 9)
		{
			for (auto s : v) // 여기서 s의 타입은 Shape* 입니다.
				s->draw(); // error. Shape 에는 draw 가 없습니다.
		}
	}
}
// 위 코드는 어디에서 ? 왜 에러일까요 ?
// 해결책은 뭘까요 ?
