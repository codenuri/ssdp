#include <iostream>
#include <string>
#include <vector>
#include <conio.h> 

class MenuItem
{
	std::string title;
	int  id;
public:
	MenuItem(const std::string& title, int id) : title(title), id(id) {}

	std::string get_title() { return title; }

	void command()
	{
		std::cout << get_title() << " ¸Þ´º ¼±ÅÃµÊ" << std::endl;

		_getch(); 
	}
};


class PopupMenu
{
	std::string title;
	std::vector<MenuItem*> v;
public:
	PopupMenu(const std::string& title) : title(title) {}

	void add_menu(MenuItem* p) { v.push_back(p); }

	void command()
	{
		while (1)
		{
			system("cls"); 

			std::size_t sz = v.size();

			for (int i = 0; i < sz; i++)
			{
				std::cout << i + 1 << ". " << v[i]->get_title() << "\n";
			}
			std::cout << sz + 1 << ". Á¾·á\n";

			std::cout << "¸Þ´º¸¦ ¼±ÅÃÇÏ¼¼¿ä >> ";
			int cmd;
			std::cin >> cmd;

			if (cmd == sz + 1)
				return;       


			if (cmd < 1 || cmd > sz + 1)
				continue;

			v[cmd - 1]->command();
		}


	}
};




int main()
{
	MenuItem m1("¼Ò°í±â±è¹ä", 11);
	MenuItem m2("ÂüÄ¡±è¹ä",   12);

	PopupMenu pmkimbam("±è¹ä·ù");
	pmkimbam.add_menu(&m1);
	pmkimbam.add_menu(&m2);

	MenuItem m3("¶ó¸é", 21);

	PopupMenu pm("¿À´ÃÀÇ Á¡½É ¸Þ´º");
	pm.add_menu(&pmkimbam); // ÇÙ½É!!!
	pm.add_menu(&m3);

	pm.command();	
}




