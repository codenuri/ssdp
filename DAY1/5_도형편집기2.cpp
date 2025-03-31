#include <iostream>
#include <vector>

// #3. �Ʒ� �ڵ尡 ������ ������ ����!!
// Shape* �� s �δ� Shape ���� �Ļ��� ����� ���ٰ����ѵ�,
// Shape ���� draw() ������.
// �ذ�å�� "���� �ҽ�" ����

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
			for (auto s : v) // ���⼭ s�� Ÿ���� Shape* �Դϴ�.
				s->draw(); // error. Shape ���� draw �� �����ϴ�.
		}
	}
}
// �� �ڵ�� ��𿡼� ? �� �����ϱ�� ?
// �ذ�å�� ����� ?
