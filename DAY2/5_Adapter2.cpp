#include <iostream>
#include <string>
#include <vector>

class TextView
{
	std::string data;
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

// 어답터의 종류
// 클래스 어답터 : 클래스의 인터페이스 변경
// 객체   어답터 : 객체의   인터페이스 변경

class Text : public TextView,	public Shape       
{
public:
	Text(const std::string& data) : TextView(data) {}

	void draw() override
	{
		TextView::show();
	}
};
int main()
{
	std::vector<Shape*> v;

	TextView tv("hello"); // TextView : 클래스(데이타 타입)
						  // tv        : 객체(변수)

	// 이미 생성된 객체 tv 를 v 에 넣을수 있을까요 ?
	v.push_back(&tv); // ???
}







