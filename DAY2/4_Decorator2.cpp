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

class Emoticon 
{
	PhotoSticker* origin; // 핵심 : 포인터 또는 참조 멤버(값타입 아님)
						  // 의미 : 이미 생성되어 있는 객체를 가리키겠다는 것
public:
	Emoticon(PhotoSticker* ps) : origin(ps) {}

	void draw()
	{
		std::cout << "@@@@@@@@@@@@@@\n"; 	
		origin->draw();

		std::cout << "@@@@@@@@@@@@@@\n"; 
	}
};




int main()
{
	PhotoSticker ps;
	ps.take();	
	ps.draw();	

	Emoticon e(&ps); // ps 라는 이미 생성된 객체에 
					 // 기능을 추가하는 e 객체

	e.draw();	// e가 추가한 기능을 사용하고
				// 다시 ps 의 기능을 사용
}
