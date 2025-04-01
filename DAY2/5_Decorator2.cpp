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

// 상속을 사용한 기능의 추가 : 클래스에 기능 추가
// 포함을 사용한 기능의 추가 : 객체에   기능 추가

class Emoticon 
{
	Image* origin;	// 핵심 : 포인터 또는 참조 멤버, 값은 안됨
					// 의도 : 외부에 이미 생성된 객체를 가리키겠다는 것
public:
	Emoticon(Image* img) : origin(img) {}

	void draw()
	{
		std::cout << "$$$$$$$$$$$$$$$$$$$$$$$$$\n"; // 추가된 기능
		origin->draw();		// 원래 존재하던 객체의 기능
		std::cout << "$$$$$$$$$$$$$$$$$$$$$$$$$\n";
	}
};

int main()
{
	Image img("www.image.com/car.png");
	img.draw();


	Emoticon e(&img); // e 는 img 객체에 기능을 추가하는 객체
	e.draw();
}
