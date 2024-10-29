
#include <iostream>



struct IDraw
{
	virtual void draw() = 0;
	virtual ~IDraw() {}
};


class PhotoSticker : public IDraw
{
public:
	void take() { std::cout << "take Photo\n"; }
	void draw() { std::cout << "draw Photo\n"; }
};

// 기능추가 클래스(Decorator)들은 공통의 특징이 있을수 있습니다.
// 기반 클래스로 제공합니다.
class Decorator : public IDraw
{
	int x = 0;
	int y = 0;		// 기능(그림)을 추가할 위치
	IDraw* origin;	// 기능을 추가할 객체 포인터
public:
	Decorator(IDraw* d) : origin(d) {}

	void draw() { origin->draw(); }
};

class Emoticon : public Decorator
{
public:
	Emoticon(IDraw* ps) : Decorator(ps) {}

	void draw()
	{
		std::cout << "@@@@@@@@@@@@@@\n";
		Decorator::draw();
		std::cout << "@@@@@@@@@@@@@@\n";
	}
};

class Frame : public Decorator
{
public:
	Frame(IDraw* ps) : Decorator(ps) {}

	void draw()
	{
		std::cout << "##############\n";
		Decorator::draw();
		std::cout << "##############\n";
	}
};

int main()
{
	PhotoSticker ps;
	ps.take();

	ps.draw();

	Emoticon e(&ps);
	e.draw();

	Frame f(&e);
	f.draw();	

	ps.draw();	
}
