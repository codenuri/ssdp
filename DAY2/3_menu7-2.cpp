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

	// 아래 2개의 함수는 PopupMenu 만 필요하고
	// MenuItem 에는 필요 없습니다.
	// 그런데, 캐스팅 없이 호출 가능하도록
	// BaseMenu 에서도 제공

//	virtual void add(BaseMenu*) = 0; // MenuItem 은 필요 없는데 만들어야 한다!!
//	virtual void add(BaseMenu*) {}; // MenuItem 은 만들필요 없지만 
									// MenuItem 에 대해서 호출시 아무일도 발생안함
									// 잘못 사용했는데, 에러도 없다!!
	virtual void add(BaseMenu*) { throw std::logic_error("unsupport operation"); }
	
	virtual BaseMenu* submenu(int idx) { throw std::logic_error("unsupport operation"); }
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
	BaseMenu* submenu(int idx) { return v[idx]; }
};

int main()
{
	PopupMenu* root = new PopupMenu("ROOT");

	root->add(new PopupMenu("색상변경"));
	root->add(new MenuItem("화면끄기", 11));


	// 해결책 #2. 캐스팅 없이 add 호출
	root->submenu(0)->add(new MenuItem("RED", 31)); 


	root->command();

}

// 7-1.cpp
// => safety 모델
// => 요즘은 이 스타일을 더 많이 사용.
// => 코드가 복잡해도, 안전하고 명확한 것이 좋다


// 7-2.cpp 
// => Transparency 모델
// => 편의성을 강조하는 모델.
// => 파이썬 처럼 "쉬운 코드 추구"
// => 잘못 사용시 예외 발생..
// => GoF's 패턴 책에는 이 모델을 더 강조 
