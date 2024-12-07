#define USING_GUI
#include "cppmaster.h" 
#include <map>

class Window;

std::map<int, Window*> this_map; 


class Window
{
	int handle;
public:
	void create(const std::string& title)
	{
		handle = ec_make_window(msgproc, title);
		ec_set_window_rect(handle, 0, 0, 300, 300);

		this_map[handle] = this;
	}


	static int msgproc(int hwnd, int msg, int a, int b)
	{
		Window* self = this_map[hwnd];

		switch (msg)
		{
		case WM_LBUTTONDOWN:
			self->lbutton_down();
					// => self 는 Window* 타입이고
					// => lbutton_down() 은 가상이 아니므로 static binding
					// => 따라서, 포인터 타입인 Window 의 lbuttondown 호출
					// => MainWindow 것을 호출할수 없다.!!!
					// => 해결은 다음소스
			break;

		case WM_KEYDOWN:
			self->key_down();
			break;
		}
		return 0;
	}
	void lbutton_down() {}
	void key_down() {}
};

class MainWindow : public Window
{
public:
	void lbutton_down() 
	{
		std::cout << "MainWindow lbutton_down()\n";
	}
};


int main()
{
	MainWindow w1;
	w1.create("MainWindow");


	ec_process_message();
}

