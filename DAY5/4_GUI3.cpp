#define USING_GUI
#include "cppmaster.h" 


class Window
{
	int handle;
public:
	void create(const std::string& title)
	{
		handle = ec_make_window(msgproc, title);

		ec_set_window_rect(handle, 0, 0, 300, 300);
	}


	static int msgproc(int hwnd, int msg, int a, int b)
	{
		switch (msg)
		{
		case WM_LBUTTONDOWN: 
			lbutton_down();		// 모든 멤버함수는 "객체.함수()"가 되야 합니다
								// this->lbutton_down() 으로 변경되야하는데
								// (thiscall1.cpp 의 this->x 와 같은원리)
								// msgproc 은 static 이므로	this가 없습니다
								// 그래서 error
								// => 해결책은 다음소스에서.. !
			break;
		case WM_KEYDOWN:     key_down(); break;
		}
		return 0;
	}

	virtual void lbutton_down() {}
	virtual void key_down() {}
};


int main()
{
	Window w;
	w.create("hello"); 

	ec_process_message();
}

