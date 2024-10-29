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

int main()
{
	DNS dns;

	std::cout << dns.resolve("www.samsung.com") << std::endl;
}