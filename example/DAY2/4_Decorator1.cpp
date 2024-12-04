// Decorator - 65 page
#include <iostream>

class PhotoSticker
{
public:
	void take() { std::cout << "take Photo\n";}
	void draw()	{ std::cout << "draw Photo\n"; }
};

int main()
{
	PhotoSticker ps;
	ps.take();
	ps.draw();
}
