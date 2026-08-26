#include <iostream>
#include <string>
#include <vector>

// 아래 클래스가 이미 있었다고 가정해 봅시다.

// TextView : 내부적으로 문자열을 보관하고 있다가 화면에 이쁘게 출력
class TextView
{
	// font이름, 크기, 색상등 다양한 정보 관리
	std::string data;
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

// 도형 편집기 에서 사용하기 위한 요구 조건
// => Shape 에서 상속 받아야 한다
// => draw() 가 있어야 한다

// TextView 를 도형편집기에서 사용가능하게 만들어 보자

class Text : public TextView, public Shape
{
public:
	Text(const std::string& s) : TextView(s) {}

	// 핵심 : 아래 코드가 show() 함수 이름을 draw() 함수 로 변경한것
	// => 사용자가 draw() 호출하면 결국 show() 기능 사용
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







