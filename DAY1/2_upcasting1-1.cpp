// 2_upcasting1-1.cpp 
#include <iostream>

class Animal
{
public:
	int age;

	virtual ~Animal() {} // 가상 소멸자, 다음시간에 자세히 배우는 문법
						// 지금은 "Animal 에 가상함수가 있다" 만 생각하세요
};

class Dog : public Animal
{
public:
	int color;
};
class Cat : public Animal
{
public:
	int speed;
};

int main()
{
	Dog d;
	Cat c;

	Animal* p1 = &c;

	// 핵심 #1. p1이 가리키는 객체는 실행 시간에 변경될수 있습니다.
	// => 따라서 p1 이 어떤 객체를 가리키는지는 컴파일 시간에는
	//   알수 없습니다
	//if (사용자입력 == 1) p1 = &d;

	// static_cast : 컴파일 시간 캐스팅
	// => 컴파일러는 컴파일 시간에 p1이 가리키는 곳을 알수도 없고, 
	//    조사할수 없습니다.
	// => 따라서 아래 코드는 항상 성공합니다.(잘못된 캐스팅이지만)
	//    이경우 pdog 를 사용하면 "미정의 동작 발생"
	// => 결론, p1 이 가리키는 곳이 Dog 라는 확신이 있을때만
	//    static_cast 해야 합니다.
	Dog* pdog1 = static_cast<Dog*>(p1);
	
	std::cout << pdog1 << std::endl;

	// dynamic_cast : 실행시간 캐스팅
	//				  실행시간에 p1이 가리키는 곳을 조사해서
	//				  Dog 가 맞을때만 캐스팅 성공.
	//				  Dog 가 아닌 경우 0 반환

	// 단, dynamic_cast 를 사용하려면, 객체 생성시 타입정보가 같이 
	// 메모리에 있어야 합니다.
	// C++은 가상함수 테이블을 사용해서 타입 정보를 관리합니다.
	// => 따라서, dynamic_cast 를 사용하려면 
	//    가상함수가 1개 이상 있는 타입만 가능합니다.

	Dog* pdog2 = dynamic_cast<Dog*>(p1);

	std::cout << pdog2 << std::endl;
}











