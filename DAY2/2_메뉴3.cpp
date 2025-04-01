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



int main()
{
	MenuItem m1("���", 11);
	MenuItem m2("���", 12);

	PopupMenu pm("������ ����");

	pm.add(&m1);
	pm.add(&m2);

	pm.command(); // �˾��޴� ���ý� �ؾ� ������ ������ ������
}




