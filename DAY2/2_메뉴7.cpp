#include <iostream>
#include <string>
#include <vector>
#include <conio.h> 

class BaseMenu
{
	std::string title;
public:
	BaseMenu(const std::string& title) : title(title) {}

	virtual ~BaseMenu() {}

	std::string get_title() const { return title; }

	virtual void command() = 0;

};



class MenuItem : public BaseMenu
{
	int id;
public:
	MenuItem(const std::string& title, int id)
		: BaseMenu(title), id(id) {
	}

	void command()
	{
		std::cout << get_title() << " �޴� ����\n";

		_getch();
	}
};


class PopupMenu : public BaseMenu
{
	std::vector<BaseMenu*> v; // <== �ٽ� !!
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


int main()
{
	PopupMenu* root = new PopupMenu("ROOT");
	PopupMenu* pm1 = new PopupMenu("�ػ� ����");

	pm1->add(new MenuItem("HD", 11));
	pm1->add(new MenuItem("FHD", 12));
	pm1->add(new MenuItem("UHD", 13));

	root->add(pm1);
	root->add(new MenuItem("ȭ�����", 21));

	//------------------------------------
	// �Ʒ� ��� �Լ��� ������ ���ô�.
	auto m1 = root->get_submenu(0);

	// �Ʒ� �ڵ带 ������ ������
//	root->get_submenu(0)->add(new MenuItem("8K", 15)); // error
						// root �� 0 �� ���� �޴��� �˾��޴��� ������
						// ��ȯ Ÿ���� BaseMenu* �̴�.
						// BaseMenu ���� add �� �����Ƿ� �����Ͽ���!!

	// �Ʒ� ó�� ĳ���� �ʿ�		
	static_cast<PopupMenu*>(root->get_submenu(0))->add(new MenuItem("8K", 15));

	// ĳ������ ���ټ� ������ ??? => �����ҽ�����

	root->command();
}









