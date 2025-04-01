#include <iostream>
#include <string>
#include <vector>

// �Ʒ� Ŭ������ �̹� �־��ٰ� ������ ���ô�.
// => ���ڿ��� ȭ�鿡 �̻ڰ� ����ϴ� Ŭ����
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


// Ŭ���� ����� : Ŭ������ �������̽��� �����ϴ� ����
// ��ü  �����  : ��ü�� �������̽��� �����ϴ� ����

// Text : ? ����� 
class Text : public TextView, public Shape
{
public:
	Text(const std::string& s) : TextView(s) {}

	void draw() override
	{
		TextView::show();
	}
};

// �Ʒ� �ڵ尡 ��ü �����
class ObjectAdapter : public Shape
{
	TextView* origin;	// �ٽ� : �����ͳ� ����
						// �ǵ� : "�̹� ������ TextView ��ü" �� ����Ű �ڴٴ°�
public:
	ObjectAdapter(TextView* p) : origin(p) {}

	void draw() override { origin->show();	}
};


int main()
{
	std::vector<Shape*> v;

	TextView tv("hello"); // TextView : Ŭ����
						  // tv       : ��ü

	// �̹� ������ "��ü tv" �� ���������� �ý��ۿ� ������ ������ ?
//	v.push_back(&tv); // error. tv �� Shape ���� ��ӵ��� �ʾҴ�.

	v.push_back( new ObjectAdapter(&tv) ); // ok.. ��ġ���� ���� �������̽���
										// ����(adapter)�� ����ؼ� ����

}







