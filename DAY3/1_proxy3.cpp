#include <iostream>
#include <thread>
#include <string>
#include <chrono>
using namespace std::literals;

// 다양한 DNS 클래스를 규칙대로 만들게 하기위한 
// 인터페이스
struct IDNS
{
	virtual std::string get_host_ip(const std::string& url) = 0;
};


class DNS : public IDNS
{
public:
	std::string get_host_ip(const std::string& url)
	{
		std::cout << "서버에 접속해서 URL 에 대한 IP 정보를 얻습니다.\n";
		std::this_thread::sleep_for(3s);

		return "100.100.100.100";
	}
};

class DNSProxy : public IDNS
{
public:
	std::string get_host_ip(const std::string& url)
	{
		if (url == "www.samsung.com")
			return "200.200.200.200";

		DNS dns;
		return dns.get_host_ip(url);
	}
};

class Machine
{
public:
	void work(IDNS* dns)
	{
		std::cout << dns.get_host_ip("www.samsung.com") << std::endl;
	}
};

int main()
{
	Machine m;

//	DNS dns;
	DNSProxy dns;
	m.work(&dns);	
}