// Decorator - 65 page
#include <iostream>

// "스티커 사진" 클래스라고 생각해 보세요. 
class PhotoSticker
{
public:
	void take() { std::cout << "take Photo\n";}
	void draw()	{ std::cout << "draw Photo\n"; }
};

// 상속을 사용한 기능의 추가
class Emoticon : public PhotoSticker
{
public:
	void draw()
	{
		std::cout << "@@@@@@@@@@@@@@\n"; // 추가된 기능
		PhotoSticker::draw();			 // 원래 기능
		std::cout << "@@@@@@@@@@@@@@\n"; // 추가된 기능
	}
};

int main()
{
	PhotoSticker ps;
	ps.take();	// 사진 촬영
	ps.draw();	// 인쇄

	Emoticon e;
	e.take();
	e.draw(); // 사진 + 이모티콘 을 같이 출력
}
