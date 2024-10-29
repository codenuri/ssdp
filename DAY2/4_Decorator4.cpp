// Decorator - 65 page
#include <iostream>



// 클래스와 
// 클래스에 "기능을 추가하는 클래스(Decorator)"
// 는 공통의 기반 클래스가 있어야
// "중첩된 기능추가" 가 가능하다.

struct IDraw
{
	virtual void draw() = 0;
	virtual ~IDraw() {}
};





// "스티커 사진" 클래스라고 생각해 보세요. 
class PhotoSticker : public IDraw
{
public:
	void take() { std::cout << "take Photo\n"; }
	void draw() { std::cout << "draw Photo\n"; }
};


class Emoticon : public IDraw
{
	IDraw* origin;	// 핵심!!
public:
	Emoticon(IDraw* ps) : origin(ps) {}

	void draw()
	{
		std::cout << "@@@@@@@@@@@@@@\n";
		origin->draw();

		std::cout << "@@@@@@@@@@@@@@\n";
	}
};

class Frame : public IDraw
{
	IDraw* origin;
public:
	Frame(IDraw* ps) : origin(ps) {}

	void draw()
	{
		std::cout << "##############\n";
		origin->draw();

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
}
