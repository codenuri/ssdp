// 1_Flyweight - 167
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
	void Draw() { std::cout << "Draw " << image_url << std::endl; }


	static std::map<std::string, Image*> image_map;

	// Image 객체를 만드는 static 멤버 함수
	static Image* Create(const std::string& url)
	{
		// #1. 이미 만든 객체가 있는지 조사
		auto it = image_map.find(url);

		// #2. 없는 경우만 생성
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
	Image* img1 = Image::Create("www.naver.com/a.png");
	img1->Draw();

	Image* img2 = Image::Create("www.naver.com/a.png");
	img2->Draw();

}



