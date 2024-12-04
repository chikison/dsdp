#include "monitor.h"

// 모니터의 밝기를 변경하려면
// 방법 #1. set_brightness() 멤버 함수를 직접 호출한다.
// 방법 #2. set_brightness() 멤버 함수를 호출하는 객체를 만들어서 사용

class BrightnessCommand
{
	Monitor& m;
	int value;
public:
	BrightnessCommand(Monitor& m, int value) : m(m), value(value) {}

	void execute() { m.set_brightness(value);}
};

int main()
{
	Monitor m;	
	m.set_brightness(90);
	
	BrightnessCommand cmd(m, 90);
	cmd.execute();
}