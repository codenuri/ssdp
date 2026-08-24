#include <iostream>
#include <vector>

class Shape
{
public:
	virtual ~Shape() {}

	void draw()
	{
		std::cout << "mutex.lock\n";
		draw_imp();
		std::cout << "mutex.unlock\n";
	}

	virtual void draw_imp() = 0;
};

class Rect : public Shape
{
	int x = 0;
	int y = 0;
	int width = 0;
	int height = 0;
public:
	Rect(int x, int y, int w, int h) : x(x), y(y), width(w), height(h) {}

	void draw_imp() override { std::cout << "draw rect\n"; }
};

int main()
{
	Rect rc(1, 1, 10, 10);
	rc.draw();
}


