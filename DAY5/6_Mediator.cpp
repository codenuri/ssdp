// Mediator - 171
#include <iostream>

class CheckBox
{
	bool state;
public:
	CheckBox() : state(false) {}
	
	void SetCheck(bool b) { state = b; ChangeState(); }
	bool GetCheck()       { return state; }

	virtual void ChangeState() {}
};

class MyCheckBox : public CheckBox
{
public:
	void ChangeState() override
	{
		std::cout << "check box 상태변경\n";

		if (GetCheck() == true)
		{
			std::cout << "enable button\n";
		}
		else 
			std::cout << "disable button\n";
	}
};


int main()
{
	MyCheckBox c;
	c.SetCheck(true);
}



