#include <iostream>

class Color
{
public:
	Color(int r, int g, int b) {}
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
}