#include <iostream>
#include <vector>

class Shape
{
	int color;
public:
	virtual ~Shape() {} // 소멸자를 가상함수로..(다음시간에 배웁니다.)
};

class Rect : public Shape
{
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
	std::vector<Shape*> v;

	while (1)
	{
		int cmd;
		std::cin >> cmd;

		if (cmd == 1) v.push_back(new Rect);
		else if (cmd == 2) v.push_back(new Circle);
		else if (cmd == 9)
		{
			for (auto p : v)
			{
				// 해결책 #1. Shape* 인 p를 Rect* 난 Circle* 로 캐스팅해서 사용
				
				if ( dynamic_cast<Rect*>(p) != nullptr )
					static_cast<Rect*>(p)->draw();

				else if (dynamic_cast<Circle*>(p) != nullptr)
					static_cast<Circle*>(p)->draw();
			}
		}
	}
}
// 위 코드는 OCP 를 만족하지 않는 코드 입니다.

// 기능 확장에 열려 있고(Open, 나중에 클래스가 추가 되어도)
// 코드 수정에는 닫혀 있어야(Close, 기존 코드는 수정되면 안되도록 하라는)
// 이론(Principle)

// OCP(Open Close Principle, 개방 폐쇄의 법칙)

// S/W 설계의 5대 원칙
// SRP, OCP, LSP, ISP, DIP  => SOLID 원칙

// 위 코드는 OCP를 위반한 좋지 않은 설계 입니다.
