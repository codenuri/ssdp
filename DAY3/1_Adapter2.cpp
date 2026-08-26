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

// Adapter 의 종류
// 1. class  Adapter : 클래스의 인터페이스를 변경
// 2. object Adapter : 객체의   인터페이스를 변경

// 클래스 Adapter
class Text : public TextView, public Shape
{
public:
	Text(const std::string& s) : TextView(s) {}

	void draw() override
	{
		TextView::show();
	}
};

// Object Adapter
// 핵심 : TextView 에서 상속이 아닌 TextView 를 포함
class ObjectAdapter : public Shape
{
	TextView* origin; // 핵심 : 포인터 또는 참조 멤버
					  // 의도 : 이미 생성되어 있는 객체를 가리키겠다 
public:
	ObjectAdapter(TextView* tv) : origin(tv) {}

	// 아래 코드가 이미 존재하는 객체(origin) 의 인터페이스를 변경한것
	// (show() => draw() 로 변경해준것)
	void draw() override 
	{
		origin->show();
	}
};

int main()
{
	std::vector<Shape*> v;
	
	TextView tv("hello");   // TextView : 클래스 
							// tv       : 객체
//	v.push_back(&tv); // error. 인터페이스 불일치

	v.push_back(new ObjectAdapter(&tv));

	v[0]->draw();
}







