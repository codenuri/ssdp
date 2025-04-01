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

class MenuItem : public BaseMenu
{
	int id;

	void(*handler)() = nullptr; // 메뉴 선택시 호출될 함수 포인터!
								// 단점 : 일반 함수 밖에 등록할수 없습니다.
								//        멤버 함수, 람다 표현식등을 등록안됨

				// 대부분의 언어에는 이런 용도로 사용하기 위한 도구가 있습니다.
				// C#   : delegate
				// java : Functional Interface(java 1.8 에서 추가)
				// C++  : std::function, std::bind

public:
	MenuItem(const std::string& title, int id)
		: BaseMenu(title), id(id) {	}

	void command()
	{
		// 여기서 직접 작업을 하면 모든 메뉴(아이템)이 동일한 작업을 하게
		// 됩니다.
		// 여기서 등록된 함수를 호출하게 합니다.

		if (handler != nullptr)
			handler();
	
	}
};

int main()
{
	PopupMenu* root = new PopupMenu("ROOT");
	
	root->add(new MenuItem("HD", 11));
	root->add(new MenuItem("FHD", 12));
	root->add(new MenuItem("UHD", 13));
	//-------------------------------------------------------


	root->command();
}









