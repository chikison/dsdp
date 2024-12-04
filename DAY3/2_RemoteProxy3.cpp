#define USING_GUI
#include "cppmaster.h"



// Proxy 는 다양하게 Update(교체)될수 있습니다.
// 규칙(인터페이스)을 먼저 설계
struct ICalc
{
	virtual int Add(int a, int b) = 0;
	virtual int Sub(int a, int b) = 0;
	virtual ~ICalc() {}
};


class Calc : public ICalc
{
	int server;
public:
	Calc() { server = ec_find_server("Calc"); }

	int Add(int a, int b) { return ec_send_server(server, 1, a, b); };
	int Sub(int a, int b) { return ec_send_server(server, 2, a, b); };
};

int main()
{
	// 아래 처럼하면 Proxy 와 Client 사이에 강한결합니다.
	// Proxy 가 Update 되면 Client 도 수정되어야 합니다.
	// Calc* calc = new Calc;

	// 약한결합으로 사용해야 합니다.
	ICalc* calc = new ? ;  // ? 를 어떻게 해야 할까요 ??
						   // 해결책은 다음소스에서!!

	int n1 = calc->Add(10, 20);
	int n2 = calc->Sub(10, 20);

	std::cout << n1 << ", " << n2 << std::endl;

}





