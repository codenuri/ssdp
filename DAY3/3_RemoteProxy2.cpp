// #1. server.zip 압축 푸세요
// => 새로운 visual studio 에서 열어보세요
// => "빌드시 32bit(x86) 으로 해야 합니다."


#define USING_GUI
#include "cppmaster.h"

int main()
{
	// 1. 서버의 핸들을 얻어 옵니다.
	int server = ec_find_server("Calc");

	std::cout << "서버 번호 : " << server << std::endl;


	// 2. 서버에 명령코드와 파라미터를 전달합니다.
	// => int 값 3개 전달
	int n1 = ec_send_server(server, 1, 10, 20); // 10 + 20 의 결과좀 달라
	int n2 = ec_send_server(server, 2, 10, 20); // 10 - 20 의 결과좀 달라

	std::cout << n1 << ", " << n2 << std::endl;

}





