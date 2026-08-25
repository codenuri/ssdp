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
	BaseMenu* submenu(int idx) { return v[idx]; }
};
//------------------------------------------------
class MenuItem : public BaseMenu
{
	int id;
	void(*handler)(); // 메뉴 선택시 수행될 함수의 주소 보관
public:
	MenuItem(const std::string& title, int id) : BaseMenu(title), id(id) {}
	void set_handler(void(*f)()) { handler = f; }

	void command()
	{
		// 여기서 MenuItem 선택시 기능을 직접 구현하면
		// "모든 MenuItem 이 동일한 기능을 수행하게 된다"
		// 그래서 여기서 직접 구현하면 안되고
		// 여기서는 "등록된 핸들러 함수" 를 다시 호출
		handler();		
	}
};
void foo() { std::cout << "PC종료 구현\n"; _getch(); }
void goo() { std::cout << "색상변경 구현\n"; _getch(); }
int main()
{
	MenuItem m1("PC종료", 11);
	m1.set_handler(&foo);
	
	MenuItem m2("색상변경", 12);
	m2.set_handler(&goo);

	m1.command(); // 실제 "PC종료" 작업을 수행해야 합니다.
}


