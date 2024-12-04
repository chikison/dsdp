//1_추상클래스2.cpp
#include <iostream>


class Camera
{
public:	
	void take() { std::cout << "Take Picture" << std::endl; }
};

class People
{
public:	
	void use_camera(Camera* p) { p->take(); }
};

int main()
{
	People p;
	Camera c;
	p.use_camera(&c);
}





