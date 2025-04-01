// Decorator - 62 page
#include <iostream>
#include <string>
#include <thread>
#include <chrono>
using namespace std::literals;

// Image : 인터넷에서 그림을 다운로드후 화면에 그리는 클래스
class Image
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

class Emoticon
{
	Image* origin;	
public:
	Emoticon(Image* img) : origin(img) {}

	void draw()
	{
		std::cout << "$$$$$$$$$$$$$$$$$$$$$$$$$\n"; 
		origin->draw();		
		std::cout << "$$$$$$$$$$$$$$$$$$$$$$$$$\n";
	}
};

class Frame
{
	Image* origin;
public:
	Frame(Image* img) : origin(img) {}

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

	Emoticon e(&img); 
	e.draw();

	Frame f(&img);
	f.draw();

}
