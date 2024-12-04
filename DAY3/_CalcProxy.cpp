#define USING_GUI
#include "cppmaster.h"
#include "ICalc.h"

class Calc : public ICalc
{
	int server;
public:
	Calc() { server = ec_find_server("Calc"); }

	int Add(int a, int b) { return ec_send_server(server, 1, a, b); };
	int Sub(int a, int b) { return ec_send_server(server, 2, a, b); };
};

// DLL 사용자(클라이언트 제작자는) DLL 내부의 Proxy 의 이름을
// 알지도 못하고, 알필요도 없고, 사용해도 안됩니다. - 약한결합을 위해서
// DLL 내부에 약속된 함수를 만들고 Proxy 객체를 생성해야 합니다.
extern "C" __declspec(dllexport)
ICalc* create()
{
	return new Calc;
}

// 어차피 이름을 약속할것라면 "Calc" 클래스 이름약속하면 안되나요 ?
// => 클라이언트가 "new Calc" 해야 하는데.. 
// new Calc : Calc 클래스 자체의 헤더 파일(ICalc 가 아니고 Calc) 이 필요
//            Proxy Update 되면 Calc 헤더도 변경될수 있습니다
//            그러면 클라이언트가 "다시 빌드" 되어야 합니다.

// create 이름 약속 : 클라이언트가 "다시 빌드" 도 필요 없습니다.
//============================================
// 빌드 하는 법 
// 리눅스 C++ 컴파일러 : g++
// 윈도우 C++ 컴파일러 : cl.exe
// => 시작 버튼 => "developer ... " 검색하면 나오는 창 실행
// => 현재 소스가 있는 폴더로 이동 (cd 명령)

// => cl CalcProxy.cpp /LD   로 빌드하면 "CalcProxy.dll" 생성됩니다.
// 
// => "/LD" 옵션이 DLL 로 빌드하라는 옵션

