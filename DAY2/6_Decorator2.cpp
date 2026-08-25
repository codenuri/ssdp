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

// 상속을 사용한 기능의 추가 : 클래스에 기능 추가
// 포함을 사용한 기능의 추가 : 객체에   기능 추가

class Emoticon
{
	Image* origin;  // 핵심 : 포인터 또는 참조 멤버
					// 의도 : 이미 생성된 객체를 가리키겠다는 것
public:
	Emoticon(Image* img) : origin(img) {}

	void draw()
	{
		std::cout << "#######################\n"; // 추가된 기능
		origin->draw();	// 원래 기능 사용
		std::cout << "#######################\n"; // 추가된 기능
	}
};

class Frame
{
	Image* origin; 
public:
	Frame(Image* img) : origin(img) {}

	void draw()
	{
		std::cout << "$$$$$$$$$$$$$$$$$$$$$$$\n"; // 추가된 기능
		origin->draw();	// 원래 기능 사용
		std::cout << "$$$$$$$$$$$$$$$$$$$$$$$\n"; // 추가된 기능
	}
};

int main()
{
	Image img("www.image.com/car.png");	
	img.draw();

	// 이미 그림은 다운 로드 했고, "img" 객체가 관리 합니다.

	// img.draw() : 그림만 출력

	// img 객체에 기능 추가 객체를 사용해서 기능을 추가 합니다.

	Emoticon e(&img);
	e.draw();

	Frame f(&img);
	f.draw();
}

