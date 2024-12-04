#include <iostream>

class Animal
{
public:
	void cry() { std::cout << "Animal cry" << std::endl; } 
};
class Dog : public Animal
{
public:
	// 함수 override : 기반 클래스 함수를 파생 클래스가 다시 만드는 것
	void cry() { std::cout << "Dog cry" << std::endl; } 
};
int main()
{
	Animal a; a.cry(); // "Animal cry"
	Dog d;	  d.cry(); // "Dog cry" 

	Animal* p = &d; // 객체는 Dog 인데, 포인터는 Animal* 타입

//	if (사용자입력 == 1)  p = &a;

	p->cry(); // 이 코드는 어떤 함수를 호출할까요 ?
			  // 어떤 함수를 호출하는것이 논리적으로 맞을까요 ? - Dog가 맞다
			  // C++/C# : Animal Cry
			  // Java, Swift, Python, kotlin등 대부분의 객체지향 언어 : Dog Cry
}

// p->cry() 를 어떤 함수와 연결할것인가 ?
// => 함수 바인딩(binding) 이라고 합니다.
// => 2가지 방식이 있습니다.

// static binding : 컴파일 시간에 컴파일러가 결정
//					핵심 : 컴파일러는 p가 가리키는 객체 자체는 알수 없다.
//						   컴파일러는 p 자체의 타입만 알수 있다.
//					따라서 컴파일러가 결정하면 "p가 Animal*" 이므로
//					Animal Cry
// 빠르지만, 논리적이지 않다.
// C++/C# 의 기본 바인딩 정책 

// dynamic binding : 실행시간에 결정
//					컴파일 시간에는 p가 가리키는 메모리를 조사하는기계어생성
//					실행시 "메모리를 조사해서 함수 호출을 결정"
//					p가 가리키는 곳에 Dog 가 있었다면 
//					"Dog Cry" 호출
// 느리지만, 논리적이다.
// Java, Swift, Kotlin, Python 등 대부분의 객체지향 언어.
// C++/C# virtual function 
