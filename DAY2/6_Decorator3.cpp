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


class Emoticon
{
	Image* origin;  
public:
	Emoticon(Image* img) : origin(img) {}

	void draw()
	{
		std::cout << "#######################\n"; 
		origin->draw();	
		std::cout << "#######################\n"; 
	}
};

class Frame
{
	Image* origin;
public:
	Frame(Image* img) : origin(img) {}

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

	Frame f(&e); // 어떻게 해야 할까 ?
				 // 해결책은 다음소스..
				 // => 항상 그림을 그려봐야 한다
	f.draw();		
}

