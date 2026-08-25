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
	MenuItem(const std::string& title, int id) : BaseMenu(title), id(id) {}

	void command()
	{
		std::cout << get_title() << "메뉴 선택됨\n";

		_getch();
	}
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

			auto sz = v.size();

			for (int i = 0; i < sz; i++)
			{
				std::cout << i + 1 << ". " << v[i]->get_title() << '\n';
			}

			std::cout << sz + 1 << ". 종료\n";

			std::cout << "메뉴를 선택하세요 >> ";

			int cmd;
			std::cin >> cmd;


			if (cmd == sz + 1)
				break;

			if (cmd < 0 || cmd > sz + 1)
				continue;

			v[cmd - 1]->command();

		}

	}

};

int main()
{
	PopupMenu* root = new PopupMenu("ROOT");
	PopupMenu* p1 = new PopupMenu("해상도 변경");
	PopupMenu* p2 = new PopupMenu("색상 변경");

	root->add(p1);
	root->add(p2);

	p1->add(new MenuItem("HD",  11));
	p1->add(new MenuItem("FHD", 12));
	p1->add(new MenuItem("UHD", 13));

	p2->add(new MenuItem("RED",   21));
	p2->add(new MenuItem("GREEN", 22));
	p2->add(new MenuItem("BLUE",  23));

	// #1. 위 메뉴 객체들의 관계를 그림을 표현해 보세요 - 어떤 자료구조와 유사합니다
	// => 객체의 포함관계가 "tree" 처럼 구성 된다
	// #2. 이제 메뉴를 시작하려면
	root->command();

}




