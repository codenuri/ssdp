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
//	DNS dns;
	DNSProxy dns;

	std::cout << dns.get_host_ip("www.samsung.com") << std::endl;
	std::cout << dns.get_host_ip("www.naver.com") << std::endl;
}

// proxy 패턴
// => 다양한 이유로 기존 요소를 대신하는 클래스를 만든 것

// DNSProxy 는 "DNS 에 캐쉬 기능 추가" 이므로 
// => 기능의 추가, Decorator 아닌 가요?

// Decorator
FileStream fs("a.txt");// 원본 객체를 먼저 만들고
ZipDecorator zd(&fs);  // "객체" 에 기능 추가!!
					   // 원본 객체는 언제라도 사용가능.

// Proxy 패턴
//DNS dns;  // 원본을 사용하지 말고
DNSProxy dns; // 대행자를 만들라는 것
			  // 대행자가 내부적으로 필요할때 DNS 객체 생성


