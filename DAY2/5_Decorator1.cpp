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

	// 아래 코드는 이미 존재하는 "img" 객체에 기능을 추가하는 것이 아니다.!!
	// 기능(이모티콘그림)을 추가하기 위해 그림을 다시 download 하는 것 
	// 상속 : 객체가 아닌 클래스에 기능 추가한것
	//        우리가 원하는 것은 img 라는 이미 생성된 객체에 기능을 추가하는것
	//        다음예제에서.. 해결..
	Emoticon e("www.image.com/car.png");
	e.draw();
}
