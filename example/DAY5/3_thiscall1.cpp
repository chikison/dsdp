#include <iostream>

class Point
{
	int x = 0;
	int y = 0;
public:
	void set(int a, int b)
	{
		x = 0;
		y = 0;
	}
};
int main()
{
	Point p1;
	Point p2;

	p1.set(10, 20);
}