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
//	Emoticon() {}  // Emoticon() : Image() {}

	// Image 에 디폴트 생성자가 없으므로 아래 처럼 해야 합니다.
	Emoticon(const std::string& url) : Image(url) {} 


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
	using Image::Image; // 생성자 상속 문법
						// Image 가 가진 모든 생성자를 물려 받게 된다
						// 즉, Emoticon 의 생성자와 유사한 역활
	void draw()
	{
		std::cout << "$$$$$$$$$$$$$$$$$$$$$$$\n"; // 추가된 기능
		Image::draw();	// 원래 기능
		std::cout << "$$$$$$$$$$$$$$$$$$$$$$$\n"; // 추가된 기능
	}
};

int main()
{
	Image img("www.image.com/car.png");	// Image : 클래스   img : 객체
	img.draw();

	Emoticon e("www.image.com/car.png");
	e.draw();

	Frame f("www.image.com/car.png");
	f.draw();
}

// 질문 #1. 위 코드는 
// 1. 객체에 대한 기능 추가  
// 2. 클래스에 대한 기능 추가 => 정답..
// => 상속은 객체가 아닌 클래스에 기능이 추가된다
// => 위 코드에서 이미 그림은 "img" 객체가 다운 받았다!!!
// => 다운 받은 "img" 객체에 기능이 추가된것은 아니다

// 질문 #2. Emoticon 과 Frame 의 추가 기능을 동시에 사용하려면 
// => 다시 파생  클래스 필요
// class FrameEmoticon : public Frame, public Emoticon {};   같은 형태


