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

// 상속을 사용한 기능의 추가
class Emoticon : public Image
{
public:
	Emoticon(const std::string& url) : Image(url) {}

	void draw()
	{
		std::cout << "$$$$$$$$$$$$$$$$$$$$$$$$$\n"; // 추가된기능
		Image::draw();		// 원래 기능 사용
		std::cout << "$$$$$$$$$$$$$$$$$$$$$$$$$\n";
	}
};

int main()
{
	Image img("www.image.com/car.png");
	img.draw();

	Emoticon e("www.image.com/car.png");
	e.draw();
}
