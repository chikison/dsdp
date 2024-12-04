#include <iostream>
#include <string>
#include <thread>
#include <chrono>

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

		std::this_thread::sleep_for(std::chrono::seconds(3));

		return "100.100.100.100";
	}
};

// DNS 클래스를 대신 해서 사용할수 있는 클래스를 만들어 봅시다.
class DNSProxy : public IDNS
{
public:
	std::string resolve(const std::string& url)
	{
		// 현재 요청한 URL 이 local pc 에 캐쉬(파일등)에 있는지 조사
		// 해서 있다면 해당 정보를 반환
		if (url == "www.samsung.com") // url 정보가 local 파일에 있는지조사
		{
			return "200.200.200.200";
		}

		// 요청된 URL 이 파일(캐쉬)에 없을때만
		// 서버에 접속해서 IP를 얻어 온다.
		DNS dns;
		return dns.resolve(url);		
	}
};


int main()
{
//	DNS dns;		// 항상 서버에 접속(시간 걸림)
	DNSProxy dns;	// 필요할때만 서버에 접속

	std::cout << dns.resolve("www.samsung.com") << std::endl;
}
// Proxy 패턴 : 다양한 이유로 대행자를 만드는 패턴

// DNSProxy : DNS 에 캐쉬 기능을 추가하기 위한 대행자

// 그런데 ? 결국 기능의 추가 아닌가요 ??
// => Decorator 와 의 차이점이 뭔가요 ?

// Decorator 
FileStream fs("a.txt"); // origin 객체를 먼저 만들고
ZipDecorator zd(&fs);	// 그후에 객체에 기능 추가
zd.write("hello");		// 기능 추가후 사용해도 되고
fs.write("hello");		// origin 을 직접 사용해 됩니다.
					// ZipDecorator 가 FileStream 을 대신하는것은 아님 

// Proxy 
//DNS dns;	// 이것을 사용하지 말고
DNSProxy dns;	// 이것을 사용하라는 것
				// 즉, origin 자체를 대신하기 위한것
				// Proxy 가 내부적으로 origin 을 생성하는 경우가많다.