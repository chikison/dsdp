#include <iostream>
#include <vector>

// 1. 디자인 패턴이란 ? 
// => 1994년 발간된 책의 제목. 4명의 저자
// => 당시 유명한 오픈소스들이 사용하던 기법에 이름을 부여 한것
// => 23개의 이름 부여
// => 4명의 저자를 "도둑" 이라는 의미로 Gang's Of Four 라고합니다.
// => 그래서 "GOF's Design Pattern"

// 2. Prototype 패턴
// => 견본이 되는 객체를 만들고, 복사본을 만들게 하는 기법
// => clone() 가상함수
// => 오늘은 소개, 목요일날 제대로 등장




class Shape
{
	int color;
public:
	virtual ~Shape() {}

	void set_color(int c) { color = c; }

	virtual int get_area() { return -1; }

	virtual void draw() { std::cout << "draw Shape\n"; }


	// 자신의 복사본을 생성하는 가상함수는 아주 널리 사용되는 
	// 기법 입니다.
	virtual Shape* clone()
	{
		Shape* s = new Shape;
		s->color = color; // 자신의 모든 속성을 새로운 객체에 복사
		return s;
	}

};





class Rect : public Shape
{
public:
	void draw() { std::cout << "draw Rect\n"; }

	virtual Shape* clone()
	{
//		Rect* s = new Rect;
//		return s;
		return new Rect(*this);
				// *this(나)와 동일한 Rect 만들어 달라. 복사 생성자사용
				// *this 의 메모리를 통째로 복사해서 만들게 됩니다.
		
	}
};


class Circle : public Shape
{
public:
	void draw() { std::cout << "draw Circle\n"; }

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

			// k 번째 도형의 복사본을 생성해서 v 에 추가 합니다
			// 어떻게 구현해야 할까요 ?
			// k 번째 만든 도형은 뭘까요 ?


			v.push_back(v[k]->clone()); // 다형성 !!
					// k 번째 도형이 뭔지 조사할 필요 없다.
					// java 에서는 이런 기법을 "don't ask do it"
					// 이라고 합니다.
	
		}
	}
}

