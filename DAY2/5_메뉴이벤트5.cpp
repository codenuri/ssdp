// 5_메뉴이벤트5 - 1번 복사해오세요.
#include "PopupMenu.h"
#include <functional> // std::bind(), std::function<>
using namespace std::placeholders;

class MenuItem : public BaseMenu
{
	int  id;
	using HANDLER = std::function<void()>;  // typedef와 같습니다.

	std::vector< HANDLER > v;
public:
	MenuItem(const std::string& title, int id, HANDLER h = nullptr) 
		: BaseMenu(title), id(id) 
	{
		if ( h != nullptr )
			v.push_back(h);
	}

	void add_handler(HANDLER h) { v.push_back(h); }

	void command()
	{
		for (auto handler : v)
			handler();   // 결국 function 타입객체이므로
						 // 함수처럼 ()로 호출하면 됩니다.
	}
};
//====================================================
void f0()       { std::cout << "f0" << std::endl; }
void f1(int id) { std::cout << "f1 : " << id << std::endl; }

class Dialog
{
public:
	void close() { std::cout << "Dialog Close" << std::endl; }

	static void foo() { std::cout << "Dialog foo" << std::endl; }
};
//-------------------------------------------------

int main()
{
	PopupMenu* root = new PopupMenu("ROOT");

	// 1. f0은 "void()" 모양이므로 std::bind()필요 없습니다.
	root->add_menu(new MenuItem("메뉴1", 11, &f0));

	// 2. 인자가 다른 함수는 std::bind()로 "0항함수"로 만들어야 합니다.
	root->add_menu(new MenuItem("메뉴2", 12, std::bind(&f1, 12)));
	root->add_menu(new MenuItem("메뉴3", 13, std::bind(&f1, 13)));

	// 3. 멤버 함수를 객체도 필요 합니다.
	Dialog dlg;
	root->add_menu(new MenuItem("메뉴4", 14, std::bind(&Dialog::close, &dlg)));

	// 4. static 멤버 함수는 객체 없어도 됩니다.
	root->add_menu(new MenuItem("메뉴5", 16, &Dialog::foo));


	MenuItem* m = new MenuItem("메뉴6", 17);
	root->add_menu(m);

	// 5. 람다 표현식도 됩니다.
	m->add_handler([]() { std::cout << "lambda" << std::endl; });

	// 6. 하나의 메뉴에 여러개 등록 해도 됩니다.
	m->add_handler(&f0);
	

	root->command();
}





