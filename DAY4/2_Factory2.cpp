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

class Rect : public Shape
{
public:
	void draw() override { std::cout << "draw Rect" << std::endl; }

	// 자신의 객체를 만드는 static 멤버 함수는 아주 유용하게 활용됩니다
	static Shape* create() { return new Rect; }
};

// Rect 객체를 만드는 2가지 방법
// 1. Rect* rc = new Rect;			=> 클래스 이름을 알아야 합니다.
// 2. Rect* rc = Rect::create();	=> 클래스 이름을 몰라도 함수 포인터만
//										알면 객체를 만들수 있습니다.

// C++ 에서는 "클래스이름"을 컨테이너(vector등, 자료구조)에 보관할수 없습니다.
//v.push_back("Rect"); // 이 코드는 클래스 이름이 아닌 "문자열 Rect" 보관한것
					 // C++은 문자열 "Rect" 로는 Rect 객체 생성 못합니다.

// 하지만 함수 포인터는 컨테이너에 보관할수 있습니다.
// v.push_back(&Rect::create); // ok
// v[0](); // Rect 객체 생성










class Circle : public Shape
{
public:
	void draw() override { std::cout << "draw Circle" << std::endl; }

	static Shape* create() { return new Circle; }
};




class ShapeFactory
{
	typedef Shape* (*CREATOR)(); // CREATOR 라는 함수 포인터 타입

	std::map<int, CREATOR> create_map; // [도형번호, 생성함수] 의 쌍을보관

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
			p = it->second(); // it->first : 도형 번호
							  // it->second : 생성함수 주소 이므로
							  // () 붙이면 호출입니다.
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
	factory.register_shape(1, &Rect::create);
	factory.register_shape(2, &Circle::create);


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




