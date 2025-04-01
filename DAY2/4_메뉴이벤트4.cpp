// 4_�޴��̺�Ʈ4.cpp   1�� ����
#include <iostream>
#include <string>
#include <vector>
#include <conio.h> 
#include <functional>
using namespace std::placeholders;


class unsupported_operation {};

class BaseMenu
{
	std::string title;
public:
	BaseMenu(const std::string& title) : title(title) {}

	virtual ~BaseMenu() {}

	std::string get_title() const { return title; }

	virtual void command() = 0;


	virtual void add(BaseMenu* m) { throw unsupported_operation(); }

	virtual BaseMenu* get_submenu(int idx) { throw unsupported_operation(); }

};








class PopupMenu : public BaseMenu
{
	std::vector<BaseMenu*> v;
public:
	PopupMenu(const std::string& title) : BaseMenu(title) {}

	void add(BaseMenu* m) { v.push_back(m); }

	void command()
	{
		while (1)
		{
			system("cls");

			int sz = v.size();

			for (int i = 0; i < sz; i++)
			{
				std::cout << i + 1 << ". " << v[i]->get_title() << std::endl;
			}

			std::cout << sz + 1 << ". ����\n";

			std::cout << "�޴��� �����ϼ��� >> ";

			int cmd;
			std::cin >> cmd;

			if (cmd == sz + 1)
				break;

			if (cmd < 1 || cmd > sz + 1)
				continue;

			v[cmd - 1]->command();
		}


	}

	BaseMenu* get_submenu(int idx) { return v[idx]; }
};

class MenuItem : public BaseMenu
{
	int id;

	void(*handler)() = nullptr; 
public:
	MenuItem(const std::string& title, int id)
		: BaseMenu(title), id(id) {
	}

	void command()
	{
	
		if (handler != nullptr)
			handler();

	}
};

int main()
{
	PopupMenu* root = new PopupMenu("ROOT");

	root->add(new MenuItem("HD", 11));
	root->add(new MenuItem("FHD", 12));
	root->add(new MenuItem("UHD", 13));
	//-------------------------------------------------------


	root->command();
}









