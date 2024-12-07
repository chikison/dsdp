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

	// 핵심 : 아래 함수가 static 이어야 하는 이유를 반드시 알아야 합니다.
	// => C언어에서 다른 함수의 인자로 전달되는 함수(Call back 함수)
	//    를 C++ 언어로 만들때는 "반드시 static 멤버 함수" 이어야 합니다.

	static int msgproc(int hwnd, int msg, int a, int b)
	{
		switch (msg)
		{
		case WM_LBUTTONDOWN: std::cout << "LBUTTON" << hwnd << std::endl; break;
		case WM_KEYDOWN:     std::cout << "KEYDOWN" << hwnd << std::endl; break;
		}
		return 0;
	}
};


int main()
{
	Window w;
	w.create("hello"); // 이순간 윈도우가 생성되어야 합니다.

	ec_process_message();	
}

