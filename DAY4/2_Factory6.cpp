#include <iostream>

// 아래 소스의 핵심
// => 객체를 만들기 위해 static 멤버 함수를 사용하고 있는것!!
// => java 에서 이기술을 "static factory method" 라고 합니다
// => 구글에서 "static factory method" 검색후 1번째 링크.
//    (복습할때 자세히 읽어 보세요)


class Color
{
public:
	Color(int r, int g, int b) {}

	static Color FromRgb(int r, int g, int b)
	{
		return Color(r, g, b);
	}
};

void fill(const Color& c) {}

// Color 객체를 생성하는 static 멤버 함수를 가진 클래스
// => C#, Java 진영에서 널리 사용하는 기술
class Colors
{
public:
	static Color& Red()
	{
		static Color c(255, 0, 0);
		return c;
	}

	static Color& Blue()
	{
		static Color c(0, 0, 255);
		return c;
	}

};

int main()
{
	// fill 함수에 빨간색 객체 전달해 보세요
	// #1. 객체를 생성해서 전달
	Color red(255, 0, 0);
	fill(red);

	// #2. 임시객체로 전달
	fill( Color(255, 0, 0) ); // 인자전달에만 사용하는 이름없는 객체
	fill( Color::FromRgb(255, 0, 0));

	fill( Colors::Red() ); // 이름이 있으므로 코드가 보다 명확하다.

	
}