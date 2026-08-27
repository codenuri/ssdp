#include <iostream>
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


// 모든 명령에 대한 인터페이스
struct ICommand
{
	virtual void execute() = 0;
	virtual bool can_undo() { return false; }
	virtual void undo() {}
	virtual ~ICommand() {}
};

// 사각형을 추가하는 명령
class AddRectCommand : public ICommand
{
	std::vector<Shape*>& v;
public:
	AddRectCommand(std::vector<Shape*>& v) :v(v) {}

	void execute() override { v.push_back(new Rect); }

	bool can_undo() { return true; }

	void undo() 
	{
		Shape* s = v.back();
		v.pop_back();
		delete s;
	}
};

class AddCircleCommand : public ICommand
{
	std::vector<Shape*>& v;
public:
	AddCircleCommand(std::vector<Shape*>& v) :v(v) {}

	void execute() override { v.push_back(new Circle); }

	bool can_undo() { return true; }

	void undo()
	{
		Shape* s = v.back();
		v.pop_back();
		delete s;
	}
};

class DrawCommand : public ICommand
{
	std::vector<Shape*>& v;
public:
	DrawCommand(std::vector<Shape*>& v) :v(v) {}

	void execute() override 
	{ 
		for (auto s : v)
			s->draw();
	}

	bool can_undo() { return true; }

	void undo() { system("cls");}
};

int main()
{
	std::vector<Shape*> v;

	std::stack<ICommand*> cmd_stack; // undo 를 위해서 모든 명령을 보관

	ICommand* command = nullptr;

	while (1)
	{
		int cmd;
		std::cin >> cmd;

		if (cmd == 1)
		{
			command = new AddRectCommand(v);
			command->execute();
			cmd_stack.push(command);
		}
		else if (cmd == 2)
		{
			command = new AddCircleCommand(v);
			command->execute();
			cmd_stack.push(command);
		}
		else if (cmd == 9)
		{
			command = new DrawCommand(v);
			command->execute();
			cmd_stack.push(command);
		}
	}
}




