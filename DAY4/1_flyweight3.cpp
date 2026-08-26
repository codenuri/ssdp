// 5_Flyweight - 167
#include <iostream>
#include <string>
#include <map>
#include "singleton.h"


class Image
{
	std::string image_url;

	Image(const std::string& url) : image_url(url)
	{
		std::cout << url << " Downloading..." << std::endl;
	}

public:
	void draw() { std::cout << "Draw " << image_url << std::endl; }

	// friend 함수  : 함수 안에서 Image 의 private 멤버 접근 허용
	// friend class : class의 모든 멤버 안에서 Image 의 private 멤버 접근 허용
	friend class ImageFactory;
};

// SRP ( Single Responsibility Principle )
// => 단일 책임의 원칙
// => 하나의 클래스는 하나의 책임만 가져야 한다

// Image        : 그림을 다운로드해서 그리는 역활
// ImageFactory : Image 객체의 생성과 공유를 담당

class ImageFactory
{
	std::map<std::string, Image*> image_map;
public:
	Image* create(const std::string& url)
	{
		Image* img = nullptr;
		auto it = image_map.find(url);
		if (it != image_map.end())
		{
			img = it->second;
		}
		else
		{
			img = new Image(url);
			image_map[url] = img;
		}
		return img;
	}

};



int main()
{
	// 공장을 먼저 짓고
	ImageFactory factory;

	// 공장을 통해서 Image 를 생성한다
	Image* img1 = factory.create("www.naver.com/a.png");
	img1->draw();

	Image* img2 = factory.create("www.naver.com/a.png");
	img2->draw();

	std::cout << img1 << std::endl;
	std::cout << img2 << std::endl;

}



