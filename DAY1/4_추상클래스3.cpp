#include <iostream>

// 추상 클래스 : 지켜야 하는 규칙 + 다른 멤버도 있는 경우
// 인터 페이스 : 지켜야 하는 규칙만 가진 경우

// C#, java : interface, abstract 라는 별도의 키워드 제공
// C++      : 별도 키워드 없음, 단지 위 내용으로 구분

//------------------------------------------
// 강한 결합(tightly coupling)
// => 하나의 클래스가 다른 클래스 사용시, 클래스 이름을 직접 사용하는것
// => use_camera(HDCamera* c)
// => 교체 불가능한 경직된 디자인.

// 약한 결합(loosely coupling)
// => 하나의 클래스가 다른 클래스 사용시, 클래스 이름이 아닌 규칙을 담은
//     인터페이스를 사용해서 접근 하는 것
// => use_camera(ICamera* c)
// => 교체 가능한 유연한 디자인.
//------------------------------------------------------

// 카메라를 먼저 만들지 말고
// 카메라 제조사와 카메라 사용자 사이에 지켜야 하는 규칙을 먼저 설계한다.
// 규칙 : "모든 카메라는 아래 클래스로 부터 파생되어야 한다." 라고 표현하지 말고
//       "모든 카메라는 아래 인터페이스를 구현해야 한다" 라고 표현합니다.

// class  : 접근 지정자 생략시 디폴트 값은 private
// struct : 접근 지정자 생략시 디폴트 값은 public

//class ICamera
struct ICamera
{
//public:
	virtual void take() = 0;
	virtual ~ICamera() {} // 인터페이스도 결국 기반 클래스 입니다.
						  // 소멸자를 가상함수로 해야 합니다. 
};



// 카메라 사용자는 "특정 제품의 이름" 이 아닌 "규칙이름" 으로 사용하면됩니다.
class People
{
public:
	void use_camera(ICamera* c) { c->take(); }
};


// 모든 카메라는 규칙을 지켜야 합니다.
class Camera : public ICamera
{
public:
	void take() override { std::cout << "Take Picture" << std::endl; }
};

class HDCamera : public ICamera
{
public:
	void take() override { std::cout << "Take HD Picture" << std::endl; }
};

class FHDCamera : public ICamera
{
public:
	void take() override { std::cout << "Take FHD Picture" << std::endl; }
};

int main()
{
	People p;

	Camera c;
	p.use_camera(&c);

	HDCamera hc;
	p.use_camera(&hc); 

	FHDCamera fhc;
	p.use_camera(&fhc);
}

