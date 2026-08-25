#include <iostream>
#include <string>
#include <vector>
#include <conio.h> 
#include <functional> // std::function 을 위한 헤더

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

	// 메뉴에 등록하는 핸들러 함수 모양 : void 반환, 인자 없는 함수
	using HANDLER = std::function<void()>; // 별명 만들어서 사용

	std::vector< HANDLER > handler_vector;

public:
	MenuItem(const std::string& title, int id, HANDLER h = 0) 
		: BaseMenu(title), id(id) 
	{
		if (h != 0)
			handler_vector.push_back(h);
	}

	void add_handler(HANDLER h) { handler_vector.push_back(h); }

	void command()
	{
		// 등록된 모든 핸들러를 실행
		for (auto f : handler_vector)
		{
			f();
		}
	}
};

void foo() { std::cout << "PC종료 구현\n"; _getch(); }
void goo() { std::cout << "색상변경 구현\n"; _getch(); }

int main()
{
	MenuItem m1("PC종료",   11, &foo);
	MenuItem m2("색상변경", 12, &goo);

	m1.add_handler([]() { std::cout << "PC종료를 람다 표현식으로\n"; });

	m1.command(); 
}


