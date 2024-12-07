#include <iostream>
#include <vector>
#include <map>
#include "Helper.h"

class Shape
{
public:
	virtual void draw() = 0;
	virtual ~Shape() {}

	virtual Shape* clone() = 0;
};

class Rect : public Shape
{
public:
	void draw() override { std::cout << "draw Rect" << std::endl; }

	static Shape* create() { return new Rect; }

	Shape* clone() override { return new Rect(*this); }
};









class Circle : public Shape
{
public:
	void draw() override { std::cout << "draw Circle" << std::endl; }

	static Shape* create() { return new Circle; }

	Shape* clone() override { return new Circle(*this); }
};




class ShapeFactory
{
	std::map<int, Shape*> prototype_map;

	MAKE_SINGLETON(ShapeFactory)
public:
	void register_shape(int key, Shape* c)
	{
		prototype_map[key] = c;
	}

	Shape* create(int key)
	{
		Shape* p = nullptr;

		auto it = prototype_map.find(key);

		if (it != prototype_map.end())
		{
			p = it->second->clone();  // prototype 패턴이 
										// 이렇게 하는 것 입니다.
										// 공장에 견본을 등록하고
										// 필요 할때 복사본을 얻는것
		}
		return p;
	}
};


int main()
{
	std::vector<Shape*> v;

	ShapeFactory& factory = ShapeFactory::get_instance();

	// 공장에 제품을 등록합니다.
	// => 도형번호와 생성함수 등록
	// => 결국, 공장에 "클래스이름"을 등록하는 효과 입니다.
//	factory.register_shape(1, &Rect::create);
//	factory.register_shape(2, &Circle::create);

	// 공장에 "클래스"가 아닌 "자주 사용되는 제품"의 견본을 등록해 봅시다.
	Rect* redRect = new Rect;
	Rect* blueRect = new Rect;
	Circle* redCircle = new Circle; // 이 객체를 만드는 과정이 복잡하다고 가정
									// 생성하고, 다양한 설정을 거쳐야 한다고..

	factory.register_shape(1, redRect);
	factory.register_shape(2, blueRect);
	factory.register_shape(3, redCircle);


	while (1)
	{
		int cmd;
		std::cin >> cmd;

		if (cmd > 0 && cmd < 8)
		{
			Shape* s = factory.create(cmd);

			if (s != nullptr)
				v.push_back(s);
		}

		else if (cmd == 9)
		{
			for (int i = 0; i < v.size(); i++)
			{
				v[i]->draw();
			}
		}
	}
}




