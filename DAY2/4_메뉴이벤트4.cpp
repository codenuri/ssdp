// 4_�޴��̺�Ʈ4.cpp   1�� ����
#include <iostream>
#include <string>
#include <vector>
#include <conio.h> 
#include <functional>
using namespace std::placeholders;


class Dialog
{
public:
	void close(int a, int b) 
	{ 
		printf("Dialog::close, %d, %d\n", a, b); 
		_getch();
	}
};


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

	using HANDLER = std::function<void()>;

	std::vector< HANDLER > v;

public:
	MenuItem(const std::string& title, int id, HANDLER h = nullptr )
		: BaseMenu(title), id(id) 
	{
		if (h != nullptr)
			v.push_back(h);
	}

	void add_handler(HANDLER h) { v.push_back(h); }


	void command()
	{
		for (auto h : v)
			h();	// ���⼭ h �� std::function<void()> �Դϴ�.
					// �ᱹ ��ϵ� �Լ�
	}
};

void f0() { std::cout << "f0\n"; _getch(); }

void f1(int n) { printf("f1 : %d\n", n); _getch(); }

int main()
{
	PopupMenu* root = new PopupMenu("ROOT");

	root->add(new MenuItem("HD",  11, &f0 ));

	// �Ʒ� �ڵ��� �ǹ̴�
	// => 2���� �޴��� ������ �Լ����� ó���ϴµ�..
	// => �Լ� ���ڷ� �޴� ID �� �����ؼ� �����ϴ� ��
	root->add(new MenuItem("FHD", 12, std::bind(&f1, 12) ));
	root->add(new MenuItem("UHD", 13, std::bind(&f1, 13)));

	// Dialog Ŭ���� ������ ������
	// �Ʒ� �޴� �� �ڵ鷯 2�� ����� ������
	// => Dialog::close �� f0 ���
	MenuItem* m = new MenuItem("ȭ�����", 14, &f0 );

	Dialog dlg;
	m->add_handler( std::bind(&Dialog::close, &dlg, 0, 0) );

	root->add(m); 
	//-------------------------------------------------------


	root->command();
}









