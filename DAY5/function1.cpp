// function1.cpp
#include <iostream>
#include <functional>
using namespace std::placeholders; // _1, _2, _3, ... 10개 까지 
void f1(int n1) {}
void f2(int n1, int n2) {}

void f4(int a, int b, int c, int d)
{
	printf("%d, %d, %d, %d\n", a, b, c, d);
}

int main()
{
	f4(1, 2, 3, 4); // 4항 함수

	// std::bind : 함수의 인자를 고정한 새로운 함수를 만드는 도구
	// 사용법 : std::bind(M항함수주소, M개 인자 )

	auto a1 = std::bind(&f4, 1, 2, 3, 4); // 4항함수 => 0항함수

	a1(); // f4(1,2,3,4)


	auto a2 = std::bind(&f4, 5, _1, 7, _2);

	a2(3, 8); // f4(5, 3, 7, 8);


	auto a3 = std::bind(&f4, _2 , _3, 4, _1); // ? 위치 채우세요(4개..)

	a3(7, 3, 8); // f4(3, 8, 4, 7) 나오도록 ? 채우세요


	// 참고 std::bind 의 반환 타입은 어떻게 사용하냐에 따라 모두 다릅니다.
	// 따라서, a1, a2, a3 의 타입은 모두 다릅니다.
	// 그래서 auto 로 받은것입니다.

	// std::bind 같은 도구가 파이썬에도 있습니다
	// => functools.partial() 입니다.
}