#include <iostream>

// 가상소멸자 

class Base
{
public:
//	~Base() {}
	virtual ~Base() {}  // 가상 소멸자 
						// 기반 클래스 소멸자가 virtual 이면
						// 파생 클래스 소멸자도 모두 자동으로 virtual 입니다.
};
class Derived : public Base
{
public:
	Derived()  { std::cout << "Derived() 자원할당" << std::endl; }
	~Derived() { std::cout << "~Derived() 자원해지" << std::endl; }
};
int main()
{
//	Derived d; // ok. 아무 문제 없는 코드

//	Derived* p = new Derived; // ok. 아무 문제 없는 코드
//	delete p;

	// 아래 코드가 핵심
	Base* p = new Derived; // Derived 생성자 호출
	delete p;	// 객체가 파괴 되므로 소멸자가 호출되어야 한다.
				// 1. p->소멸자()
				// 2. 메모리 파괴
				
	// 그런데, 소멸자 호출도 "멤버함수의 호출" 개념이므로
	// "p->소멸자()" 의 모양입니다.
	
	// p 가 Base* 이므로 컴파일러는
	// 1. Base 클래스 선언을 보고 소멸자가 virtual 인지 조사
	// 2. 소멸자가
	// 가상함수가 아니면 : static binding, p의 포인터 타입으로 결정
	// 가상함수라면      : dynamic binding. 메모리 조사후 결정

}	

