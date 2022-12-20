#include "PopupMenu.h"

// 방법 2. 변하는 것을 다른 클래스로!!!

// 메뉴 이벤트를 처리하고 싶은 모든 클래스는
// 반드시 아래 인터페이스를 구현해야 한다.

struct IMenuListener
{
	virtual void on_command() = 0;
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
			ps->on_command();
	}
};
//=========================================
// 이제 프로그램을 구성하는 다양한 클래스들 중에서 메뉴를 처리하고 싶다면
// 약속된 규칙을 지켜야 합니다.
class Camera : public IMenuListener
{
public:
	// ....다양한 멤버들...

	virtual void on_command() override
	{
		std::cout << "Camera 객체가 메뉴 이벤트 처리" << std::endl;
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





