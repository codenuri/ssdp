#include <iostream>
#include <string>
#include <vector>
#include <conio.h> 


class MenuItem
{
	std::string title;
	int id;
public:
	MenuItem(const std::string& title, int id)
		: title(title), id(id) {
	}

	std::string get_title() const { return title; }

	void command()
	{
		std::cout << get_title() << " �޴� ����\n";

		_getch();
	}
};


class PopupMenu
{
	std::string title;
	std::vector<MenuItem*> v;
public:
	PopupMenu(const std::string& title) : title(title) {}

	void add(MenuItem* m) { v.push_back(m); }

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
};



int main()
{
	MenuItem m1("��ġ���",   11);
	MenuItem m2("�Ұ����", 12);
	MenuItem m3("���", 13);
	MenuItem m4("����", 14);

	PopupMenu kimbab("����");

	kimbab.add(&m1);
	kimbab.add(&m2);

	PopupMenu pm("������ ����");
	pm.add(&kimbab); // �ٽ�!! ����� ����.. �ǰ� �Ϸ��� ??
	pm.add(&m3);
	pm.add(&m4);

	pm.command();
}




