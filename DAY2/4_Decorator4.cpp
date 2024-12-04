#include <iostream>


// 핵심 클래스와
// 핵심 클래스에 기능을 추가하는 클래스(Decorator)는 공통의 인터페이스가 필요하다.

struct IDraw
{
	virtual void draw() = 0;
	virtual ~IDraw() {} 
};



class PhotoSticker : public IDraw 
{
public:
	void take() { std::cout << "take Photo\n"; }
	void draw() { std::cout << "draw Photo\n"; }
};

//----------------------------------------------
class Emoticon : public IDraw
{
	IDraw* origin;
public:
	Emoticon(IDraw* ps) : origin(ps) {}

	void draw()
	{
		std::cout << "$$$$$$$$$$$$\n";
		origin->draw();
		std::cout << "$$$$$$$$$$$$\n";
	}
};

class Frame : public IDraw
{
	IDraw* origin;
public:
	Frame(IDraw* ps) : origin(ps) {}

	void draw()
	{
		std::cout << "============\n";
		origin->draw();
		std::cout << "============\n";
	}
};

int main()
{
	PhotoSticker ps;
	ps.take();
	ps.draw();


	Emoticon emo(&ps);
	emo.draw();


	Frame frame(&emo);
	frame.draw();
}
