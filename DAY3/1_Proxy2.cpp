#include <iostream>
#include <string>
#include <thread>
#include <chrono>

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

		std::this_thread::sleep_for(std::chrono::seconds(3)); // 3초대기 

		return "100.100.100.100";
	}
};

// DNS 의 대행자를 만들어 봅시다.
class DNSProxy : public IDNS
{
public:
	std::string resolve(const std::string& url)
	{
		if (url == "www.samsung.com")
		{
			// 자주 사용되는 url 은 파일등에 정보를 기록해 놓고
			// 서버에 접속할필요 없어 기록된 정보를 반환합니다.
			return "100.100.100.100";
		}

		// LOCAL PC 에 정보가없을때만 실제 DNS 객체의 기능을 사용합니다.
		DNS dns;
		return dns.resolve(url);
	}
};


int main()
{
//	DNS dns;		// 항상 서버에 접근
	DNSProxy dns;	// 캐쉬를 먼저 조사
					// 정보가 없을때만 서버에 접근

	std::cout << dns.resolve("www.samsung.com") << std::endl;
}