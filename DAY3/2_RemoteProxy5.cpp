#define USING_GUI
#include "cppmaster.h"
#include "ICalc.h"


int main()
{
	ICalc* calc = load_proxy(); // 이순간 DLL 안에 있는 create() 함수에서
								// "new Calc" 하게 됩니다.
								// 사용후에는 "delete" 해야 되지 않을까요 ?

	int n1 = calc->Add(10, 20);


	delete calc;  // 이렇게 해도 될까요 ?
					// 안됩니다.!!
					// DLL 이 할당한 자원은 DLL 에서 해지
					// 해결은 다음소스!!


}





