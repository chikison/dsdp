// 구현계층
// Point 의 모든 기능은 이 클래스가 구현
// PointImpl.h
class PointImpl
{
	int x, y;
	int debug;
public:
	void print();
};

// PointImpl.cpp
#include "PointImpl.h"

void PointImpl::print() {} 



// 아래클래스가 추상층(간접층)
// 구현자체는 없지만
// 사용자는 이 클래스 사용합니다.
// Point.h
//#include "PointImpl.h"
class PointImpl; // 클래스 전방선언만 있어도
				 // 포인터 변수는 사용가능
class Point
{
	PointImpl* impl;
public:
	Point();
	void print();
};

// Point.cpp
#include "Point.h"
#include "PointImpl.h"

Point::Point() { impl = new PointImpl;  }
void Point::print() { impl->print(); }




// main.cpp
#include "Point.h"
int main()
{
	Point p;
	p.print();
}

// 위 기술은 결국 "Bridge" 패턴인데

// C++에서는 "PIMPL" 이라고도 부릅니다.

// "Pointer to IMPLementation"

// 장점 1. 컴파일러 방화벽,컴파일 속도 증가
//		  PointImpl.h 가 변해도
//		  최종 사용자 코드는 재 컴파일 필요 없다.
//        (중간층만 재컴파일 하면 된다.)

// 장점 2. 완벽한 정보 은닉
//		  구현의 헤더를 노출할 필요 없다.
//		  간접층의 헤더만 노출하면된다.
