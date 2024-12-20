#include <iostream>
#include <string>
#include <thread>
#include <chrono>

// URL : www.naver.com



// Domain Name Server : url => ip 로 변경
struct IDNS
{
	virtual std::string resolve(const std::string& url) = 0;
	virtual ~IDNS() {}
};

class DNS : public IDNS
{
public:
	std::string resolve(const std::string& url)
	{ 
		std::cout << "서버에 접속해서 "
			<< url << "에 대한 IP 정보 얻는중\n";
		
		// 서버접속에 시간이 걸린다고 가정(3초)
		std::this_thread::sleep_for(std::chrono::seconds(3));

		return "100.100.100.100";
	}
};

int main()
{
	DNS dns;

	std::cout << dns.resolve("www.samsung.com") << std::endl;
}