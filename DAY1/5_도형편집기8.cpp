#include <iostream>
#include <vector>

class not_implemented {}; //예외를 위한 클래스
class Shape
{
	int color;
public:
	virtual ~Shape() {}

	void set_color(int c) { color = c; }

	void draw()
	{
		std::cout << "lock mutex\n";
		draw_imp();
		std::cout << "unlock mutex\n";

	}

	// 가상 함수      : 파생클래스가 override 하지 않으면 기본 구현 제공하겠다는 의도
	// 순수 가상 함수 : 파생 클래스에게 반드시 override 하라고 지시하는 것

	virtual void draw_imp() = 0;


	// 아래 함수도
	// 1. 순수 가상함수로 해도 좋습니다.
	// 2. 예외 전달 구현도 나쁘지 않습니다.
	// virtual Shape* clone() = 0; 

	// 1. 파생 클래스가 만드시 만들 필요는 없다.
	// 2. 파생클래스가 override 하지 않았는데 사용하지 않으면 ok
	// 3. 파생클래스가 override 하지 않았는데 사용하면 예외 발생
	// 4. 파생클래스가 override 하고  사용하면 ok
	// => 즉, 사용하려면 override 하라는 의미
	virtual Shape* clone() { throw not_implemented(); }


	// 아래 함수도
	// 1. =0 으로 해도 되고
	// 2. 기본 구현으로 예외 던지는 기법도 가능하고
	// 3. 실패를 나타내는 값을 약속(C기법)한 것도 가능.. 
	// => "get_area()의 결과가 -1이면 면적 구할수 없음"이라고 약속하자는것
	virtual int get_area() { return -1; }
};





class Rect : public Shape
{
public:
	void draw_imp() override { std::cout << "draw Rect\n"; }

	Shape* clone() override  { return new Rect(*this);	}
};


class Circle : public Shape
{
public:
	void draw_imp() override  { std::cout << "draw Circle\n"; }

	Shape* clone() override  {	return new Circle(*this);}
};

int main()
{
	std::vector<Shape*> v;

	while (1)
	{
		int cmd;
		std::cin >> cmd;

		// 생각해 볼 문제 #1. 객체의 생성과정을 OCP 를 만족하게 할수 없을까 ?
		// => 새로운 도형이 추가되어도 아래 코드가 수정되지 않게 ??
		// => "factory" 패턴을 사용하면 됩니다. 목요일날 배우게 됩니다.

		// #2. undo/redo 기능을 넣으려면 어떻게 해야 할까 ?
		// => "command" 패턴을 배우면 됩니다. 목요일날 배우게 됩니다.
		if (cmd == 1) v.push_back(new Rect);
		else if (cmd == 2) v.push_back(new Circle);
		else if (cmd == 9)
		{
			for (auto p : v)
			{
				p->draw();	// 다형성. OCP 만족
							// 새로운 도형 추가시 이 한줄은 수정될 필요 없다.
			}
		}
		else if (cmd == 8)
		{
			std::cout << "몇번째 만든 도형을 복제 할까요 >> ";
			int k;
			std::cin >> k;
			v.push_back(v[k]->clone());// 다형성, OCP 만족, 좋은 코드


		}
	}
}

