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


// 클래스 어답터 : 클래스 인터페이스 변경
// 객체   어답터 : 객체   인터페이스 변경

// 아래 코드는 클래스 어답터 입니다.
class Text : public TextView,  public Shape     
{
public:
	Text(const std::string& s) : TextView(s) {}

	void draw() override
	{
		TextView::show();
	}
};

// 아래 코드가 객체 어답터 입니다.
// => "이미 생성되어 있는" TextView 객체의 인터페이스를 변경하겠다는 의도
class ObjectAdater : public Shape
{
	TextView* tview; // 핵심 : 포인터 또는 참조 멤버
					 // 의도 : 이미 만들어진 객체를 가리키겠다는것
public:
	ObjectAdater(TextView* v) : tview(v) {}

	void draw() override
	{
		tview->show();
	}
};


int main()
{
	std::vector<Shape*> v;

	TextView tv("hello"); // TextView : 클래스
						  // tv       : 객체(변수)

	// 이미 생성된 객체 tv 를 v에 넣을수 있을까요 ?
//	v.push_back(&tv); // error


	v.push_back( new ObjectAdater(&tv) ); // ok..
											// 객체 어답터 사용

	v[0]->draw();
}


/*
class Text : public TextView {}; 
// 상속 : 클래스에 기능 추가, 클래스의 함수 이름 변경

class ObjectAdapter
{
	TextView* tv; // 포인터형태로 포함
				  // 객체에 기능 추가, 객체에 이름 변경
};
*/


