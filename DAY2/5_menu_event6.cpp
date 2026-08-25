#include <iostream>
#include <string>
#include <vector>
#include <conio.h> 
#include <functional>

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

	using HANDLER = std::function<void()>;

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
		for (auto f : handler_vector)
		{
			f();
		}
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

// 메뉴 이벤트를 처리할 함수들

void color_red() { std::cout << "색상을 Red로  변경\n"; _getch(); }
void color_green() { std::cout << "색상을 green로 변경\n"; _getch(); }


void change_resolution(int id)
{
	switch (id)
	{
	case 1: std::cout << "HD\n"; break;
	case 2: std::cout << "FHD\n"; break;
	}
	_getch();
}

class Dialog
{
public:
	void close() { std::cout << "Dialog close\n"; _getch(); }
};


int main()
{
	PopupMenu* root = new PopupMenu("ROOT");
	PopupMenu* p1 = new PopupMenu("해상도 변경");
	PopupMenu* p2 = new PopupMenu("색상 변경");

	root->add(p1);
	root->add(p2); 

	p2->add(new MenuItem("RED", 21, &color_red));
	p2->add(new MenuItem("GREEN", 22, &color_green));
	p2->add(new MenuItem("BLUE", 23, []() { std::cout << "blue\n"; _getch(); }));

	Dialog dlg;
	p2->add(new MenuItem("WHITE", 24, [&dlg]() { dlg.close(); }));

	p1->add(new MenuItem("HD", 11, []() { change_resolution(1); }));
	p1->add(new MenuItem("FHD", 12, []() { change_resolution(2); }));
	p1->add(new MenuItem("UHD", 13, []() { change_resolution(3); }));



	root->command();

	// 위 코드의 모든 메뉴 객체는 "new" 로 만들었습니다.
	// 종료전에 "반드시 delete" 해야 합니다

	// 방법 #1. raw pointer 사용하지 말고 스마트 포인터 사용(std::shared_ptr)
	// 방법 #2. 모든 객체를 직접 delete
	// 방법 #3. delete root 만 하고, PopupMenu 소멸자에서 자신이 포함한 메뉴를 delete

	delete root; // 방법 #3. 사용
}


