// 5_팩토리메소드
#include <iostream>

// 모든 종류의 컨트롤은 공통의 기반 클래스 필요
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

class BaseDialog
{
public:
	void init()
	{
		IButton* btn = CreateButton();
		IEdit* edit = CreateEdit();
		// btn->Move(); edit->Move();

		btn->Draw();
		edit->Draw();
	}
	// 결국 Dialog 의 모든 로직은 동일한데..
	// Dialog 가 사용하는 부품의 타입만 다르다.
	// (어떤 타입의 컨트롤을 사용할지는 파생 클래스가 결정)
	// Factory method
	// => 객체를 만들기 위한 인터페이스를 제공하고 사용하지만
	//    어떤 종류인지는 파생클래스가 결정

	virtual IButton* CreateButton() = 0;
	virtual IEdit* CreateEdit() = 0;
};


class WinDialog : public BaseDialog
{
public:
	IButton* CreateButton() override { return new WinButton; }
	IEdit* CreateEdit() override { return new WinEdit; }
};

class OSXDialog : public BaseDialog
{
public:
	IButton* CreateButton() override { return new OSXButton; }
	IEdit* CreateEdit() override { return new OSXEdit; }
};
class MixDialog : public BaseDialog
{
public:
	IButton* CreateButton() override { return new OSXButton; }
	IEdit* CreateEdit() override { return new WinEdit; }
};


int main(int argc, char** argv)
{

}








