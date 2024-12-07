#include <iostream>


// 문법 이야기.. 

class Point
{
	int x = 0;
	int y = 0;
public:
	// #1. 멤버 함수는 인자로 this 가 추가 됩니다. 
	// => "this call" 이라고 합니다.
	// 사용자 코드			// 컴파일러가 변경한 코드
	void set(int a, int b)	// void set(Point* this, int a, int b)
	{						// {
		x = a;				//		this->x = a; 
		y = b;				//		this->y = b;  처럼 변경된것
	}

	// #2. static 멤버 함수는  this 가 추가되지 않는 멤버 함수 입니다.
	static void foo(int a)	// void foo(int a)
	{
		x = a;				// this->x = a; 가 되야 하는데.
	}						//			이 안에는 this 가없다.
							//			그래서, error.
};				
int main()
{
	Point::foo(10); // 객체 없이 호출. 전달될 객체가 없다.!
					// call Point::foo(10)

	Point p1;
	Point p2;

	p1.set(10, 20); // set(&p1, 10, 20)
	p2.set(10, 20); // set(&p2, 10, 20)
}