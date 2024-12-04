#include <iostream>
#include <vector>



class Shape
{
	int color;
public:
	virtual ~Shape() {}

	void set_color(int c) { color = c; }

	virtual int get_area() { return -1; }

	virtual void draw() { std::cout << "draw Shape\n"; }
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

			
			// 아래 처럼 했다면 역시 OCP 만족할수 없는 코드
			// => 그래서 dynamic_cast 를 사용하는 것은 좋은 디자인이 아니다.
			if (dynamic_cast<Rect*>(v[k]) != nullptr)
			{
				Rect* r = new Rect;
			//	r->set_color = v[k]->color; // v[k] 의 모든 속성을 r에 복사
				v.push_back(r);
			}
			else if (dynamic_cast<Circle*>(v[k]) != nullptr)
			{
				Circle* c = new Circle;
				
				v.push_back(c);
			}
		}
	}
}

