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

	// 자신의 객체를 만드는 static 멤버 함수
	static Image* Create(const std::string& url)
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
			img = ret->second; // map 의 반복자는 pair 의 포인터
		}

		return img;
	}
};
std::map<std::string, Image*> Image::image_map;




int main()
{
	// IOS 개발시 사용되는 "cocoa" 라이브러리가
	// "UImage" 객체 생성시 "static 멤버함수"를 사용하도록 되어 있습니다
	// => 동일 그림을 공유하게 됩니다.
	Image* img1 = Image::Create("www.naver.com/a.png");
	img1->Draw();

	Image* img2 = Image::Create("www.naver.com/a.png");
	img2->Draw();
}

// 참고 : map 에서 키값 유무 조사시 아래처럼 하지 마세요
// if ( image_map[url] == nullptr )

// 아래 처럼해야 합니다.
// auto ret = image_map.find(url);
// if ( ret == image_map.end()) {}

// C++20 부터는 아래 처럼 가능합니다. - contain() 멤버 함수 추가됐습니다.
// if ( image_map.contain(url) ) {}



