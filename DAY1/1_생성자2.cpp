// github.com/codenuri/dsdp/OT.txt 읽어 보세요

#include <iostream>

class Base
{
public:
	// 핵심 : Base 에는 디폴트 생성자(인자없는 생성자)가 없습니다.
	Base(int a) {  }
	~Base() {  }
};

class Derived : public Base
{
public:
	// 핵심 #1. 아래 코드가 왜 에러인지 생각해 보세요
//	Derived()		{ }		// Derived()	  : Base()	{ }
//	Derived(int a)	{ }		// Derived(int a) : Base()	{ }


	// 핵심 #2. 기반 클래스에 디폴트 생성자가 없다면 
	//         반드시 파생 클래스 생성자에서 에서 기반 클래스 생성자를
	//         호출하는 코드를 제공해야 합니다.
	Derived()      : Base(0) {}		
	Derived(int a) : Base(a) {}	


};

int main()
{

}
