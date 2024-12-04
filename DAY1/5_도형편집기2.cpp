#include <iostream>
#include <vector>

class Shape
{
	int color;
public:
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
				p->draw();	// A. Error
		}		
	}
}
// 위 코드는 왜 ?? 어디서 ?? 에러 일까요 ??
// => vector<Shape*> 이므로 
// => 코드 A 에서 p 의 타입은 Shape* 이다.
// => 그런데, Shape 에는 draw 가 없다!! 그래서 에러


// 해결책은 뭘까요 ?
// => 다음소스에서..., 
