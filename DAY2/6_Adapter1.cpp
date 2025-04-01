#include <iostream>
#include <string>
#include <vector>

// 아래 클래스가 이미 있었다고 가정해 봅시다.
// => 문자열을 화면에 이쁘게 출력하는 클래스
class TextView
{
	std::string data;
	// font size, font name, italic, color, width, ...
public:
	TextView(const std::string& s) : data(s) {}

	void show() { std::cout << data << std::endl; }
};


//---------------------------------
class Shape
{
public:
	virtual void draw() = 0;
	virtual ~Shape() {}
};

class Rect : public Shape
{
public:
	void draw() override { std::cout << "draw rect" << std::endl; }
};
class Circle : public Shape
{
public:
	void draw() override { std::cout << "draw circle" << std::endl; }
};
// 도형편집기 예제에서 "문자열" 을 다루는 클래스가 필요합니다.
// 예전 부터 가지고 있던, "TextView" 클래스를 여기서 사용할수 있을까요 ?

// TextView 의 인터페이스를 도형편집기가 요구하는 형태로 변경한다.
class Text : public TextView, public Shape
{
public:
	Text(const std::string& s) : TextView(s) {}

	// 아래 코드가 어답터 패턴의 핵심
	// "show" 라는 함수 이름을 "draw" 라는 이름으로 변경한 코드
	void draw() override
	{
		TextView::show();
	}
};
int main()
{
	std::vector<Shape*> v;
	v.push_back(new Text("hello"));
	v[0]->draw();
}







