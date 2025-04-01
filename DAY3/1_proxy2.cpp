#include <iostream>
#include <thread>
#include <string>
#include <chrono>
using namespace std::literals;


class DNS
{
public:
	std::string get_host_ip(const std::string& url)
	{
		std::cout << "서버에 접속해서 URL 에 대한 IP 정보를 얻습니다.\n";
		std::this_thread::sleep_for(3s);

		return "100.100.100.100";
	}
};

class DNSProxy
{
public:
	std::string get_host_ip(const std::string& url)
	{
		// 요청한 URL 에 local DB에 있는지 찾아서 있으면 
		// 바로 반환 합니다
		if (url == "www.samsung.com")
			return "200.200.200.200";
		
		// local DB 에 없다면 DNS 클래스를 사용해서 
		// 서버에 접속해서 IP 를 얻습니다.
		DNS dns;
		return dns.get_host_ip(url);
	}
};

int main()
{
	DNS dns;

	std::cout << dns.get_host_ip("www.samsung.com") << std::endl;
}



