#include "PopupMenu.h"

// 방법 2. 변하는 것을 다른 클래스로!!!
// => 메뉴 선택시, 인터페이스로 약속된 함수를 호출
// => java, 안드로이드의 "리스너" 방식
// => 객체지향 언어에서 가장 널리 사용되는 방식

// 특징 : 여러개 메뉴를 한개의 함수에서 처리하게 되는 경우가 많아지고
//        커다란 switch-case 를 만들게 된다.


// 메뉴 이벤트를 처리하고 싶은 모든 클래스는
// 반드시 아래 인터페이스를 구현해야 한다.

struct IMenuListener
{
	virtual void on_command(int id) = 0;
	virtual ~IMenuListener() {}
};

class MenuItem : public BaseMenu
{
	int  id;
	IMenuListener* ps = nullptr;
public:
	void set_listener(IMenuListener* p) { ps = p; }

	MenuItem(const std::string& title, int id) : BaseMenu(title), id(id) {}

	void command()
	{
		if (ps != nullptr)
			ps->on_command(id);
	}
};
//=========================================
// 이제 프로그램을 구성하는 다양한 클래스들 중에서 메뉴를 처리하고 싶다면
// 약속된 규칙을 지켜야 합니다.
class Camera : public IMenuListener
{
public:
	// ....다양한 멤버들...

	virtual void on_command(int id) override
	{
		std::cout << "Camera 객체가 메뉴 이벤트 처리" << std::endl;

		// 수십개의 메뉴를 이곳에서 처리하게 된다면
		// "거대한 switch ~ case" 를 가지게 됩니다.
		switch (id)
		{
		case 11: break;
		case 12: break;
		}
		_getch();
	}
};


int main()
{
	PopupMenu* root = new PopupMenu("ROOT");

	MenuItem* m1 = new MenuItem("FHD", 11);
	MenuItem* m2 = new MenuItem("UHD", 12);

	root->add_menu(m1);
	root->add_menu(m2);

	// 각 메뉴에 이벤트를 처리할 객체를 연결
	Camera* cam = new Camera;
	m1->set_listener(cam);
	m2->set_listener(cam);


	root->command();
}





