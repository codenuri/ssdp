#include <iostream>
#include <vector>

// ���� ���� Ŭ����
class unsupported_operation {};

class Shape
{
	int color = 0;
public:
	virtual ~Shape() {}

	void set_color(int c) { color = c; }



	


public:
	void draw()
	{
		std::cout << "mutex lock\n";
		draw_imp();
		std::cout << "mutex unlock\n";
	}

	// �����Լ� : �Ļ� Ŭ������ override ���� ������ �⺻ ���� �����Ѵٴ� �ǹ�
	// ���� �����Լ� : �Ļ� Ŭ������ �ݵ�� override �ؼ� ���� �����϶�� �ǹ�

protected:
	virtual void draw_imp() = 0;

public:
	// clone �� ���
	// #1. �Ʒ� ó�� ���� ���� �ڵ� �̰�!!
//	virtual Shape* clone() = 0;

	// #2. �Ʒ� ó�� �Ҽ��� �ֽ��ϴ�.(C#, Python ���� �θ� ����ϴ� ���)
	// => �⺻ �������� ���� �߻�
	// => �ǵ�!
	// 1. �Ļ� Ŭ������ override �Ѱ�� ����ϸ� ok
	// 2. �Ļ� Ŭ������ override ���� �ʾҴµ� ����ϸ� ���� �߻�
	// 3. �Ļ� Ŭ������ override ���� �ʾҴµ� ��������� ������ ok
	// => ��, ����� ������ override �ض�!
	virtual Shape* clone() { throw unsupported_operation();  }

	// �Ʒ� �����Լ���
	// =>  =0 �Ǵ� �⺻ ������ ���� ���޷� �ص� �˴ϴ�.
	// => �Ǵ� C��� ó�� �߸��� ���� ��ȯ�ϴ� �⺻ ������ ����ϱ⵵ �մϴ�
	// => get_area()�� ��ȯ���� -1 �̸� ���� ���Ҽ� ����! ��� �Ŵ���� �ۼ�
	virtual int get_area() { return -1; }
};



class Rect : public Shape
{
public:
	void draw_imp() override { std::cout << "draw rect\n"; }

	Shape* clone() override { return new Rect(*this); }
};

class Circle : public Shape
{
public:
	void draw_imp() override { std::cout << "draw circle\n"; }

	Shape* clone() override { return new Circle(*this); }
};

int main()
{
	std::vector<Shape*> v;

	while (true)
	{
		int cmd;
		std::cin >> cmd;

		// #1. �� ������ Undo/Redo �� �߰��Ϸ��� ��� �ؾ� �ұ�� ?
		// => Command ������ �����ϸ� �˴ϴ�. ( ���� �Ǵ� ����� )
		// 
		// #2. Triangle �߰��� �Ʒ� if ���� ����(�߰�)�Ǿ�� �մϴ�.
		// => ��ü�� ������ OCP �� �����ϰ� �Ҽ� ������� ?
		// => factory ������ ����ϸ� �ذ��Ҽ� �ֽ��ϴ�(����Ͽ�..)

		if (cmd == 1) v.push_back(new Rect);
		else if (cmd == 2) v.push_back(new Circle);

		else if (cmd == 9)
		{
			for (auto s : v)
				s->draw();
		}
		else if (cmd == 0)
		{
			std::cout << "���° ������ ���� �ұ�� ?";

			int k;
			std::cin >> k;

			v.push_back(v[k]->clone());

		}
	}
}

