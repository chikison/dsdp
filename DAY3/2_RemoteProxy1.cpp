// 32bit 환경에서 컴파일 해야 합니다. 
// => "x64" 가 아닌 "x86"

#define USING_GUI
#include "cppmaster.h"

// 아래 코드는 전형적인 C 스타일 입니다.
// => 단점을 생각해 봅시다.

// 1. 모든 Client 제작자가 IPC 기술을 알아야 합니다.

// 2. 서버 장애시 각각의 Client 에서 모두 장애처리 해야 합니다.

// 3. 덧셈은 1, 뺄셈은 2라는 명령 코드를 모두 외워야 합니다.
//   실제 명령 코드는 많을수 있습니다.

// "서버를 대신하는 대행자(Proxy)를 만들어 봅시다."
// => 다음 소스에서..


int main()
{
	// 1. 서버의 핸들을 얻어 옵니다.
	int server = ec_find_server("Calc");


	std::cout << "서버 번호 : " << server << std::endl;

	// 2. 서버에 명령코드와 파라미터를 전달합니다.
	int n1 = ec_send_server(server, 1, 10, 20); // 10 + 20 요청
	int n2 = ec_send_server(server, 2, 10, 20); // 10 - 20 요청

	std::cout << n1 << ", " << n2 << std::endl;

}





