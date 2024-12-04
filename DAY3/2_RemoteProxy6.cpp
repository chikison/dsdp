#define USING_GUI
#include "cppmaster.h"
#include "ICalc.h"

// 아래 코드(규칙)는 어렵지는 않습니다. 그런데
// => 지루한 코드가 반복되고
// => 실수 할수 있습니다.(AddRef 또는 Release 호출을 실수로 생략!!!)

// 실수 할수 없도록 해봅시다. => 다음 단계(마지막)
int main()
{
	ICalc* calc1 = load_proxy();
	
	calc1->AddRef(); // 규칙 #1. Proxy 포인터를 처음 얻으면 참조계수 증가

	ICalc* calc2 = calc1;
	calc2->AddRef(); // 규칙 #2. Proxy 포인터 복사시 참조 계수 증가


	calc2->Release(); // 규칙 #3. 포인터가 더이상 필요없으면 참조계수 감소

	std::cout << "-------------\n";
	
	calc1->Release(); // 이순간 참조계수가 0되고 proxy 파괴
	
	std::cout << "-------------\n";

}





