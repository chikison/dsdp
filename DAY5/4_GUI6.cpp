#define USING_GUI
#include "cppmaster.h" 
#include <vector>
#include <map>

class Window;

std::map<int, Window*> this_map;


class Window
{
	int handle;

	Window* parent = nullptr; 
	std::vector<Window*> child_vector; 
public:
	void add_child(Window* cw)
	{
		cw->parent = this;
		child_vector.push_back(cw);
		ec_add_child(this->handle, cw->handle);
		ec_set_window_rect(cw->handle, 50, 50, 200, 200); 
	}

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
			self->handle_lbutton_down(); // 책임의 전가를 구현한 함수
			break;

		case WM_KEYDOWN:
			self->key_down();
			break;
		}
		return 0;
	}

	// 아래 코드가 "chain of responsibility" 의 핵심입니다.
	void handle_lbutton_down()
	{
		// #1. 자신이 먼저 처리를 시도
		if (lbutton_down() == true)
			return;

		// #2. 처리하지 않은 경우 부모 윈도우가 있다면 전달
		if (parent != nullptr)
			parent->handle_lbutton_down();
	}

	virtual bool lbutton_down() { return false; }

	virtual void key_down() {}
};


class MainWindow : public Window
{
public:
	bool lbutton_down() override
	{
		std::cout << "MainWindow lbutton_down()\n";
		return true;
	}
};

class ImageView : public Window
{
public:
	bool lbutton_down() override
	{
		std::cout << "ImageView lbutton_down()\n";

//		return true;	// 이벤트 처리를 끝내겠다는것
		return false;	// 부모윈도우 에게도 이벤트를 전달해 달라는 의도
	}
};

int main()
{
	MainWindow w1;
	w1.create("MainWindow");

	ImageView w2;
	w2.create("ImageView");


	w1.add_child(&w2);

	ec_process_message();
}

// 대부분의 GUI 라이브러리는 위 코드 처럼
// 자식윈도우에서 발생된 이벤트가 부모윈도우에게도 전달됩니다.

// C# WPF : bubbling event 라고 부릅니다.

// IOS : Responder Chain 이라고 부릅니다.

// C++ MFC : Message Routing 이라고 부릅니다.
