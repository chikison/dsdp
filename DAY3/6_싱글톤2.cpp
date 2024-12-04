#include <iostream>

// static 지역변수 vs static 멤버 데이타 

// static 지역변수 : get_instance() 가 호출되지 않으면 생성되지 않는다.
//					get_instance() 가 처음 호출될때 Cursor 생성(생성자 호출)
//					=> 지연된 초기화. 필요한 경우만(때에) 만들겠다
//

// static 멤버 데이타 : get_instance() 가 호출되지 않아도 Cursor 생성
//					=> 프로그램이 처음 load될때(main함수 호출이전)에 
//						생성자 호출
//					=> 이른(early) 초기화
//					=> 런칭시에 모든 초기화 하고, 실행중에는 빠르게 하고 싶을때
//						이방식도 나쁘지 않다.


class Cursor
{
private:
	Cursor() { std::cout << "Cursor()\n"; }

	Cursor(const Cursor&) = delete;
	Cursor& operator=(const Cursor&) = delete;

//	Cursor instance;		// 이코드는 에러 지만
	static Cursor instance; // 이 코드는 에러 아닙니다.
public:
	static Cursor& get_instance()
	{
//		static Cursor instance;

		return instance;
	}
};
Cursor Cursor::instance;


int main()
{
	std::cout << "main\n";

	Cursor& c1 = Cursor::get_instance();

}







