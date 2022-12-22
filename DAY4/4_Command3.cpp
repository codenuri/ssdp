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

//----------------------------------
// 요즘 C++ 에서는 "Factory Method" 패턴은 거의 사용하지 않습니다.
// => "template" 등을 사용하면 더 편리합니다.

template<typename T>
class AddCommand : public ICommand
{
	std::vector<Shape*>& v;
public:
	AddCommand(std::vector<Shape*>& v) : v(v) {}

	virtual void execute()  override { v.push_back( new T ); }
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



int main()
{
	std::vector<Shape*> v;

	ICommand* pcmd = nullptr;

	std::stack<ICommand*> cmd_stack;

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




