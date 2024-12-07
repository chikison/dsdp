#define USING_GUI
#include "cppmaster.h" 
#include <map>


class Window;

std::map<int, Window*> this_map;


// 클래스 템플릿 만들때
// => T를 사용하지 않은 멤버가 있다면
// => 템플릿을 사용하지 않는 멤버를 기반 클래스 만들어서 제공해라!!
// => "thin template" 또는 "template hoisting" 이라고 불리는 기술(C++ IDioms)

class Window
{
protected:
	int handle;

public:
	// 메세지 처리 관련된 수백개 함수
	void lbutton_down() {}
	void key_down() {}
	
	// move(), hide(), set_title(), set_top_most()등
	// 윈도우 제어 관련 수십개 함수를 여기서
};


template<typename T>
class MsgWindow : public Window
{

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

};

class MainWindow : public MsgWindow<MainWindow>
{
public:
	void lbutton_down() {	std::cout << "MainWindow lbutton_down()\n";	}
};





int main()
{
	MainWindow w1;
	w1.create("MainWindow");


	ec_process_message();
}



// GUI4.cpp : event 처리를 가상함수에 의존하는 코드(template method)
//			 => 가상함수 테이블의 오버헤드가 있습니다.

// GUI9.cpp : event 처리를 CRTP 기술로 해결하는 코드
//			=> WTL(Window Template Library) 이라는 라이브러리 이 기술 사용
//			  (office 만들때 사용한 MS 의 라이브러리)