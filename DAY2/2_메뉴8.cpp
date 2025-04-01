#include <iostream>
#include <string>
#include <vector>
#include <conio.h> 

class unsupported_operation {};

class BaseMenu
{
	std::string title;
public:
	BaseMenu(const std::string& title) : title(title) {}

	virtual ~BaseMenu() {}

	std::string get_title() const { return title; }

	virtual void command() = 0;


	// 아래 2개는 MenuItem 에는 필요 없지만,
	// 사용하기 쉽게(캐스팅없이) 하기 위해 BaseMenu 에도 제공
	virtual void add(BaseMenu* m) { throw unsupported_operation(); }

	virtual BaseMenu* get_submenu(int idx){ throw unsupported_operation(); }

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
	root->get_submenu(0)->add(new MenuItem("8K", 15)); 

//	root->get_submenu(1)->add(new MenuItem("8K", 15));
				// 1번째 메뉴가 Popup 이 아니므로 예외 발생
			
	root->command();
}


// menu7.cpp : get_submenu() 의 반환 타입을 사용자가 캐스팅해서 사용
//				=> 안전성을 위한 모델
// 
// menu8.cpp : 캐스팅 필요 없다.
//				=> 편의성을 위한 모델.







