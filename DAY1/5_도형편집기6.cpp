#include <iostream>
#include <vector>

// 9. template method 패턴
//    => 기반 클래스에 변하지 않은 전체적인 흐름을 담은 함수를 제공
//       (public, non-virtual)
//    => 변해야 하는 부분만 찾아서 가상함수로 제공(private 또는 protected, virtual)

//    => 파생 클래스가 전체 흐름을 물려 받으면서도, 변해야하는 것만 변경할 기회를
//       얻을수 있게 된다.


class Shape
{
	int color;
public:
	virtual ~Shape() {}

	int  get_color() { return color; }
	void set_color(int c) { color = c; }

	virtual int get_area() { return -1; }

	// 공통성과 가변성의 분리
	// => 변하지 않은 흐름 내부에 숨어 있는 변해야 하는 코드는
	//    분리되어야 합니다.
	// => 변하는 것을 찾아서 가상함수로 분리하세요
protected:
	virtual void draw_imp()
	{
		std::cout << "draw Shape" << std::endl;
	}
public:
	void draw() 
	{
		std::cout << "mutex lock" << std::endl;
		std::cout << "graphic 객체 설정" << std::endl;

		draw_imp();		
		std::cout << "mutex unlock" << std::endl;
	}





	virtual Shape* clone()
	{
		Shape* p = new Shape(*this);
		return p;
	}
};




class Rect : public Shape
{
public:
	virtual void draw_imp() override { std::cout << "draw Rect" << std::endl; }

	virtual Shape* clone() override
	{
		return new Rect(*this);
	}
};

class Circle : public Shape
{
public:
	virtual void draw_imp() override { std::cout << "draw Circle" << std::endl; }

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

			v.push_back(v[k]->clone()); 

		}
	}
}






