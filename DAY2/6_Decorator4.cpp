#include <iostream>
#include <string>
#include <thread>
#include <chrono>
using namespace std::literals;


// 핵심 기능 클래스인 "Image" 와
// 기능 추가 클래스의 공통의 인터페이스

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
		std::cout << "#######################\n";
		origin->draw();
		std::cout << "#######################\n";
	}
};

class Frame : public IDraw
{
	IDraw* origin;
public:
	Frame(IDraw* img) : origin(img) {}

	void draw()
	{
		std::cout << "$$$$$$$$$$$$$$$$$$$$$$$\n";
		origin->draw();
		std::cout << "$$$$$$$$$$$$$$$$$$$$$$$\n";
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

