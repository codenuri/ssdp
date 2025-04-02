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
		WSADATA w;
		WSAStartup(0x202, &w);
	}
	~NetworkInit()
	{
		WSACleanup();
	}
};
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

//-----------------------------------------------
// TCP Server 를 만들려면
// => 라이브러리 내부의 몇개 클래스를 사용해서
// => 몇가지 절차를 거쳐야 합니다.

// 위 과정 자체가 "하나의 책임(TCPServer 만들기)" 입니다.
// => 이 복잡한 과정은 한가지 인터페이스로 제공하는 
// => 사용하기 쉬운 클래스 제공
// => facade 패턴

class TCPServer
{
	NetworkInit init;
	Socket sock(SOCK_STREAM); 
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
	// 최종 사용자 코드
	// => 사용하기 쉬워 졌습니다.
	// => 복잡 한 과정을 단순화 하는 상위 계층의 클래스 때문에!!!
	TCPServer server;
	server.Start("100.100.100.100", 4000);

}
