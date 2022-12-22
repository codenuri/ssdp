#include <iostream>
#include <string>
#include <map>
#include "helper.h"

class Image
{
	std::string image_url;

	Image(const std::string& url) : image_url(url)
	{
		std::cout << url << " Downloading..." << std::endl;
	}
public:

	void Draw() { std::cout << "Draw " << image_url << std::endl; }

	// ImageFactory에서는 Image 를 만들수 있어야 한다.
	// private 접근 가능하도록 "friend" 연결

	friend class ImageFactory;
};


// 단일 책임의 원칙에 따라
// Image 는 그림을 다운로드해서 그리는 기능만을 가지게 하고
// Image 객체의 생성과 관리는 다른 클래스에서!!

class ImageFactory
{
	MAKE_SINGLETON(ImageFactory)

	std::map<std::string, Image*> image_map;
public:
	Image* Create(const std::string& url)
	{
		Image* img = nullptr;

		auto ret = image_map.find(url);

		if (ret == image_map.end())
		{
			img = new Image(url);

			image_map[url] = img;
		}
		else
		{
			img = ret->second;
		}
		return img;
	}
};










int main()
{
	ImageFactory& factory = ImageFactory::getInstance();

	Image* img1 = factory.Create("www.naver.com/a.png");
	img1->Draw();

	Image* img2 = factory.Create("www.naver.com/a.png");
	img2->Draw();
}




