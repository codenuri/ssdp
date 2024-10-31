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

	friend class ImageFactory;	// ImageFactory 클래스에서는
								// Image private 접근 가능하게

};

// Image 는 그림 다운로드와 출력 의 기능만 가지고
// Image 의 생성/공유는 다른 클래스로. 공장 도입

class ImageFactory
{
	MAKE_SINGLETON(ImageFactory)

	std::map<std::string, Image*> image_map;

public:
	Image* Create(const std::string& url)
	{
		auto it = image_map.find(url);

		if (it == image_map.end())
		{
			Image* img = new Image(url);
			image_map[url] = img;
			return img;
		}
		return it->second;
	}
};


int main()
{
	ImageFactory& factory = ImageFactory::get_instance();

	Image* img1 = factory.Create("www.naver.com/a.png");
	img1->Draw();

	Image* img2 = factory.Create("www.naver.com/a.png");
	img2->Draw();

}



