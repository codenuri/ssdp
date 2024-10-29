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

// 인터페이스의 불일치를 해결해 봅시다.
class Text : public TextView
{

};

int main()
{
	std::vector<Shape*> v;
}







