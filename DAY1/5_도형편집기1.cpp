// 15page ~ 
#include <iostream>
#include <vector>

// 파워 포인트 값은 프로그램을 객체지향으로 만드는 방법을 생각해 봅시다.
// #1. 모든 도형을 타입으로 설계해야 한다. (class 문법)

// #2. 기반 클래스가 있다면
// => 공통의 특징을 물려 줄수 있고
// => 하나의 컨테이너에 모든 도형을 "같이 보관" 할수 있다.

class Shape
{
	int color;
public:
};

class Rect : public Shape
{
	// x, y, w, h, 생성자등은 생략, 가상함수에 집중!!
public:
	void draw() { std::cout << "draw Rect\n"; }
};
class Circle : public Shape
{
public:
	void draw() { std::cout << "draw Circle\n"; }
};

int main()
{
//	std::vector<Rect*> v; // Rect 만 보관 가능한 vector
	std::vector<Shape*> v; // 모든 종류의 도형을 보관 가능한 vector
}

