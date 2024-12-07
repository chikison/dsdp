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



// 공장에 제품을 등록하기 위한 클래스
class AutoRegister
{
public:
	AutoRegister(int key, Shape* (*c)())
	{
		ShapeFactory::get_instance().register_shape(key, c);
	}
};

// 전역변수의 생성자가 언제 호출되는지 생각해보세요!!
// 1. 모든 전역변수의 생성자가 호출되고
// 2. main 함수 실행
// AutoRegister ar(1, &Rect::create);



class Rect : public Shape
{
public:
	void draw() override { std::cout << "draw Rect" << std::endl; }

	static Shape* create() { return new Rect; }

	// static 멤버 데이타의 특징을 생각해 보세요
	// => 언제 생성되는지 ?
	// => 결국 Rect 가 사용하는 "전역변수" 입니다
	// => main 함수 실행이전에 생성됩니다. ar 생성자 호출. 
	static AutoRegister ar;
};
AutoRegister Rect::ar(1, &Rect::create);

//						// Rect::ar 의 생성자 호출
//						// => 즉, Rect 라는 클래스에 대해서 최초 1회 실행
//						// => "객체의 생성자가 아닌 클래스의 생성자개념"
// Rect* r1 = new Rect;	// Rect 생성자 호출
// Rect* r2 = new Rect; // Rect 생성자 호출
// Rect* r3 = new Rect; // Rect 생성자 호출
						// 즉, 생성자는 "객체를 만들때 마다" 호출
						// 객체당 1번
/*
// C#
class Car
{
	public Car() {} // instance 생성자
	static Car() {} // static 생성자 - C# 언어만 있는 문법
};

Car c1 = new Car(); // static 생성자 호출
					// instance 생성자 호출
Car c2 = new Car(); // instance 생성자 호출
Car c3 = new Car(); // instance 생성자 호출

*/

class Circle : public Shape
{
public:
	void draw() override { std::cout << "draw Circle" << std::endl; }

	static Shape* create() { return new Circle; }

	// C++17 부터는 아래 처럼하면 외부선언 필요 없습니다.
	// => inline static
	// => 프로젝트메뉴=> DAY4속성 메뉴 에서 C++버전 C++17 로 변경하세요
	inline static AutoRegister ar{ 2, &Circle::create };
};







int main()
{
	std::vector<Shape*> v;

	ShapeFactory& factory = ShapeFactory::get_instance();


//	factory.register_shape(1, &Rect::create);
//	factory.register_shape(2, &Circle::create);


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




