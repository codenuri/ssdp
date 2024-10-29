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
// 상속 : 객체가 아닌 클래스에 기능을 추가 한것
//	      실행시간(동적)으로 추가한것이 아닌 소스 작성(정적)시에 추가된것
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

	// 위 코드는 
	// 1. 이미 촬영된 사진(객체)에 기능을 추가하는 것이 아니라
	// 2. 기능이 추가된 객체를 새로 만든것
	//    (이모티콘을 추가하기 위해 사진을 다시 촬영)
}
