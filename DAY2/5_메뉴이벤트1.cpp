// 메뉴 이벤트1.cpp     메뉴5번 복사해오세요

#include "PopupMenu.h"

class MenuItem : public BaseMenu
{
	int  id;
public:
	MenuItem(const std::string& title, int id) : BaseMenu(title), id(id) {}

	void command()
	{
		std::cout << get_title() << " 메뉴 선택됨" << std::endl;
		_getch();
	}
};


int main()
{
	PopupMenu* root = new PopupMenu("ROOT");

	root->add_menu(new MenuItem("FHD", 11));
	root->add_menu(new MenuItem("UHD", 12));

	// 이제 시작하려면 ?
	root->command();
}





