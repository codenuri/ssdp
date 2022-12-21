#include <iostream>
#include <string>
#include <vector>

// 아래 클래스가 이미 있었다가 가정해 봅시다.

// TextView : 문자열을 보관했다가 화면에 이쁘게 출력하는 클래스
class TextView
{
	// font종류, 크기등의 정보
	std::string data;
public:
	TextView(const std::string& s) : data(s) {}

	void show() { std::cout << data << std::endl; }
};

//==========================================




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

// "도형편집기 시스템" 에서 "Rect", "Circle" 외에
// 문자열도 필요하게 되었다..
// 기존에 있던 TextView : show()로 출력
// 도형편집기 요구조건   : draw()로 출력해야 하고 Shape로 부터 상속받아야 한다


// Adapter 패턴 : 기존 클래스의 인터페이스(함수이름)을 변경해서
//				  시스템이 요구하는 형태로 변경해주는 패턴

// "인터페이스의 불일치" 를 해결하는 패턴.


// TextView 의 인터페이스(함수이름)을 변경해서 도형편집기에서
// 사용할수 있게 해보자
class Text : public TextView, public Shape
{
public:
	Text(const std::string& s) : TextView(s) {}

	// show() 함수 이름을 draw() 이름으로 변경하는 역활
	virtual void draw() override
	{
		TextView::show();
	}
};


int main()
{
	std::vector<Shape*> v;

	v.push_back(new Text("hello"));

	v[0]->draw(); // 결국 : TextView::show() 로 출력
}








