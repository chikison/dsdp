#define USING_GUI
#include "cppmaster.h" 
#include <map>

class Window;

std::map<int, Window*> this_map; // this를 보관하기 위한 맵


class Window
{
	int handle;
public:
	void create(const std::string& title)
	{
		handle = ec_make_window(msgproc, title);

		ec_set_window_rect(handle, 0, 0, 300, 300);

		// 핵심. static 멤버함수인 msgproc 에서 this를 사용하기 위해
		//      자료구조에 this를 보관합니다.
		this_map[handle] = this;
	}


	static int msgproc(int hwnd, int msg, int a, int b)
	{
		Window* self = this_map[hwnd];

		// 이제 self 가 객체의 주소인 this 의 의미 입니다.
		// "self->" 로 접근하면
		// static 멤버 함수인 이 안에서, 모든 멤버 접근 가능합니다.

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

	virtual void lbutton_down() {}
	virtual void key_down() {}
};

// 위 코드의 의도는 결국
// Window 의 파생클래스를 만들어서 event 처리를 위해 "약속된 가상함수"를
// override 하라는 것
class MainWindow : public Window
{
public:
	void lbutton_down() override 
	{
		std::cout << "MainWindow lbutton_down()\n";
	}
};

class ImageView : public Window
{
public:
	void lbutton_down() override
	{
		std::cout << "ImageView lbutton_down()\n";
	}
};

int main()
{
	MainWindow w1;
	w1.create("MainWindow");

	ImageView w2;
	w2.create("ImageView");

	ec_process_message();
}

