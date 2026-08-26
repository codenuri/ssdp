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

// 라이브러리 설계자가 위와 같은 클래스를 제공했다면
// 사용자는 아래 처럼만 만들면 됩니다.
// facade1.cpp 보다는 쉽습니다.

int main()
{
	NetworkInit init;

	Socket sock(SOCK_STREAM); // TCP 서버

	IPAddress addr("127.0.0.1", 4000);
	sock.Bind(&addr);
	sock.Listen();
	sock.Accept();

}
