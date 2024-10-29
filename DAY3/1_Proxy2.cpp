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

//	std::cout << dns.resolve("www.samsung.com") << std::endl;
	std::cout << dns.resolve("www.naver.com") << std::endl;
}

// Proxy  패턴
// => 다양한 이유로 기존 클래스를 대신하는 것을 만들어 사용하는 패턴

// DNSProxy 는 DNS 에 Cache 기능을 추가하므로
// => 기능의 추가(decorator) 패턴 아닌가요 ??

// decorator : origin 도 계속 사용가능...
// proxy     : origin 을 대신해서 사용

FileStream fs("a.txt");
ZipDecorator zd(&fs);
zd.write("aaa"); // 기능을 추가한 것을 사용해도 되고
fs.write("aaa"); // origin 도 사용가능. 

// proxy
//DNS dns; // 이것을 사용하지 말고!!
DNSProxy dns; // 이것을 사용해라!!
			  // Proxy 가 필요할때 원래 객체 사용

// DNSProxy : DNS 에 캐쉬 기능을 추가하려고 만든것
// 이외에도 다양한 Proxy 기술이 있습니다. - 다음예제.