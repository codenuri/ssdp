#include <iostream>
#include <vector>


// 6. Refactoring 에서 가장 유명한 용어 입니다. 의미를 생각해 보세요
// 리팩토링 : 기존 코드를 보기 좋게 수정하는 작업
// 
// "Replace Conditional(제어문, if, switch) With Polymorphism(다형성, 가상함수)"
// "도형편집기5-1처럼 되어 있다면 5-2 처럼 변경하라" 는 의미!!
// 항상 제어문 보다는 다형성을 먼저 생각 해라!


// 7. 디자인 패턴 - 1994년 4명의 개발자가 저술한 책의 제목!!!

// 당시 오픈 소스를 분석해서 유행하던 코딩 스타일에 이름을 붙인것!!
// => 4명의 저자가 코드를 만든것이 아니라!! 이름을 부여 한것
// => 23개의 이름 부여!!


// 8. Prototype 패턴 : 견본이 되는 객체를 만들고
//					   복사를 통한 객체를 생성하는 기술
//						Clone() 가상함수



class Shape
{
	int color;
public:
	virtual ~Shape() {}

	int  get_color() { return color; }
	void set_color(int c) { color = c; }

	virtual int get_area() { return -1; }

	virtual void draw() { std::cout << "draw Shape" << std::endl; }

	// 자신의 복사본을 만드는 가상함수는 항상 유용하게 활용됩니다.
	virtual Shape* clone()
	{
		Shape* p = new Shape(*this); // 복사생성자로 나와 동일한 객체생성
		return p;
	}
};




class Rect : public Shape
{
public:
	virtual void draw() override { std::cout << "draw Rect" << std::endl; }

	virtual Shape* clone() override 
	{
		return new Rect(*this); 		
	}
};



class Circle : public Shape
{
public:
	virtual void draw() override { std::cout << "draw Circle" << std::endl; }
	
	virtual Shape* clone() override
	{
		return new Circle(*this);
	}
};



int main()
{
	std::vector<Shape*> v;

	while (1)
	{
		int cmd;
		std::cin >> cmd;

		if (cmd == 1)       v.push_back(new Rect);
		else if (cmd == 2)	v.push_back(new Circle);

		else if (cmd == 9)
		{
			for (auto p : v)
				p->draw();
		}

		else if (cmd == 8)
		{
			std::cout << "몇번째 도형을 복제 할까요 >> ";

			int k;
			std::cin >> k;

			// 방법 2. 다형성 사용
			// => 핵심 : k번째 도형이 어떤 도형인지 알필요 없다.
			v.push_back(v[k]->clone()); // 다형성!!
			
		}
	}
}






