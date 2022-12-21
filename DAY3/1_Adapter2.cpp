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

//==========================================================
// 어답터의 종류
// 클래스 어답터 : 클래스의 인터페이스를 변경
// 객체   어답터 : 객체의  인터페이스를 변경

// 아래 코드는 "클래스 어답터" 입니다.
class Text : public TextView, public Shape
{
public:
	Text(const std::string& s) : TextView(s) {}

	virtual void draw() override
	{
		TextView::show();
	}
};

// 객체 어답터. 
class Text2 :  public Shape
{
	TextView* txtView;		// 핵심 : 기존 클래스로 부터 상속이 아니라!
							//       포인터 또는 참조로 포함.
							// 외부에 이미 만들어진 객체를 가리키겠다는
							// 의도!!!
public:
	Text2(TextView* tv) : txtView(tv) {}

	virtual void draw() override
	{
		txtView->show();
	}
};




int main()
{
	std::vector<Shape*> v;

	TextView tv("hello"); // TextView : 클래스!!
						  // tv       : 객체
	tv.show();	// 현재 tv 는 show() 로 출력


	
	// 이미 만들어서 사용중인 tv 객체를 v에 넣을수 있을까요 ?
//	v.push_back(&tv); // error. 인터페이스 불일치!!

	v.push_back( new Text2(&tv) ); // ok.. 객체 어답터를 사용해서
									// 인터페이스 변경

}

// TextView 의 인터페이스(show) 를 도형편집기 요구(draw)로 변경할때

// 클래스 어답터 : TextView 로 부터 상속받은 클래스로 구현
// 객체   어답터 : TextView 를 포함(포인터 또는 참조) 한 클래스로 구현

// 상속 : 클래스의 변화(기능 추가)
// 포함 : 객체의 변화(기능 추가)

// Decorator : 객체에 인터페이스는 동일한데, 기능이 추가되는 것
//				zd.write() => 기능추가후  fs.write() 호출
// 
// Adapter   : 객체에 인터페이스 변경!!


// decorator 와  adapter 구현이 유사해 보일수있습니다.
// 하지만, 의도가 명확히 다릅니다. => 항상 의도가 중요!






