// 6_Mediator - 중재자 패턴 
#include <iostream>
#include <conio.h>

class CheckBox
{
	bool state;
public:
	CheckBox() : state(false) {}
	
	void SetCheck(bool b) { state = b; ChangeState(); }
	bool GetCheck()       { return state; }

	// 체크 상태가 변경될때마다 호출되는 가상함수
	virtual void ChangeState() {}
};

class MyCheckBox : public CheckBox
{
public:
	void ChangeState() override
	{
		if (GetCheck() == true)
			std::cout << "enable button\n";
		else 
			std::cout << "disable button\n";
	}
};

int main()
{
	MyCheckBox c;
	_getch(); c.SetCheck(true);
	_getch(); c.SetCheck(false);
}



