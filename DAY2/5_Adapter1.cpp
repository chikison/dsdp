#include <iostream>
#include <string>
#include <vector>

// 아래 클래스가 이미 있었다가 가정해 봅시다.
// => 문자열을 보관했다가 화면에 이쁘게 출력하는 기능
class TextView
{
	// font 종류, 크기, 색상 등... 다양한 정보 관리 
	std::string data;
public:
	TextView(const std::string& s) : data(s) {}

	void show() { std::cout << data << std::endl; }
};




//=================================================
class Shape
{
public:
	virtual void draw() = 0;
	virtual ~Shape() {}
};


class Rect : public Shape
{
public:
	void draw() override { std::cout << "draw rect" << std::endl; }
};
class Circle : public Shape
{
public:
	void draw() override { std::cout << "draw circle" << std::endl; }
};

// 도형편집기 예제에서 "Rect, Circle" 외에 "문자열"을 관리하는 클래스가 필요하다.
// 그런데, 예전부터 가지고 있던 TextView 기능이면 될거 같다.
// => 여기서 TextView 를 사용할수 있을까 ?
// => "TextView" 는 Shape 로 부터 파생되지 않고, draw()도 없다. 안된다.!!

// TextView 를 도형편집기에서 사용가능하도록 인터페이스(함수이름)을 변경하자.

// Adapter 패턴
// => 기존 클래스의 인터페이스(함수이름)을 변경해서
//    시스템에 맞도록 바꿔주는 클래스
// => 인터페이스의 불일치를 해결하는 패턴. 


class Text : public TextView,  // 여기서 모든 기능 물려받고
		     public Shape      // 도형편집기 시스템 요구조건 만족
{

public:
	Text(const std::string& s) : TextView(s) {}

	// 아래 부분이 "show()" 이름을 "draw()"로 변경해서, 요구조건을 만족하게
	// 만드는 부분
	void draw() override
	{
		TextView::show();
	}
};

int main()
{
	std::vector<Shape*> v;

	v.push_back(new Text("Hello"));

	v[0]->draw();
}







