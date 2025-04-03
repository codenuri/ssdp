// 5_���丮�޼ҵ� - 148
#include <iostream>

// ��� ������ ��Ʈ���� ������ ��� Ŭ���� �ʿ�
struct IButton
{
	virtual void Draw() = 0;
	virtual ~IButton() {}
};
struct IEdit
{
	virtual void Draw() = 0;
	virtual ~IEdit() {}
};


struct WinButton : public IButton
{
	void Draw() { std::cout << "Draw WinButton" << std::endl; }
};
struct WinEdit : public IEdit
{
	void Draw() { std::cout << "Draw WinEdit" << std::endl; }
};

struct OSXButton : public IButton
{
	void Draw() { std::cout << "Draw OSXButton" << std::endl; }
};
struct OSXEdit : public IEdit
{
	void Draw() { std::cout << "Draw OSXButton" << std::endl; }
};
//--------------------------------------
// ���� �̾߱� 
#include <memory>

class Dialog
{
public:
	void init()
	{
		auto btn = CreateButton();
		auto edit = CreateEdit();
		btn->Draw();
		edit->Draw();
	}
	virtual std::unique_ptr<IButton> CreateButton() = 0;
	virtual std::unique_ptr<IEdit> CreateEdit() = 0;
};
// ���������� �Ʒ�ó�� ����Ʈ �����͸� ����ϴ°� ���� �����ϴ�.
// => �޸� ������ ���ؼ�. 
class WinDialog : public Dialog
{
public:
	std::unique_ptr<IButton>  CreateButton() override
	{
		return std::make_unique<WinButton>();
	}
	std::unique_ptr<IEdit> CreateEdit()     override 
	{ 
		return std::make_unique<WinEdit>();
	}
};

int main(int argc, char** argv)
{

}








