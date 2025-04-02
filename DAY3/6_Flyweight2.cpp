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

	// inline static : C++17 부터 도입된 문법
	//				   static 멤버 데이타 만들때 외부 선언 필요 없음. 
	//				   VS 옵션에서 언어버전 C++17 로.. 
	//				   프로젝트메뉴 => 속성메뉴 =>C++ 언어 버전
	inline static std::map<std::string, Image*> image_map;


	// 자신의 객체를 만드는 static 멤버 함수
	static Image* create(const std::string& url)
	{
		Image* img = nullptr;

		auto it = image_map.find(url);

		if (it == image_map.end())   // C++20 image_map.contain(url)
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
	// IOS 라이브러리인 cocoa touch 의 UIImage 클래스가 아래처럼 사용합니다.
	Image* img1 = Image::create("www.naver.com/a.png");
	img1->draw();

	Image* img2 = Image::create("www.naver.com/a.png");
	img2->draw();

}



