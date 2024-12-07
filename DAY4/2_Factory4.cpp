#include <iostream>
#include <vector>
#include <map>
#include "Helper.h"

class Shape
{
public:
	virtual void draw() = 0;
	virtual ~Shape() {}
};

class ShapeFactory
{
	typedef Shape* (*CREATOR)();

	std::map<int, CREATOR> create_map;

	MAKE_SINGLETON(ShapeFactory)
public:
	void register_shape(int key, CREATOR c)
	{
		create_map[key] = c;
	}

	Shape* create(int key)
	{
		Shape* p = nullptr;

		auto it = create_map.find(key);

		if (it != create_map.end())
		{
			p = it->second();
		}
		return p;
	}
};


class AutoRegister
{
public:
	AutoRegister(int key, Shape* (*c)())
	{
		ShapeFactory::get_instance().register_shape(key, c);
	}
};



#define REGISTER(key, classname)					\
static Shape* create() { return new classname; }	\
inline static AutoRegister ar{ key, &classname::create };



class Rect : public Shape
{
public:
	void draw() override { std::cout << "draw Rect" << std::endl; }

	REGISTER(1, Rect)
};







class Circle : public Shape
{
public:
	void draw() override { std::cout << "draw Circle" << std::endl; }

	REGISTER(2, Circle)
};

class Triangle : public Shape
{
public:
	void draw() override { std::cout << "draw Triangle" << std::endl; }

	REGISTER(3, Triangle)
};





int main()
{
	std::vector<Shape*> v;

	ShapeFactory& factory = ShapeFactory::get_instance();

	// 복습할때 아래 함수 만들어 보세요
//	factory.show_registered_shape();  // 등록된 모든 제품(도형)
									// 에 대한 정보를 제공
									// 1. Rect 2.Circle 3.Triangle 등
									
									// 키값도 공장에서 얻어낼수 있게 
									// 발전시켜 보세요

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




