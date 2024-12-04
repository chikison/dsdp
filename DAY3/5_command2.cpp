#include "monitor.h"

// C 언어 : 어떤 일을 할때, "함수를 직접 호출" 합니다.
//         => 주어진 일만 할수 있습니다.


// Command 패턴 : 어떤일을 할때, 그 함수를 호출해주는(그일을하는) 객체를 만들라는 것
//			=> 주어진 일도 할수 있고.
//			=> 취소하는 방법도 제공할수 있고
//			=> 취소할때 필요한 데이타도 보관할수 있다.
//			=> 또한 명령을 차례대로 보관할수도 있다.


// 다양한 명령이 있을수 있으므로 인터페이스 부터 설계
struct ICommand
{
	virtual void execute() = 0;
	virtual void undo() = 0;
	virtual ~ICommand() {}
};

class BrightnessCommand : public ICommand
{
	Monitor& m;
	int value;
	int old_value = 0;
public:
	BrightnessCommand(Monitor& m, int value) : m(m), value(value) {}

	void execute() 
	{
		old_value = m.get_brightness();
		m.set_brightness(value); 
	}
	void undo()
	{
		m.set_brightness(old_value);
	}
};

int main()
{
	Monitor m;
	
	int old_value = m.get_brightness();
	m.set_brightness(90);
	// 여기서, Monitor m 을 밝기를 바꾸기 이전상태로 복구해 보세요
	m.set_brightness(old_value);


	BrightnessCommand cmd(m, 90);
	cmd.execute();
	cmd.undo(); // ?!!!
}