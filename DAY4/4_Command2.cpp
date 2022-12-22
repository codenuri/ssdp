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

// 도형을 추가하는 명령은 "유사한 코드가 많습니다"
// 기반 클래스를 만들어서 유사한 코드를 제공합니다.
class AddCommand : public ICommand
{
	std::vector<Shape*>& v;
public:
	AddCommand(std::vector<Shape*>& v) : v(v) {}

	virtual void execute()  override { v.push_back( CreateShape() ); }
	virtual bool can_undo() override { return true; }

	virtual void undo() override
	{
		Shape* p = v.back();
		v.pop_back();
		delete p;
	}
	
	// Factory Method 패턴
	// 객체를 만들기 위한 인터페이스를 정의하고 사용하지만
	// 어떤 종류의 객체를 만들지는 파생 클래스가 결정한다.
	// 객체의 종류를 파생 클래스가 결정하게 하는 패턴.!
	// 
	// => 기본 구조는 template method 와 동일한데...
	// => 변하는 가상함수가 하는 일이 "알고리즘"의 변경이 아닌
	//    "객체의 종류를 결정"합니다.
	virtual Shape* CreateShape() = 0;
};

class AddRectCommand : public AddCommand
{
public:
	using AddCommand::AddCommand;

	virtual Shape* CreateShape() override { return new Rect; }
};

class AddCircleCommand : public AddCommand
{
public:
	using AddCommand::AddCommand;

	virtual Shape* CreateShape() override { return new Circle; }
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
			pcmd = new AddRectCommand(v);
			pcmd->execute();
			cmd_stack.push(pcmd);
		}
		else if (cmd == 2)
		{
			pcmd = new AddCircleCommand(v);
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




