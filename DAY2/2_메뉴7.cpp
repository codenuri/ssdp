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
		std::cout << get_title() << " 메뉴 선택\n";

		_getch();
	}
};


class PopupMenu : public BaseMenu
{
	std::vector<BaseMenu*> v; // <== 핵심 !!
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

	BaseMenu* get_submenu(int idx) { return v[idx]; }
};


int main()
{
	PopupMenu* root = new PopupMenu("ROOT");
	PopupMenu* pm1 = new PopupMenu("해상도 변경");

	pm1->add(new MenuItem("HD", 11));
	pm1->add(new MenuItem("FHD", 12));
	pm1->add(new MenuItem("UHD", 13));

	root->add(pm1);
	root->add(new MenuItem("화면끄기", 21));

	//------------------------------------
	// 아래 멤버 함수를 생각해 봅시다.
	auto m1 = root->get_submenu(0);

	// 아래 코드를 생각해 보세요
//	root->get_submenu(0)->add(new MenuItem("8K", 15)); // error
						// root 의 0 번 하위 메뉴는 팝업메뉴가 맞지만
						// 반환 타입이 BaseMenu* 이다.
						// BaseMenu 에는 add 가 없으므로 컴파일에러!!

	// 아래 처럼 캐스팅 필요		
	static_cast<PopupMenu*>(root->get_submenu(0))->add(new MenuItem("8K", 15));

	// 캐스팅을 없앨수 없을까 ??? => 다음소스에서

	root->command();
}









