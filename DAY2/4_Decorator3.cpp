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
	PhotoSticker* origin; 
public:
	Emoticon(PhotoSticker* ps) : origin(ps) {}

	void draw()
	{
		std::cout << "$$$$$$$$$$$$\n";	
		origin->draw();					
		std::cout << "$$$$$$$$$$$$\n";
	}
};

class Frame
{
	PhotoSticker* origin;
public:
	Frame(PhotoSticker* ps) : origin(ps) {}

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


//	Frame frame(&ps);
	Frame frame(&emo);	// 현재 코드는 에러!!. 
						// 해결책은 다음소스에서 
	frame.draw();
}
