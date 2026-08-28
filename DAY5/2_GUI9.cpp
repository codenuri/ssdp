#define USING_GUI
#include "cppmaster.h"
#include <map>

// Window 클래스는 실제로 구현하면 클래스 크기가 아주 큽니다.
// => 수십개의 일반 멤버 함수
// => 수백개의 메세지 처리용 함수
// => 수십개의 멤버 데이타(좌표, 색상, 폰트정보등...)


// 클래스 템플릿 만들때
// => 템플릿 인자 T 를 사용하지 않은 멤버는 
// => 템플릿이 아닌 기반 클래스를 만들어서 제공한다

// => "template hosting 또는 thin template" 이라는 이름을 가진 C++ Idioms

// => template 이 여러 타입에 대해서 instance 화 되어서
//    코드 메모리가 증가하는 현상을 제거하기 위해서 사용하는 기술 입니다.



// 아래 코드가 유명한 스타일 이므로
// => 복습할때 잘 정리해 두세요
// => 오픈소스에서 많이 볼수 있는 스타일 입니다.

class WindowBase
{
protected:
	int handle;
	inline static std::map<int, WindowBase*> this_map;
public:
	void move() {}
	void show() {}
	void set_style() {}

	void lbutton_down() { std::cout << "Window lbutton_down\n"; }
	void key_down() {}
};


template<typename T>
class Window : public WindowBase
{
public:
	void create(const std::string& title)
	{
		handle = ec_make_window(&foo, title);
		this_map[handle] = this;
	}

	static int foo(int hwnd, int msg, int a, int b)
	{
		T* self = static_cast<T*>(this_map[hwnd]);

		switch (msg)
		{
		case WM_LBUTTONDOWN:
			self->lbutton_down(); 
			break;

		case WM_KEYDOWN:
			self->key_down();
			break;
		}
		return 0;
	}
};

class MainFrame : public Window<MainFrame>
{
public:
	void lbutton_down() { std::cout << "MainFrame lbutton_down\n"; }
};
class ImageView : public Window<ImageView>
{
public:
	void lbutton_down() { std::cout << "MainFrame lbutton_down\n"; }
};
int main()
{
	MainFrame w;
	w.create("Hello");

	ec_process_message();
}







