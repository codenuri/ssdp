// 32bit - "x86" ���� ����
#define USING_GUI
#include "cppmaster.h"



class Window
{
	int handle;
public:
	void create(const std::string& title)
	{
		handle = ec_make_window(&event_loop, title);
	}

	// �ٽ� #1. �Ʒ� �Լ��� static �̾�� �Ǵ� ������ �ݵ�� �˾ƾ� �մϴ�
	// C ���� "�Լ��� ���ڷ� ���޵Ǵ� �Լ�(callback �Լ�)" ��
	// C++ Ŭ������ ���鶧�� �ݵ�� static ����Լ��� �ؾ� �մϴ�.
	// => this ����

	static int event_loop(int hwnd, int msg, int a, int b)
	{
		switch (msg)
		{
		case WM_LBUTTONDOWN: std::cout << "LBUTTON " << hwnd << std::endl; break;
		case WM_KEYDOWN:     std::cout << "KEYDOWN " << hwnd << std::endl; break;
		}
		return 0;
	}
};

int main()
{
	Window w;
	w.create("A");

	ec_process_message();
}

