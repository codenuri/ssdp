#include <iostream>
#include <string>
#include <vector>
#include <conio.h> 

// C 언어 : 메모리 구조를 이해하기 위해 메모리 그림을 그리게 됩니다.

// 객체지향 : 디자인을 이해하기 위해 "클래스 다이어그램(관계도)" 를 그리세요



class BaseMenu
{
	std::string title;
public:
	BaseMenu(const std::string& title) : title(title) {}

	virtual ~BaseMenu() {}	
	
	std::string get_title() const { return title; }

	// 모든 메뉴의 공통의 특징은 기반 클래스에 있어야 한다.
	virtual void command()  = 0;
};




class MenuItem : public BaseMenu
{
	int id;
public:
	MenuItem(const std::string& title, int id) : BaseMenu(title), id(id) {}

	void command()
	{
		std::cout << get_title() << " 메뉴 선택됨\n";
		_getch();
	}
};

class PopupMenu : public BaseMenu
{
	std::vector<BaseMenu*> v; // <== composite 패턴의 핵심 부분
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

			if (cmd < 1 || cmd > sz + 1)
				continue;



			v[cmd - 1]->command();
		}
	}
};



int main()
{
	MenuItem m1("참치김밥", 11);
	MenuItem m2("소고기김밥", 12);

	MenuItem m9("라면", 21);

	PopupMenu kimbab("김밥류");
	kimbab.add(&m1);
	kimbab.add(&m2);


	PopupMenu pm("오늘의 점심 메뉴");

	pm.add(&kimbab);	
	pm.add(&m9);	

	pm.command();
}




