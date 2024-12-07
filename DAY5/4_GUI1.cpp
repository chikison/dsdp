// GUI1.cpp
// => 32bit 로 빌드해야 합니다.
// => "x64" 말고 "x86"

#define USING_GUI
#include "cppmaster.h" // 이 안에 ec_make_window() 등이 있습니다


int foo(int hwnd, int msg, int a, int b) 
{
	switch (msg)
	{
	case WM_LBUTTONDOWN: std::cout << "LBUTTON" << hwnd << std::endl; break;
	case WM_KEYDOWN:     std::cout << "KEYDOWN" << hwnd << std::endl; break;
	}
	return 0;
}

int main()
{
	int h1 = ec_make_window(foo,  // 이벤트 처리함수 주소(인자가 반드시 int 4개이어야 합니다.)
							"A"); // 캡션 문자열

	int h2 = ec_make_window(foo, "B");

	
	// 크기 변경
	ec_set_window_rect(h1, 100, 100, 400, 400);
	ec_set_window_rect(h2, 100, 100, 300, 300);

	// 색상 변경
	ec_set_window_color(h2, Color(255, 0, 0) );

	// 자식윈도우로 부착
	ec_add_child(h1, h2); // h2 를 h1 의 자식 윈도우로 부착


	ec_process_message();	// 프로그램을 종료 하지 말고
							// event 루프를 실행해 달라.
}

