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

// TCP Server 를 만들려면 
// 1. 몇개의 클래스를 사용해서
// 2. 일련의 절차를 수행해야 합니다.
// => 이런 작업도 "하나의 책임(TCPServer라는 책임)" 입니다.

// 이런 과정을 단순화 해서 "하나의 인터페이스(함수)로 제공" 하는 클래스를 만들어라
// => "facade" 패턴

class TCPServer
{
	NetworkInit init;
//	Socket sock(SOCK_STREAM); // 멤버 데이타에서는 () 초기화하면 에러
	Socket sock{SOCK_STREAM}; // {} 로 해야 합니다.
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
	TCPServer server;
	server.Start("127.0.0.1", 4000);
}
