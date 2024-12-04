//생성자1.cpp - 3page
#include <iostream>

class Base
{
public:
	Base()     { std::cout << "Base()" << std::endl; }
	Base(int a){ std::cout << "Base(int)" << std::endl; }
	~Base()    { std::cout << "~Base()" << std::endl; }
};
class Derived : public Base
{
public:						
	// 생성자 호출의 정확한 원리(C++, C#, Java 등 대부분 동일)
	// 사용자 코드			컴파일러가 변경한 코드
	Derived()			// Derived() : Base()
	{ 
		std::cout << "Derived()" << std::endl; 
	}
	Derived(int a)		// Derived(int a) : Base() <= 컴파일러가 추가한코드는
	{												// 항상 기반 클래스
													// 디폴트 생성자 호출
		std::cout << "Derived(int)" << std::endl; 
	}
	~Derived()		
	{ 
		std::cout << "~Derived()" << std::endl; 

		// 소멸자는 Derived 구현이 실행된후 Base 소멸자 호출
		// Base::~Base();
	}
};
int main()
{
//	Derived d1;
	Derived d2(5);
}
