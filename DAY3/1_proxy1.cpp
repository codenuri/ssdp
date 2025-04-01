#include <iostream>
#include <thread>
#include <string>
#include <chrono>
using namespace std::literals;

// Proxy 78p ~

// URL => IP Address 로 변경해주는 클래스
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

int main()
{
	DNS dns;

	std::cout << dns.get_host_ip("www.samsung.com") << std::endl;
}



