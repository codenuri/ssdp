// 32비트로 빌드해야 합니다
// => "x64" => "x86" 으로 변경
// server 폴더에 있는 cppmaster.h 를 day3 폴더에 복사해주세요
#define USING_GUI
#include "cppmaster.h"

// client 를 아래 처럼 만들면

// #1. 1은 덧셈, 2는 뺄셈이라는 명령 코드를 항상 외우고 있어야 한다.
// => 명령코드는 많을수 있습니다.

// #2. 모든 클라이언트 제작자는 IPC 기술을 알아야 합니다.

// #3. 서버 장애 발생시, 모든 클라이언트에서 각각 장애 처리를 해야 합니다.

// 해결책
// => 원격지 서버를 대신하는 클래스(proxy) 제공. 








int main()
{
	// 1. 서버의 핸들을 얻어 옵니다.
	int server = ec_find_server("Calc");

	std::cout << "서버 번호 : " << server << std::endl;

	// 2. 서버에 명령코드와 파라미터를 전달합니다.
	int n1 = ec_send_server(server, 1, 10, 20);
	int n2 = ec_send_server(server, 2, 10, 20);

	std::cout << n1 << ", " << n2 << std::endl;

}






// git 에서 server.zip 받아서 압축 풀고
// 새로운 visual studio 에서 server.sln 여세요
