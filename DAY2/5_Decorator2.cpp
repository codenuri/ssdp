// Decorator - 62 page
#include <iostream>
#include <string>
#include <thread>
#include <chrono>
using namespace std::literals;

// Image : ���ͳݿ��� �׸��� �ٿ�ε��� ȭ�鿡 �׸��� Ŭ����
class Image
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

// ����� ����� ����� �߰� : Ŭ������ ��� �߰�
// ������ ����� ����� �߰� : ��ü��   ��� �߰�

class Emoticon 
{
	Image* origin;	// �ٽ� : ������ �Ǵ� ���� ���, ���� �ȵ�
					// �ǵ� : �ܺο� �̹� ������ ��ü�� ����Ű�ڴٴ� ��
public:
	Emoticon(Image* img) : origin(img) {}

	void draw()
	{
		std::cout << "$$$$$$$$$$$$$$$$$$$$$$$$$\n"; // �߰��� ���
		origin->draw();		// ���� �����ϴ� ��ü�� ���
		std::cout << "$$$$$$$$$$$$$$$$$$$$$$$$$\n";
	}
};

int main()
{
	Image img("www.image.com/car.png");
	img.draw();


	Emoticon e(&img); // e �� img ��ü�� ����� �߰��ϴ� ��ü
	e.draw();
}
