#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include <iostream>
#include <WinSock2.h>
#pragma comment(lib, "ws2_32.lib")
using namespace std;



class NetworkInit
{
public:
	NetworkInit()
	{
		// 1. 네트워크 라이브러리 초기화
		WSADATA w;
		WSAStartup(0x202, &w);
	}
	~NetworkInit()
	{
		// 6. socket 라이브러리 cleanup
		WSACleanup();
	}
};


// IP 주소를 관리하는 클래스
class IPAddress
{
	SOCKADDR_IN addr;
public:
	IPAddress(const char* ip, short port)
	{
		addr.sin_family = AF_INET;
		addr.sin_port = htons(port);
		addr.sin_addr.s_addr = inet_addr(ip);
	}
	SOCKADDR* getRawAddress()
	{
		return (SOCKADDR*)&addr;
	}
};

// Socket 작업을 책임지는 클래스
class Socket
{
	int sock;
public:
	Socket(int type) { sock = socket(PF_INET, type, 0); }

	void Bind(IPAddress* ip)
	{
		::bind(sock, ip->getRawAddress(), sizeof(SOCKADDR_IN));
	}
	void Listen() { ::listen(sock, 5); }

	void Accept()
	{
		struct sockaddr_in addr2 = { 0 };
		int sz = sizeof(addr2);

		accept(sock, (SOCKADDR*)&addr2, &sz);
	}
};

// TCP 서버를 만들려면
// => 몇개의 클래스를 가지고 전형적인 몇가지 절차를 수행해야 합니다.
// => 이런 절차를 책임지는 클래스를 제공합니다

// facade
// => 몇개의 타입과 복잡한 절차가 필요한 작업을
// => 하나의 인터페이스로 해결하는 새로운 계층을 제공하라.
// => facade 는 "건물의 정면" 이라는 의미
// => C#, Python 이 수많은 facade 를 제공하는 언어.. 

class TcpServer
{
	NetworkInit init;
	Socket sock{ SOCK_STREAM };
public:
	void Start(const char* ip, short port)
	{
		IPAddress addr(ip, port);
		sock.Bind(&addr);
		sock.Listen();
		sock.Accept();
	}
};
int main()
{
	// 이제 최종 사용자는 아래 처럼 사용합니다
	TcpServer server;
	server.Start("127.0.0.1", 4000);

}
