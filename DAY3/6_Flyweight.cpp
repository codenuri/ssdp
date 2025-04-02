// 5_Flyweight - 167
#include <iostream>
#include <string>
#include <map>


// 속성이 동일한 객체는  공유 할수 있게 하자.

class Image
{
	std::string image_url;
public:
	Image(const std::string& url) : image_url(url)
	{
		std::cout << url << " Downloading..." << std::endl;
	}
	void draw() { std::cout << "Draw " << image_url << std::endl; }
};

int main()
{
	Image* img1 = new Image("www.naver.com/a.png");
	img1->draw();

	Image* img2 = new Image("www.naver.com/a.png");
	img2->draw();

}



