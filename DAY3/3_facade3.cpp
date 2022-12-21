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
// => 라이브러리 내부의 몇개를 클래스를 사용해서
// => 몇가지 절차를 거쳐야 됩니다

// 이런 절차를 하나의 함수로 제공하는 포괄적 개념의 인터페이스를 제공합니다.
// => "Facade" 패턴

class TCPServer
{
	NetworkInit init;
	Socket sock{ SOCK_STREAM }; 
public: 
	void Start(const char* sip, short port)
	{
		IPAddress addr(sip, port);
		sock.Bind(&addr);
		sock.Listen();
		sock.Accept();
	}
};

int main()
{
	// 라이브러리의 최종 사용자 코드 입니다.
	TCPServer server;
	server.Start("127.0.0.1", 4000);



}