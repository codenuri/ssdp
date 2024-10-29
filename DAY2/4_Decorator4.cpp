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
	f.draw();	// 기능 추가된것을 사용

	ps.draw();	// 기능 추가전의 객체도 사용가능. 
}
/*
// 자주 나오는 질문
// => 아래처럼 "filter" 개념으로 하면 안되나요 ?
PhotoSticker ps;
ps.take();

ps.add_filter(new Emoticon);
ps.add_filter(new Frame);

ps.draw();  // 등록된 필터를 모두 출력하고
			// 촬영된 사진 출력
			 // emoticon.draw()
			 // frame.draw()
			 // ps.draw()
// 이 모델은 "원본 그림만 출력" 하는 기능이 없습니다.
// => 필터를 제거후에 그려야 합니다.

// decorator 는 기능 추가후에도 "원본 접근"을 허용하는 모델
*/