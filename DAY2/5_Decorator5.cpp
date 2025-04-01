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

// 기능추가 클래스(Decorator)는 공통의 특징이 있을수 있습니다.
// 기반 클래스로 제공합니다.
class Decorator : public IDraw
{
	int x, y;
	IDraw* origin;
public:
	Decorator(IDraw* img) : origin(img) {}

	void draw() { origin->draw(); }
};

class Emoticon : public Decorator
{
public:
	Emoticon(IDraw* img) : Decorator(img) {}

	void draw()
	{
		std::cout << "$$$$$$$$$$$$$$$$$$$$$$$$$\n";
		Decorator::draw();
		std::cout << "$$$$$$$$$$$$$$$$$$$$$$$$$\n";
	}
};

class Frame : public Decorator
{
public:
	Frame(IDraw* img) : Decorator(img) {}

	void draw()
	{
		std::cout << "#########################\n";
		Decorator::draw();
		std::cout << "#########################\n";
	}
};
int main()
{
	Image img("www.image.com/car.png");
	img.draw();

	Emoticon e(&img);
	e.draw();

	Frame f(&e);	
	f.draw();	

}
