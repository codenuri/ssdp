#define USING_GUI
#include "cppmaster.h"


// Proxy �� ��ü �ɼ� �־�� �մϴ�.
// => �������̽��� ���� ���� �մϴ�.

struct ICalc
{
	virtual int Add(int, int) = 0;
	virtual int Sub(int, int) = 0;
	virtual ~ICalc() {}
};

class Calc : public ICalc
{
	int server;
public:
	Calc() { server = ec_find_server("Calc"); }

	int Add(int a, int b) { return ec_send_server(server, 1, a, b); }
	int Sub(int a, int b) { return ec_send_server(server, 2, a, b); }
};


int main()
{
	// proxy ������ : ���������ڰ� ����� �˴ϴ�.
	// proxy ����� : client �����ڰ� ����ϰ� �˴ϴ�.

	// �Ʒ� ó�� ����ϸ� Proxy Ŭ���� �̸��� ���� ����ϹǷ�
	// "���� ����" �Դϴ�.
	// => ��ü �Ұ����մϴ�.
	// Calc* calc = new Calc;

	// �Ʒ� ó�� ���� �������� ����ؾ� ��ü �����մϴ�.
	// => �׷��� ? ������ ������
	// => �ذ�å�� ���� �ҽ�..
	ICalc* calc = new ? ;


	int n1 = calc->Add(10, 20);
	int n2 = calc->Sub(10, 20);


	std::cout << n1 << ", " << n2 << std::endl;

}


