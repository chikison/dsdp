//1_추상클래스2.cpp
#include <iostream>


class Camera
{
public:	
	void take() { std::cout << "Take Picture" << std::endl; }
};

class HDCamera
{
public:
	void take() { std::cout << "Take HD Picture" << std::endl; }
};

class People
{
public:	
	void use_camera(Camera* p) { p->take(); }
	void use_camera(HDCamera* p) { p->take(); }
};

int main()
{
	People p;

	Camera c;
	p.use_camera(&c);

	HDCamera hc;
	p.use_camera(&hc); // ??
}


// 위코드는 나중에 추가된 "HDCamera" 때문에
// People 의 코드가 수정되었습니다.

// => OCP 를 만족할수 없는 코드 입니다.

// => 새로운 카메라가 또 나오면, 다시 People 은 수정되어야 합니다.


