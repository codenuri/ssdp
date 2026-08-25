#include <iostream>
#include <string>
#include <vector>
#include <conio.h> 

// 메뉴 예제 핵심
// #1. 필요한 타입을 먼저 설계해라 : MenuItem, PopupMenu 클래스 만들기

// #2. 각 타입에 디자인 패턴을 적용해서 연관성을 부여..


// C 언어         : 메모리 구조를 이해 하기 위해 "메모리 그림" 을 그리면서 학습합니다.

// 객체지향 디자인 : 클래스 구조를 이해 하기 위해 "클래스 다이어그램" 을 그리면서 학습
//					교재의 각 패턴 설명에 있는 클래스 다이어 그램과 같은 형태


// 모든 종류의 메뉴를 하나의 컨테이너에 보관하려면
// => 모든 메뉴의 공통의 기반 클래스 필요

class BaseMenu
{
	std::string title;
public:
	BaseMenu(const std::string& title) : title(title) {}

	virtual ~BaseMenu() {}
	
	std::string get_title() const { return title; }
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
	MenuItem m1("참치 김밥", 11);
	MenuItem m2("야채 김밥", 12);
	MenuItem m3("소고기 김밥", 13);

	MenuItem m9("라면", 21);

	PopupMenu kimbab("김밥류");
	kimbab.add(&m1);
	kimbab.add(&m2);
	kimbab.add(&m3);

	PopupMenu pm("오늘의 점심 메뉴");

	pm.add(&kimbab); 
	pm.add(&m9);

	pm.command();

}




