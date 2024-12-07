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

// 각 스타일의 컨트롤의 이름만 관리하는 타입(구조체) 설계
struct WinStyle
{
	// 타입(클래스)의 이름만 약속된 별명으로 관리하는 구조체
	using Button = WinButton;
	using Edit = WinEdit;

	// 그외 모든 Windows 스타일 컨트롤의 이름만 관리 합니다.
};

struct OSXStyle
{
	using Button = OSXButton;
	using Edit = OSXEdit;		// typedef OSXEdit Edit;
};



template<typename T>
class Dialog
{
public:
	void init()
	{
		IButton* btn = new typename T::Button;
		IEdit* edit = new typename T::Edit;

		// btn->Move(); edit->Move();

		btn->Draw();
		edit->Draw();
	}
};



int main(int argc, char** argv)
{
	Dialog<WinStyle> dlg1;
	Dialog<OSXStyle> dlg2;
}








