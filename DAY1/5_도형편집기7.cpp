#include <iostream>
#include <vector>

// template method 패턴
// => 기반 클래스가 변하지 않은 전체적인 흐름을 담을 코드를 제공
// => 변해야 하는 부분만 가상함수화 해서 파생 클래스가 다시 만들기회 제공
// => 가장 널리 사용되는 디자인 패턴.



class Shape
{
	int color;
public:
	virtual ~Shape() {}

	void set_color(int c) { color = c; }

	virtual int get_area() { return -1; }


	// 공통성과 가변성의 분리
	// => 변하지 않은 코드안에서 변해야 하는 부분이 있다면 분리되어야한다.
	// => 변해야 하는 부분을 가상함수로 분리한다.

	virtual void draw_imp()
	{
		std::cout << "draw Shape\n";
	}

	void draw()
	{ 
		std::cout << "lock mutex\n";

		draw_imp();		
		
		std::cout << "unlock mutex\n";

	}







	virtual Shape* clone()
	{
		Shape* s = new Shape;
		s->color = color; 
		return s;
	}

};





class Rect : public Shape
{
public:
	void draw_imp() { std::cout << "draw Rect\n"; }

	virtual Shape* clone()
	{
		return new Rect(*this);
	}
};


class Circle : public Shape
{
public:
	void draw_imp() { std::cout << "draw Circle\n"; }

	virtual Shape* clone()
	{
		return new Circle(*this);
	}
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
				p->draw();
			}
		}

		else if (cmd == 8)
		{
			std::cout << "몇번째 만든 도형을 복제 할까요 >> ";

			int k;
			std::cin >> k;

			v.push_back(v[k]->clone());
		

		}
	}
}

