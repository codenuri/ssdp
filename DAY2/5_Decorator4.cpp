#include <iostream>
#include <string>
#include <thread>
#include <chrono>
using namespace std::literals;

// Image 와 Image 에 기능을 추가하는 클래스(데코레이터)
// 는 공통의 기반 클래스(인터페이스)가 필요하다.

struct IDraw
{
	virtual void draw() = 0;
	virtual ~IDraw() {}
};


class Image : public IDraw
{
	std::string url;
public:
	Image(const std::string& url) : url(url)
	{
		std::cout << "downloading... " << url << std::endl;
		std::this_thread::sleep_for(3s);
	}

	void draw()
	{
		std::cout << "draw " << url << std::endl;
	}
};

class Emoticon : public IDraw
{
	IDraw* origin;
public:
	Emoticon(IDraw* img) : origin(img) {}

	void draw()
	{
		std::cout << "$$$$$$$$$$$$$$$$$$$$$$$$$\n";
		origin->draw();
		std::cout << "$$$$$$$$$$$$$$$$$$$$$$$$$\n";
	}
};

class Frame : public IDraw
{
	IDraw* origin;
public:
	Frame(IDraw* img) : origin(img) {}

	void draw()
	{
		std::cout << "#########################\n";
		origin->draw();
		std::cout << "#########################\n";
	}
};
int main()
{
	Image img("www.image.com/car.png");
	img.draw();

	Emoticon e(&img);	// 기능 추가
	e.draw();

	Frame f(&e);		// 추가된 기능에 다시 기능 추가
	f.draw();	// 기능 추가된것 실행
	img.draw();	// 기능 추가되기전의 구현실행
				// 즉, 원본에 대한 접근이 허용된다.

	// 자주 나오는 질문.. 아래 처럼 하면 안되나요?
	/*
	img.add_filter(new Emoticon);
	img.add_filter(new Frame);
	
	img.draw(); // 등록된 필터의 모든 draw() 호출후
				// 자신의 draw() 실행
	// 위 모델은 필터 적용되기 전의 원본그림에 접근할수 없습니다.
	// 하지만 decorator 패턴은 원본 접근이 됩니다.
	*/
}
