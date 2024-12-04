#include <memory>
#include "ICalc.h"

int main()
{
	// C++ 표준에 이미 스마트포인터가 있는데(std::shared_ptr)
	// 그것을 사용하면 안되나요 ?

	std::shared_ptr<ICalc> p1(load_proxy());
						// p1 의 소멸자에서 "delete" 하게 됩니다
						// 즉, DLL에서 new 한것을 exe 가 delete 하는것
						// 우리에게 필요한것은 delete 가 아닌 Release()호출

	sp<ICalc> p2(load_proxy());
				// p2 는 소멸자에서 
				// "보관된주소->Release()"

	// 그래서 C++ 표준에 이미 스마트포인터가 있지만
	// 많은 오픈소스가 다양한 이유로 "자신만의 스마트 포인터 제공"
	// 실제 안드로이드 소스에 "sp" 가 있습니다.(참조계수 관리)

	// 단 아래 코드는 가능한데, AddRef 호출 안됨.
	std::shared_ptr<ICalc> p3(load_proxy(), [](ICalc* p) { p->Release(); });
	p3->AddRef(); // 이게 필요
}