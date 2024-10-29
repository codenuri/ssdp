// Decorator - 65 page
#include <iostream>

// "스티커 사진" 클래스라고 생각해 보세요. 
class PhotoSticker
{
public:
	void take() { std::cout << "take Photo\n"; }
	void draw() { std::cout << "draw Photo\n"; }
};


class Emoticon
{
	PhotoSticker* origin; 
public:
	Emoticon(PhotoSticker* ps) : origin(ps) {}

	void draw()
	{
		std::cout << "@@@@@@@@@@@@@@\n";
		origin->draw();

		std::cout << "@@@@@@@@@@@@@@\n";
	}
};

// 액자 그림 기능을 추가하는 클래스
class Frame
{
	PhotoSticker* origin;
public:
	Frame(PhotoSticker* ps) : origin(ps) {}

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

//	Frame f(&ps);
	Frame f(&e); // 기능의 중첩
				 // 현재 코드는 에러!!!
				 // 해결은 "다음소스에서"
				 
	f.draw();
}
