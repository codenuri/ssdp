// 5_메뉴이벤트4
#include "PopupMenu.h"

// 방법 3. 함수 포인터 기반 메뉴 이벤트 처리

class MenuItem : public BaseMenu
{
	int  id;

	void(*handler)() = nullptr;
public:
	void set_handler( void(*f)() ) { handler = f; }

	MenuItem(const std::string& title, int id) : BaseMenu(title), id(id) {}

	void command()
	{
		if (handler)
			handler();
	}
};

//
void f1() { std::cout << "f1" << std::endl; }


int main()
{
	MenuItem m("FHD", 11);

	m.set_handler(&f1); // 이벤트 처리 함수 연결

	m.command();
}





