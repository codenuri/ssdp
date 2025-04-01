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
		std::cout << "������ �����ؼ� URL �� ���� IP ������ ����ϴ�.\n";
		std::this_thread::sleep_for(3s);

		return "100.100.100.100";
	}
};

class DNSProxy
{
public:
	std::string get_host_ip(const std::string& url)
	{
		// ��û�� URL �� local DB�� �ִ��� ã�Ƽ� ������ 
		// �ٷ� ��ȯ �մϴ�
		if (url == "www.samsung.com")
			return "200.200.200.200";
		
		// local DB �� ���ٸ� DNS Ŭ������ ����ؼ� 
		// ������ �����ؼ� IP �� ����ϴ�.
		DNS dns;
		return dns.get_host_ip(url);
	}
};

int main()
{
//	DNS dns;
	DNSProxy dns;

	std::cout << dns.get_host_ip("www.samsung.com") << std::endl;
	std::cout << dns.get_host_ip("www.naver.com") << std::endl;
}

// proxy ����
// => �پ��� ������ ���� ��Ҹ� ����ϴ� Ŭ������ ���� ��

// DNSProxy �� "DNS �� ĳ�� ��� �߰�" �̹Ƿ� 
// => ����� �߰�, Decorator �ƴ� ����?

// Decorator
FileStream fs("a.txt");// ���� ��ü�� ���� �����
ZipDecorator zd(&fs);  // "��ü" �� ��� �߰�!!
					   // ���� ��ü�� ������ ��밡��.

// Proxy ����
//DNS dns;  // ������ ������� ����
DNSProxy dns; // �����ڸ� ������ ��
			  // �����ڰ� ���������� �ʿ��Ҷ� DNS ��ü ����


