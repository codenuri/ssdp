// Decorator - 65 page
#include <iostream>

// "스티커 사진" 클래스라고 생각해 보세요. 
class PhotoSticker
{
public:
	void take() { std::cout << "take Photo\n"; }
	void draw() { std::cout << "draw Photo\n"; }
};

// 상속 : 객체가 아닌 클래스에 기능을 추가 한것
//	      실행시간(동적)으로 추가한것이 아닌 소스 작성(정적)시에 추가된것
class Emoticon : public PhotoSticker
{
public:
	void draw()
	{
		std::cout << "@@@@@@@@@@@@@@\n"; 
		PhotoSticker::draw();			 
		std::cout << "@@@@@@@@@@@@@@\n"; 
	}
};

int main()
{
	PhotoSticker ps;
	ps.take();	
	ps.draw();	

	Emoticon e;
	e.take();
	e.draw(); 
}
