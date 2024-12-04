#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include <iostream>
#include <WinSock2.h>
#pragma comment(lib, "ws2_32.lib")
using namespace std;


class NetworkInit
{
public:
	NetworkInit()
	{
		WSADATA w;
		WSAStartup(0x202, &w);
	}
	~NetworkInit()
	{

		WSACleanup();
	}
};

class IPAddress
{
	SOCKADDR_IN addr;
public:
	IPAddress(const char* ip, short port)
	{
		addr.sin_family = AF_INET;
		addr.sin_port = htons(port);
		addr.sin_addr.s_addr = inet_addr(ip);
	}
	SOCKADDR* getRawAddress()
	{
		return (SOCKADDR*)&addr;
	}
};


class Socket
{
	int sock;
public:
	Socket(int type) { sock = socket(PF_INET, type, 0); }

	void Bind(IPAddress* ip)
	{
		::bind(sock, ip->getRawAddress(), sizeof(SOCKADDR_IN));
	}
	void Listen() { ::listen(sock, 5); }

	void Accept()
	{
		struct sockaddr_in addr2 = { 0 };
		int sz = sizeof(addr2);

		accept(sock, (SOCKADDR*)&addr2, &sz);
	}
};

// TCP Server 를 만들려면
// => 라이브러리내의  몇개의 클래스를 사용해서
// => 몇가지의 전형적인 절차를 거쳐야 합니다

// => 이런 절차도 한가지의 책임으로 볼수 있습니다.
// => 이책임을 담당하는 클래스를 제공합니다.
class TCPServer
{
	NetworkInit init;
//	Socket sock(SOCK_STREAM); // 멤버 데이타 안에서 생성자 인자를 전달할때는 () 하지말고
	Socket sock{ SOCK_STREAM };// {} 로 만 가능합니다.
public:
	void Start(const char* ip, short port)
	{
		IPAddress addr(ip, port);
		sock.Bind(&addr);
		sock.Listen();
		sock.Accept();
	}
};

int main()
{
	// 이제 최종 사용자는 아래 처럼 사용하면 됩니다
	TCPServer server;
	server.Start("127.0.0.1", 4000);

}
