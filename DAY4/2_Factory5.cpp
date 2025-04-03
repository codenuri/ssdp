#include <iostream>
#include <vector>
#include <map>
#include "Helper.h"

class Shape
{
public:
	virtual void draw() = 0;
	virtual ~Shape() {}

	virtual Shape* clone() = 0;
};

class Rect : public Shape
{
public:
	void draw() override { std::cout << "draw Rect" << std::endl; }

	static Shape* create() { return new Rect; }

	virtual Rect* clone() override { return new Rect(*this); }
};




class Circle : public Shape
{
public:
	void draw() override { std::cout << "draw Circle" << std::endl; }

	static Shape* create() { return new Circle; }

	virtual Circle* clone() override { return new Circle(*this); }
};


class ShapeFactory
{
	MAKE_SINGLETON(ShapeFactory)

	std::map<int, Shape*> prototype_map;

public:
	void register_shape(int key, Shape* c)
	{
		prototype_map[key] = c;
	}


	Shape* create(int key)
	{
		Shape* p = nullptr;

		auto it = prototype_map.find(key);

		if (it != prototype_map.end())
		{
			p = it->clone();	
		}
		return p;
	}
};


int main()
{
	std::vector<Shape*> v;

	ShapeFactory& factory = ShapeFactory::getInstance();

	// �Ʒ� �ڵ�� ���忡 Ŭ������ ����ϴ� ȿ��
	// => ��ü�� �����ϱ����� ���� ���
//	factory.register_shape(1, &Rect::create);
//	factory.register_shape(2, &Circle::create);


	// ���忡 Ŭ������ �ƴ� ���� ���Ǵ� ������ �ߺ��� ����� ���ô�.
	Rect* redRect = new Rect; // ������, ũ�� 10
	Rect* blueRect = new Rect; // �Ķ�����, ũ�� 20
	Circle* circle = new Circle; // gradient �� ������ ������ ��

	factory.register_shape(1, redRect);
	factory.register_shape(2, blueRect);
	factory.register_shape(3, circle);





	while (1)
	{
		int cmd;
		std::cin >> cmd;


		if (cmd >= 1 && cmd <= 7)
		{
			Shape* s = factory.create(cmd);

			if (s != nullptr)
				v.push_back(s);
		}

		else if (cmd == 9)
		{
			for (int i = 0; i < v.size(); i++)
			{
				v[i]->draw();
			}
		}
	}
}




