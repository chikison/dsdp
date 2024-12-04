#include <iostream>

class Monitor
{
	int brightness = 80;   // ¹à±â
	int resolution = 1024; // ÇØ»óµµ
public:
	void set_brightness(int value) { brightness = value; }
	int  get_brightness() const { return brightness; }

	void set_resolution(int value) { resolution = value; }
	int  get_resolution() const { return resolution; }

	void info() const
	{
		std::cout << "brightness : " << brightness << ", ";
		std::cout << "resolution : " << resolution << '\n';
	}
};