#define USING_GUI
#include "cppmaster.h" 
#include <map>


// CRTP 기술사용
// => 그런데, Window 가 template 이므로 아래 처럼 Window 만 사용은 안됨.
// => 에러는 다음단계에서 해결

class Window;

std::map<int, Window*> this_map;



template<typename T>
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
		T* self = static_cast<T*>(this_map[hwnd]);

		switch (msg)
		{
		case WM_LBUTTONDOWN:
			self->lbutton_down();
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

class MainWindow : public Window<MainWindow>
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

