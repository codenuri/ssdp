#include <iostream>
#include <thread>
#include <string>
#include <chrono>
using namespace std::literals;

// Proxy 78p ~

// URL => IP Address �� �������ִ� Ŭ����
class DNS
{
public:
	std::string get_host_ip(const std::string& url)
	{
		std::cout << "������ �����ؼ� URL �� ���� IP ������ ����ϴ�.\n";
		std::this_thread::sleep_for(3s);

		return "100.100.100.100";
	}
};

int main()
{
	DNS dns;

	std::cout << dns.get_host_ip("www.samsung.com") << std::endl;
}



