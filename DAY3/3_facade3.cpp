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

public:
	void Start(const char* ip, short port)
	{

	}
};


int main()
{
	NetworkInit init;

	Socket sock(SOCK_STREAM); 

	IPAddress addr("127.0.0.1", 4000);
	sock.Bind(&addr);
	sock.Listen();
	sock.Accept();

}
