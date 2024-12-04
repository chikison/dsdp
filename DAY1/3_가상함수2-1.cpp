#include <iostream>

// 아래 와 같은 코드가 없으면 소멸자가 가상이 아니어도 됩니다.
// => 가상함수를 느립니다.
// Base* p = new Derived;
// delete p;

// 또다른 해결책

class Base
{

protected:
	~Base() {}	
};

class Derived : public Base
{
public:
	Derived() { std::cout << "Derived() 자원할당" << std::endl; }
	~Derived() { std::cout << "~Derived() 자원해지" << std::endl; }
};
int main()
{
	Base* p = new Derived;

//	delete p;	// 컴파일 에러, protected 소멸자

	delete  static_cast<Derived*>(p); // ok

}

// 구글, "C++ core guideline" 검색
// 1번째 링크 선택
// => C++ 창시자와 표준 위원장을 했던 개발자가 만들고 있는 
//    guide line

 