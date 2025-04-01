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


// 클래스 어답터 : 클래스의 인터페이스를 변경하는 도구
// 객체  어답터  : 객체의 인터페이스를 변경하는 도구

// Text : ? 어답터 
class Text : public TextView, public Shape
{
public:
	Text(const std::string& s) : TextView(s) {}

	void draw() override
	{
		TextView::show();
	}
};

// 아래 코드가 객체 어답터
class ObjectAdapter : public Shape
{
	TextView* origin;	// 핵심 : 포인터나 참조
						// 의도 : "이미 생성된 TextView 객체" 를 가리키 겠다는것
public:
	ObjectAdapter(TextView* p) : origin(p) {}

	void draw() override { origin->show();	}
};


int main()
{
	std::vector<Shape*> v;

	TextView tv("hello"); // TextView : 클래스
						  // tv       : 객체

	// 이미 생성된 "객체 tv" 를 도형편집기 시스템에 넣을수 있을까 ?
//	v.push_back(&tv); // error. tv 는 Shape 에서 상속되지 않았다.

	v.push_back( new ObjectAdapter(&tv) ); // ok.. 일치하지 않은 인터페이스를
										// 젠더(adapter)를 사용해서 연결

}







