// 8_메멘토 - 178
#include <iostream>


// 화면에 그림을 그릴때 사용하는 클래스
class Graphics
{
	// 수백가지의 그리는 함수를 제공합니다.
};

int main()
{
	Graphics g;
	g.DrawLine(0, 0, 100, 100);

	// 선의 색상이나 두께 등을 변경하고 싶습니다.

	// 방법 1. DrawLine 함수 인자로 선의 속성 전달
	// => windows API gdi+ 방식
	g.DrawLine(0, 0, 100, 100, red, dash, 10);
	g.DrawLine(0, 0, 200, 200, blue, dash_dot, 20);

	// 방법 2. Graphics 객체의 속성을 변경하는 방식
	// => IOS 의 cocoa 라이브러리 방식
	g.SetStrokeColor(red);
	g.SetStrokeStyle(dash);
	g.SetStrokeWidth(10);

	g.DrawLine(0, 0, 100, 100);
	g.DrawLine(0, 0, 200, 200);
}









