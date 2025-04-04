// 메멘토 - 163
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

	// #1. 함수 인자로 전달하자
	// windows os 의 gdi+ 라이브러리
	g.DrawLine(0, 0, 100, 100, red, 10);
	g.DrawLine(0, 0, 100, 100, red, 10);


	// #2. Graphics 객체의 속성을 변경하는 방식으로 하자
	// => ios 의 cocoa touch 
	g.SetStrokeColor(red);
	g.SetStrokeWidth(10);

	g.DrawLine(0, 0, 100, 100);
	g.DrawLine(0, 0, 100, 100);
}









