#include <iostream>
#include <vector>
#include <stack>
#include "Helper.h"

class Shape
{
public:
	virtual void draw() = 0;
	virtual ~Shape() {}
};

class Rect : public Shape
{
public:
	void draw() override { std::cout << "draw Rect" << std::endl; }
};
class Circle : public Shape
{
public:
	void draw() override { std::cout << "draw Circle" << std::endl; }
};

struct ICommand
{
	virtual void execute() = 0;
	virtual bool can_undo() { return false; }
	virtual void undo() {}
	virtual ~ICommand() {}
};

template<typename T>
class AddCommand : public ICommand
{
	std::vector<Shape*>& v;
public:
	AddCommand(std::vector<Shape*>& v) : v(v) {}

	virtual void execute()  override { v.push_back(new T); }
	virtual bool can_undo() override { return true; }

	virtual void undo() override
	{
		Shape* p = v.back();
		v.pop_back();
		delete p;
	}
};



class DrawCommand : public ICommand
{
	std::vector<Shape*>& v;
public:
	DrawCommand(std::vector<Shape*>& v) : v(v) {}

	virtual void execute()  override
	{
		for (auto p : v) p->draw();
	}
	virtual bool can_undo() override { return true; }

	virtual void undo() override
	{
		system("cls");
	}
};

// 여러개의 명령을 보관했다가 한번에 실행하면 "매크로 명령"
// 을 만들어 봅시다.

class MacroCommand : public ICommand	 // Composite 패턴!!!
{
	std::vector<ICommand*> v;
public:
	void add_command(ICommand* p) { v.push_back(p); }

	void execute() { for (auto p : v) p->execute();	}
};










int main()
{
	std::vector<Shape*> v;

	ICommand* pcmd = nullptr;
	std::stack<ICommand*> cmd_stack;


	MacroCommand* mc1 = new MacroCommand;

	mc1->add_command(new AddCommand<Rect>(v));
	mc1->add_command(new AddCommand<Circle>(v));
	mc1->add_command(new DrawCommand(v));
	mc1->execute();


	MacroCommand* mc2 = new MacroCommand;

	mc2->add_command(new AddCommand<Rect>(v));

	mc2->add_command( mc1);

	mc2->execute();



	while (1)
	{
		int cmd;
		std::cin >> cmd;

		if (cmd == 1)
		{
			pcmd = new AddCommand<Rect>(v);
			pcmd->execute();
			cmd_stack.push(pcmd);
		}
		else if (cmd == 2)
		{
			pcmd = new AddCommand<Circle>(v);
			pcmd->execute();
			cmd_stack.push(pcmd);

		}
		else if (cmd == 9)
		{
			pcmd = new DrawCommand(v);
			pcmd->execute();
			cmd_stack.push(pcmd);

		}
		else if (cmd == 0)
		{
			if (!cmd_stack.empty())
			{
				pcmd = cmd_stack.top();
				cmd_stack.pop();

				if (pcmd->can_undo())
					pcmd->undo();

				delete pcmd;
			}
		}
	}
}




