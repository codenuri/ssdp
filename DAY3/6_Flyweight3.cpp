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

	friend class ImageFactory;
				// ImageFactory 클래스는 친구 이므로
				// Image 클래스 private 접근 가능하게 해달라.
};

// SRP 원칙에 따라
// Image : 그림을 다운해서 그리는 기능만
// ImageFactory : Image 객체의 생성과 공유를 책임지도록

class ImageFactory
{
	std::map<std::string, Image*> image_map;
public:
	Image* create(const std::string& url)
	{
		Image* img = nullptr;

		auto it = image_map.find(url);

		if (it == image_map.end())
		{
			img = new Image(url);
			image_map[url] = img;
		}
		else
		{
			img = it->second;
		}
		return img;
	}

};

int main()
{
	ImageFactory factory;

	Image* img1 = factory.create("www.naver.com/a.png");
	img1->draw();

	Image* img2 = factory.create("www.naver.com/a.png");
	img2->draw();

}



