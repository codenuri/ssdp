#include <iostream>
#include <vector>
#include <map>
#include "Helper.h"


class Shape
{
public:
	virtual void draw() = 0;
	virtual ~Shape() {}
};

class ShapeFactory
{
	MAKE_SINGLETON(ShapeFactory)

		using CREATOR = Shape * (*)();

	std::map<int, CREATOR> create_map;

public:
	void register_shape(int key, CREATOR c)
	{
		create_map[key] = c;
	}


	Shape* create(int key)
	{
		Shape* p = nullptr;

		auto it = create_map.find(key);

		if (it != create_map.end())
		{
			p = it->second();
		}
		return p;
	}
};

// ��ǰ(����)�� ���忡 ����ϱ� ���� Ŭ����
class AutoRegister
{
public:
	AutoRegister(int key, Shape* (*f)())
	{
		ShapeFactory::getInstance().register_shape(key, f);
	}
};

// ���������� �����ڰ� ȣ��Ǵ� ������ ������ ������
// => main �Լ��� ����Ǳ���, ���α׷� ó�����۵ɶ� ȣ��
//AutoRegister ar(1, &Rect::create);






class Rect : public Shape
{
public:
	void draw() override { std::cout << "draw Rect" << std::endl; }

	static Shape* create() { return new Rect; }

	// static ��� ����Ÿ�� ���� �����Ǵ��� ������ ������
	// => �ᱹ ���������� �����ϹǷ�, main �Լ� ������ �����ڰ� ȣ��˴ϴ�
	static AutoRegister ar;
};
AutoRegister Rect::ar(1, &Rect::create);

/*
						// Rect::ar �� ������ ȣ��
Rect* r1 = new Rect; // Rect ������ ȣ��
Rect* r2 = new Rect; // Rect ������ ȣ��
Rect* r3 = new Rect; // Rect ������ ȣ��
					 // ��, Rect �����ڴ� "��ü�� �ѹ���" ȣ��

// C#
class Car
{
	public Car() {} // �ν��Ͻ� ������
	static Car() {} // static ������
};
	
Car c1 = new Car();	// static �����ڰ� ���� ȣ��ǰ�
					// instance ������ ȣ��
Car c2 = new Car();	// instance ������ ȣ��
*/







class Circle : public Shape
{
public:
	void draw() override { std::cout << "draw Circle" << std::endl; }

	static Shape* create() { return new Circle; }

	inline static AutoRegister ar{ 2, &Circle::create };
};





int main()
{
	std::vector<Shape*> v;

	ShapeFactory& factory = ShapeFactory::getInstance();

	// main �Լ� �������� �̹� ������ ���忡 ��ϵǾ����ϴ�.
//	factory.register_shape(1, &Rect::create);
//	factory.register_shape(2, &Circle::create);


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




