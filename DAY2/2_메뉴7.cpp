#include <iostream>
#include <string>
#include <vector>
#include <conio.h> 


class BaseMenu
{
	std::string title;
public:
	BaseMenu(const std::string& title)
		: title(title) {}

	virtual ~BaseMenu() {}

	std::string get_title() { return title; }

	virtual void command() = 0;
};




class MenuItem : public BaseMenu
{
	int id;
public:
	MenuItem(const std::string& title, int id)
		: BaseMenu(title), id(id) {}



	void command()
	{
		std::cout << get_title() << " 메뉴 선택\n";
		_getch();
	}
};

class PopupMenu : public BaseMenu
{
	std::vector<BaseMenu*> v;
public:
	PopupMenu(const std::string& title)
		: BaseMenu(title) {}

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

			if (cmd < 1 || cmd > sz + 1)
				continue;


			v[cmd - 1]->command();

		}
	}

	BaseMenu* submenu(int idx) { return v[idx]; }
};

int main()
{
	PopupMenu* root = new PopupMenu("ROOT");
	PopupMenu* pm1 = new PopupMenu("색상 변경");
	PopupMenu* pm2 = new PopupMenu("해상도 변경");

	root->add(pm1);
	root->add(pm2);	
	root->add(new MenuItem("재부팅", 12));
	//------------------------------
	
	auto m1 = root->submenu(0); // "색상 메뉴 객체의 포인터"


	// 아래 한줄에 대해서 생각해 봅시다.
//	root->submenu(1)->add(new MenuItem("HD", 21)); // error
				// submenu(1) 은 "해상도 메뉴" 이므로
				// PopupMenu 객체가 맞지만
				// submenu() 의 반환 타입이 BaseMenu* 이다.
				// 따라서, PopupMenu 가 추가한 멤버에는 접근 안됨
			
	// 해결책 #1. 캐스팅해서 사용
	static_cast<PopupMenu*>(root->submenu(1))->add(new MenuItem("HD", 21));


	// 캐스팅 없이 사용할수 없을까 ?
	// => 다음예제(메뉴8.cpp)


	root->command();

}



