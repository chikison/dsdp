// function1.cpp
#include <iostream>
#include <functional>
using namespace std::placeholders; 

void f1(int n1) {}
void f2(int n1, int n2) {}

void f4(int a, int b, int c, int d)
{
	printf("%d, %d, %d, %d\n", a, b, c, d);
}

int main()
{
	// C의 함수 포인터는 유연성이 부족합니다.
	/*
	void(*f)(int);

	f = &f1; // ok.. signature가 동일
	f = &f2; // error. 즉, 인자의 갯수가 다르면 담을수 없습니다.
	*/

	// C++ 에서는 함수 포인터의 일반화된 형태인 std::function<> 제공

	std::function<void(int)> f; // void(*f)(int) 와 유사

	f = &f1; // ok
	f(10);   // f1(10).. 즉, 함수포인터와 동일하게 사용

//	f = &f2; // error. 인자의 갯수가 다름

	// 핵심 : std::function<> 는 std::bind이 결과를 담을수 있습니다.
	// => 인자가 1개 이상인 모든 함수는 
	// => std::bind 사용시, 인자가 1개로 만들수 있습니다.

	f = std::bind(&f2, 3, _1);
	f(5); // f2(3, 5)


	f = std::bind(&f4, 1, 2 , _1 , 3);
	f(5); // f4(1, 2, 5, 3) 되게 해보세요
}