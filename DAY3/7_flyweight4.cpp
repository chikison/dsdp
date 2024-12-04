#include <iostream>

// 컴파일러와 flyweight

int main()
{
	// 아래 2줄의 차이점(메모리구조)를 생각해 보세요
	char sa[] = "hello";

//	char* sp = "hello";	// 이 코드는
						// C 언어 ok. C++ 에러

	const char* sp = "hello"; // C++도 ok..
							  // 문자열 포인터는 "char*" 가 아닌
							  // "const char*" 로 가리켜야 한다.


	*sa = 'X'; // ok. stack 은 R/W 가능
	*sp = 'X'; // char* sp 라면 runtime error. sp 가 가리키는 곳은 상수메모리
				// const char* sp 라면 compile-error
}