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

// C 언어 : 프로그램의 기본은 "함수"
// => 메뉴 선택시 해야할 일을 함수로 작성
// => "해야할 일" 만 작성한다.

// C++ 언어 : 프로그램의 기본은 "클래스"
// => 메뉴 선택시 해야할 일을 클래스로 작성
// => "해야할 일 + 취소동작 + 기타 멤버" 등을 묶어서 관리할수 있다.

//----------------------------------------------------------
// 모든 명령은 아래 인터페이스를 구현해야 한다.
struct ICommand
{
	virtual void execute() = 0;
	virtual bool can_undo() { return false; }
	virtual void undo() {}
	virtual ~ICommand() {}
};

// 사각형을 추가하는 메뉴에 대한 명령객체
class AddRectCommand : public ICommand
{
	std::vector<Shape*>& v;
public:
	AddRectCommand(std::vector<Shape*>& v) : v(v) {}

	virtual void execute()  override { v.push_back(new Rect); }
	virtual bool can_undo() override { return true; }

	virtual void undo() override
	{
		Shape* p = v.back();
		v.pop_back();

		delete p;
	}
};

class AddCircleCommand : public ICommand
{
	std::vector<Shape*>& v;
public:
	AddCircleCommand(std::vector<Shape*>& v) : v(v) {}

	virtual void execute()  override { v.push_back(new Circle); }
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

				delete pcmd;		// redo 하려면 delete 하지 말고
									// redo_stack.push(pcmd) 하면 됩니다.
			}
		}
	}
}




