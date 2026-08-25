#include <iostream>
#include <string>
#include <thread>
#include <chrono>
using namespace std::literals;

// Decorator - 62 page
// 2개의 예제
// 1번 : 좋은 예제 아니지만 쉽다
// 2번 : 좋은 예제 약간 어려움

// Image : 인터넷에서 그림 다운로드후 화면에 출력하는 클래스
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
	void draw()
	{
		std::cout << "#######################\n"; // 추가된 기능
		Image::draw();	// 원래 기능
		std::cout << "#######################\n"; // 추가된 기능
	}
};

class Frame : public Image
{
public:
	void draw()
	{
		std::cout << "$$$$$$$$$$$$$$$$$$$$$$$\n"; // 추가된 기능
		Image::draw();	// 원래 기능
		std::cout << "$$$$$$$$$$$$$$$$$$$$$$$\n"; // 추가된 기능
	}
};

int main()
{
	Image img("www.image.com/car.png");
	img.draw();

	Emoticon e;
	e.draw();
	Frame f;
	f.draw();
}



