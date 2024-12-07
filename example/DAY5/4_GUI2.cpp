#define USING_GUI
#include "cppmaster.h"

class CWnd
{
	int handle;
public:
	void Create()
	{
	}

	virtual void LButtonDown() {}
	virtual void KeyDown() {}
};

class MyWindow : public CWnd
{
public:
	void LButtonDown() override { std::cout << "LBUTTON" << std::endl; }
	void KeyDown()     override { std::cout << "KEYDOWN" << std::endl; }
};

int main()
{
	MyWindow w; 
	w.Create(); 				

	ec_process_message();
}
