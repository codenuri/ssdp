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
	
	inline static std::map<std::string, Image*> image_map;

	// 핵심 : 자신의 객체를 만드는 static 멤버 함수 - 너무나 유명한 기술입니다.
	static Image* create(const std::string& url)
	{
		Image* img = nullptr;

		// map 에서 먼저 객체가 있는지 검색
		auto it = image_map.find(url);

		if (it != image_map.end())
		{
			img = it->second;   // map 의 반복자는 key, value 이므로
								// second 가 Image* 입니다
		}
		else
		{							
			img = new Image(url);	// 검색 실패시 새롭게 생성후
			image_map[url] = img;	// map 에 보관
		}

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



