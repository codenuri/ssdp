#include <iostream>
#include <string>
#include <vector>

// 아래 클래스가 이미 있었다가 가정해 봅시다.

// TextView : 문자열을 보관하고 있다가, 화면에 이쁘게 출력하는 기능
class TextView
{
	std::string data;
	// font name, size, color 등의 많은 멤버가 있다고 가능.

public:
	TextView(const std::string& s) : data(s) {}

	void show() { std::cout << data << std::endl; }
};







//=================================================
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

// 도형편집기 예제에 "문자열" 을 출력하는 클래스가 필요 하다.
// => 예전 부터 가지고 있던 "TextView" 를 여기서 사용할수 있을까요 ?
// => 안됩니다
// 1. 도형편집기는 "draw()"요구, TextView 는 "show()" 제공
// 2. 도형편집기는 "Shape" 로 부터 파생된 클래스만 사용가능. 
// => 인터페이스(함수이름)의 불일치 때문에 안됨. 

// Adapter 패턴
// => 기존 클래스의 인터페이스를 
//    시스템이 요구하는 형태로 변경해 주는 클래스를 만드는 패턴
// => "인터페이스의 불일치 해결"
// => "인터페이스(함수이름) 변경"

// 인터페이스의 불일치를 해결해 봅시다.
class Text : public TextView,	// TextView 의 모든 기능을 물려받고
			 public Shape       // 시스템(도형편집기)의 요구조건도 만족
{
public:
	Text(const std::string& data) : TextView(data) {}

	// 핵심 : show() => draw() 로 함수 이름을 변경하는 부분
	// "인터페이스의 불일치" 를 해결하는 코드
	void draw() override
	{
		TextView::show();
	}
};
int main()
{
	std::vector<Shape*> v;

//	v.push_back(new TextView("hello")); // error
	v.push_back(new Text("hello")); // ok
	v[0]->draw();
}







