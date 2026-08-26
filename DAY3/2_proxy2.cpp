#include <iostream>
#include <thread>
#include <string>
#include <chrono>
using namespace std::literals;

struct IDNS
{
	virtual std::string get_host_ip(const std::string& url) = 0;
	virtual ~IDNS() {}
};

class DNS : public IDNS
{
public:
	std::string get_host_ip(const std::string& url)
	{
		std::cout << "서버에 접속해서 URL 에 대한 IP 정보를 얻고 있습니다.\n";
		std::this_thread::sleep_for(3s);

		return "100.100.100.100";
	}
};

class Machine
{
public:
	void work(IDNS* dns)
	{
		std::cout << dns->get_host_ip("www.samsung.com") << std::endl;
	}
};

// DNS 클래스 사용시 사용자가 "특정 URL" 을 자주 요청한다..
// DNS 을 "대신 사용할 클래스를 만들어 봅시다"

class CacheDNS : public IDNS
{
public:
	std::string get_host_ip(const std::string& url)
	{
		// #1. 사용자가 요청한 url 이 local pc 의 cache 에 있는 지 확인
		//     => 있다면 즉시 반환
		if (url == "www.samsung.com") // local pc 에 있는 url
			return "200.200.200.200";

		// #2. cache 에 없다면 이제 DNS 클래스로 서버에 접속해서 ip 얻기
		DNS dns;
		std::string ip = dns.get_host_ip(url);

		return ip;
	}
};




int main()
{
	Machine m;

	DNS dns;
	m.work(&dns);
}