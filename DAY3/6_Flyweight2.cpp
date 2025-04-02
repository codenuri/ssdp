// 5_Flyweight - 167
#include <iostream>
#include <string>
#include <map>

class Image
{
	std::string image_url;

	Image(const std::string& url) : image_url(url)
	{
		std::cout << url << " Downloading..." << std::endl;
	}

public:
	void draw() { std::cout << "Draw " << image_url << std::endl; }

	// 자신의 객체를 만드는 static 멤버 함수
	static Image* create(const std::string& url)
	{
		Image* img = new Image(url);
		return img;
	}
};

int main()
{
	Image* img1 = Image::create("www.naver.com/a.png");
	img1->draw();

	Image* img2 = Image::create("www.naver.com/a.png");
	img2->draw();

}



