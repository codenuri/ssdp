#include <iostream>
#include <string>
#include <vector>
#include <conio.h> 

// C언어 : 포인터(메모리 구조)를 이해하기 위해 메모리 그림을 그리며 학습 합니다.
// 객체지향 디자인 : 클래스 다이어그램을 그리면서 디자인을 학습해야 합니다

// 56 page~ 에 아래 그림 그려 두세요.


class BaseMenu
{
	std::string title;
public:
	BaseMenu(const std::string& title) : title(title) {}

	virtual ~BaseMenu() {}

	std::string get_title() const { return title; }

	// 모든 메뉴는 선택될수 있어야 한다.

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

			v[cmd - 1]->command(); // 다형성!!
						// MenuItem::command() 또는
						// PopupMenu::command() 호출
		}


	}
};



int main()
{
	MenuItem m1("참치김밥", 11);
	MenuItem m2("소고기김밥", 12);
	MenuItem m3("라면", 13);
	MenuItem m4("국수", 14);

	PopupMenu kimbab("김밥류");

	kimbab.add(&m1);
	kimbab.add(&m2);

	PopupMenu pm("오늘의 점심");
	pm.add(&kimbab); 
	pm.add(&m3);
	pm.add(&m4);

	pm.command();
}




