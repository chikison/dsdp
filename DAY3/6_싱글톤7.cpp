
#include <iostream>


class Cursor
{
private:
	Cursor() {}

	Cursor(const Cursor&) = delete;
	Cursor& operator=(const Cursor&) = delete;

public:

	// 아래 함수는 멀티스레드 환경에서 안전할까요?
	// => 오직 한개의 객체만 생성되고, Cursor 의 생성자 호출이 
	//    동기화 됨을 보장할수 있을까요 ?

	// C++11 부터 static 지역변수의 생성자 호출은
	// "언어" 자체에서 동기화 됨을 보장합니다.
	// 동기화 방식은 "spinlock(busy wait)" 입니다

	static Cursor& get_instance()
	{

		static Cursor instance;
		
		return instance;

	}
};






int main()
{
	Cursor& c1 = Cursor::get_instance();

}








