#define USING_GUI
#include "cppmaster.h"
#include "ICalc.h"

// Proxy 패턴 : 기존 요소를 대신할 요소를 만드는 것!!

//  Raw Pointer 를 사용하지 말고 대신할 것을 만들어봅시다.
// => C++의 스마트 포인터 기술
// => 스마트 포인터가 결국 "포인터를 대신" 하는 역활의 객체를 사용하자이므로
//    "proxy 패턴" 입니다. "smart proxy" 라고 합니다.

template<typename T>
class sp
{
	T* obj;
public:
	sp(T* p = nullptr) : obj(p) { if (obj != nullptr) obj->AddRef(); }

	sp(const sp& other) : obj(other.obj) { if (obj != nullptr) obj->AddRef(); }

	~sp() { if (obj != nullptr) obj->Release(); }

	// sp 는 포인터를 대신 하는 것이 목적이므로 
	// -> 와 * 연산자를 지원해야 합니다.
	T* operator->() { return obj; }
	T& operator*() { return *obj; }
};
int main()
{
	sp<ICalc> calc1 = load_proxy();
	sp<ICalc> calc2 = calc1;

	// calc1 은 진짜 포인터 처럼 사용가능해야 합니다.
	int n1 = calc1->Add(10, 20);
	int n2 = (*calc1).Sub(10, 20);

	std::cout << n1 << ", " << n2 << std::endl;
}


/*
int main()
{
	ICalc* calc1 = load_proxy();

	calc1->AddRef(); 

	ICalc* calc2 = calc1;
	calc2->AddRef(); 


	calc2->Release(); 

	std::cout << "-------------\n";

	calc1->Release(); 

	std::cout << "-------------\n";

}

*/



