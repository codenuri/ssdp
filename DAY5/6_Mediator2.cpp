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

class RadioBox
{
	bool state;
public:
	RadioBox() : state(false) {}
	
	void SetCheck(bool b) { state = b; ChangeState(); }
	bool GetCheck()       { return state; }

	virtual void ChangeState() {}
};
//------------------------------------------
// 체크 박스 2개와 라디오박스 2개가 필요합니다
// 단점 : 아래 처럼 만들면 4개의 객체가 서로를 알고 있어야 합니다.
//        하나의 객체의 상태 변화시 나머지 객체의 상태를 조사하느 코드가
//        4개의 객체 모두에 있어야 합니다.
//        객체의 관계가 너무 복잡해 집니다. - "중간층(중재자)"가 있으면
//											편리합니다.
class MyCheck : public CheckBox
{
public:
	void ChangeState()
	{
		// 체크박스 2개가 모두 체크 되고 라디오1이 체크 되어야만 버튼이
		// enable 된다고 가정합니다.
		if ( GetCheck() == true  &&
			 check2.GetCheck() == true &&
			 radio1.GetCheck() == true &&
			 radio2.GetCheck() == false)
		{
			cout << "Button Enable" << endl;
		}
		else
		{
			cout << "Button Disable" << endl;
		}
	}
};
int main()
{
}











