// Decorator(포장지, 꾸미기) - 65 page
#include <iostream>

// 스티커 사진 클래스라고 생각해 봅시다.
class PhotoSticker
{
public:
	void take() { std::cout << "take Photo\n"; }
	void draw() { std::cout << "draw Photo\n"; }
};

//----------------------------------------------
class Emoticon 
{
	PhotoSticker* origin; // 핵심 : 포인터 또는 참조변수로!!
						  // 의도 : 외부에 이미 만들어진 객체를 가리키겠다는 것
public:
	Emoticon(PhotoSticker* ps) : origin(ps) {}


	void draw()
	{
		std::cout << "$$$$$$$$$$$$\n";	// 추가 기능
		origin->draw();					// 원래 객체 기능
		std::cout << "$$$$$$$$$$$$\n";	
	}
};

int main()
{
	PhotoSticker ps;
	ps.take();	
	ps.draw();	


	Emoticon emo(&ps); // ps 라는 객체에 기능을 추가하겠다는 것
	emo.draw();			// ps 자체의 기능 + 추가된 기능도 수행
						// emo 는 ps라는 객체에 기능을 추가 한 것

	// 기능이 추가되기전의 원본 객체의 기능만 사용할수도 있다.
	ps.draw();
}
