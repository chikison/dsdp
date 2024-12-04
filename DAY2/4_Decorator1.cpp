// Decorator(포장지, 꾸미기) - 65 page
#include <iostream>

// 스티커 사진 클래스라고 생각해 봅시다.
class PhotoSticker
{
public:
	void take() { std::cout << "take Photo\n";}
	void draw()	{ std::cout << "draw Photo\n"; }
};

// 상속을 사용한 기능의 추가
class Emoticon : public PhotoSticker
{
public:
	void draw()
	{
		std::cout << "$$$$$$$$$$$$\n";	// 추가된 기능
		PhotoSticker::draw();			// 원래 기능 사용
		std::cout << "$$$$$$$$$$$$\n";	// 추가된 기능
	}
};

int main()
{
	PhotoSticker ps;
	ps.take();	// 사진 촬영
	ps.draw();	// 촬영된 사진 출력

	// 아래 코드는 위에서 이미 만든 "ps" 라는 객체에 기능 추가된것이 아니라!!
	// 기능이 추가된 객체를 다시 만든것
	// 즉, 다시 사진을 촬영해야 한다.
	// 상속 : 클래스에 기능을 추가하는 것

	Emoticon emo;
	emo.take();
	emo.draw(); // 원래 기능 +  추가된 기능 사용
}
