#include <iostream>
#include <string>
#include <thread>
#include <chrono>
using namespace std::literals;

// Image �� Image �� ����� �߰��ϴ� Ŭ����(���ڷ�����)
// �� ������ ��� Ŭ����(�������̽�)�� �ʿ��ϴ�.

struct IDraw
{
	virtual void draw() = 0;
	virtual ~IDraw() {}
};


class Image : public IDraw
{
	std::string url;
public:
	Image(const std::string& url) : url(url)
	{
		std::cout << "downloading... " << url << std::endl;
		std::this_thread::sleep_for(3s);
	}

	void draw()
	{
		std::cout << "draw " << url << std::endl;
	}
};

class Emoticon : public IDraw
{
	IDraw* origin;
public:
	Emoticon(IDraw* img) : origin(img) {}

	void draw()
	{
		std::cout << "$$$$$$$$$$$$$$$$$$$$$$$$$\n";
		origin->draw();
		std::cout << "$$$$$$$$$$$$$$$$$$$$$$$$$\n";
	}
};

class Frame : public IDraw
{
	IDraw* origin;
public:
	Frame(IDraw* img) : origin(img) {}

	void draw()
	{
		std::cout << "#########################\n";
		origin->draw();
		std::cout << "#########################\n";
	}
};
int main()
{
	Image img("www.image.com/car.png");
	img.draw();

	Emoticon e(&img);	// ��� �߰�
	e.draw();

	Frame f(&e);		// �߰��� ��ɿ� �ٽ� ��� �߰�
	f.draw();	// ��� �߰��Ȱ� ����
	img.draw();	// ��� �߰��Ǳ����� ��������
				// ��, ������ ���� ������ ���ȴ�.

	// ���� ������ ����.. �Ʒ� ó�� �ϸ� �ȵǳ���?
	/*
	img.add_filter(new Emoticon);
	img.add_filter(new Frame);
	
	img.draw(); // ��ϵ� ������ ��� draw() ȣ����
				// �ڽ��� draw() ����
	// �� ���� ���� ����Ǳ� ���� �����׸��� �����Ҽ� �����ϴ�.
	// ������ decorator ������ ���� ������ �˴ϴ�.
	*/
}
