#include <iostream>
#include <string>
#include <vector>
#include <stack>

class Shape
{
public:
	virtual void draw() = 0;
	virtual ~Shape() {}
};

class Rect : public Shape
{
public:
	void draw() override { std::cout << "draw rect" << std::endl; }
};

class Circle : public Shape
{
public:
	void draw() override { std::cout << "draw circle" << std::endl; }
};
//--------------------------------------------------
struct ICommand
{
	virtual void execute() = 0;
	virtual bool can_undo() { return false; }
	virtual void undo() {}

	virtual ~ICommand() {}
};

// 프로그램에서 사용하는 모든 명령(작업)을 클래스로 설계합니다.
class AddRectCommand : public ICommand
{
	std::vector<Shape*>& v;
public:
	AddRectCommand(std::vector<Shape*>& v) : v(v) {}

	void execute() override { v.push_back(new Rect);}

	bool can_undo() override { return true; }

	void undo() override
	{
		Shape* s = v.back(); // 반환만
		v.pop_back();		 // 제거
		delete s;
	}
};

class AddCircleCommand : public ICommand
{
	std::vector<Shape*>& v;
public:
	AddCircleCommand(std::vector<Shape*>& v) : v(v) {}

	void execute() override { v.push_back(new Circle); }

	bool can_undo() override { return true; }

	void undo() override
	{
		Shape* s = v.back(); // 반환만
		v.pop_back();		 // 제거
		delete s;
	}
};

class DrawCommand : public ICommand
{
	std::vector<Shape*>& v;
public:
	DrawCommand(std::vector<Shape*>& v) : v(v) {}

	void execute() override 
	{ 
		for (auto e : v)
			e->draw();
	}

	bool can_undo() override { return true; }

	void undo() override
	{
		system("cls");
	}
};

int main()
{
	std::vector<Shape*> v;

	std::stack<ICommand*> undo_stack;
	std::stack<ICommand*> redo_stack;

	ICommand* command = nullptr;

	while (1)
	{
		int cmd;
		std::cin >> cmd;	

		if (cmd == 1)
		{
			command = new AddRectCommand(v);
			command->execute();

			undo_stack.push(command); // undo 를 위해서 보관
		}
		else if (cmd == 2) 
		{
			command = new AddCircleCommand(v);
			command->execute();

			undo_stack.push(command);
		}
		else if (cmd == 9)
		{
			command = new DrawCommand(v);
			command->execute();

			undo_stack.push(command);
		}

		else if (cmd == 0)
		{
			if (!undo_stack.empty())
			{
				command = undo_stack.top(); // 반환만되고
				undo_stack.pop();			// 실제 제거는 여기서

				if (command->can_undo())
				{
					command->undo();
				}

				delete command; // redo 도 지원하려면 지우지 말고
								// redo_stack.push(command)
			}
		}
	}
}

// C++ 로 만든 GUI 라이브러리인 QT 에 보면 "UndoManager" 가 있습니다.
// C# WPF 라이브러리는 메뉴 이벤트 처리를 위해 "class" 로 만드는 것을 권장합니다.
// => 모두 "Command" 패턴 입니다.



// 함수 : 동작 한개만 정의 합니다.(execute, 즉, 해야 할일)
//		  데이타 보관 안됨
// 
// class : 동작 여러개 정의 가능(멤버 함수 여러개, execute, undo 등)
//		   데이타 보관 가능(멤버데이타)
//		   undo 를 위한 데이타 보관 가능

