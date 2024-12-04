// 7_싱글톤1 - 123 page
#include <iostream>

// 싱글톤 : 오직 한개의 객체만 존재하고,
//			프로그램에서 어디서도 동일한 방법으로 접근가능하게 한다.

// => 결국 전역변수와 같은 의미. 
// => 그런데, 전역변수는 좋지 않다고 사용하지 말라고 합니다.!!
// => 그래서, 싱글톤 패턴에 대한 비판이 많습니다.
// -------------------------------------------------

class Cursor
{
	// 규칙 #1. 생성자를 private 에
private:
	Cursor() {}

	// 규칙 #2. 컴파일러에게 복사생성자와 대입연산자를 만들지 못하게 한다.
	Cursor(const Cursor&) = delete;
	Cursor& operator=(const Cursor&) = delete; 
				// => 복사 금지시에는 대입도 금지 하는 것이 관례


	// 규칙 #3. 오직 한개를 만들어서 반환하는 static 멤버 함수
public:
	static Cursor& get_instance()
	{
		static Cursor instance;
		return instance;
	}
};

int main()
{
	Cursor& c1 = Cursor::get_instance();
	Cursor& c2 = Cursor::get_instance();

	std::cout << &c1 << std::endl;
	std::cout << &c2 << std::endl;

//	Cursor c3 = c1; // 일반 생성자가 아닌 컴파일러가 만드는 복사 생성자사용
					// 이렇게 만드는 것도 막아야 합니다.

//	Cursor c1, c2; // error
}

// 위 코드가 "effective-c++ 책" 의 저자인 "scott-meyer" 가 처음 만든 코드
// => "meyer's singleton" 이라고 하고
// 
// => 현재 C++ 진영에서 가장 좋은 코드라고 알려진 방식
// => 싱글톤 사용하려면 위코드로 하세요

// => 특징: 오직 한개의 객체가 static 지역변수인 모델







