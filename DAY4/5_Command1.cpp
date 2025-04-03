#include <iostream>
#include "monitor.h"

class ResolutionCommand
{
	Monitor& m;
	int value;
public:
	ResolutionCommand(Monitor& m, int v) : m(m), value(v) {}

	void execute() { m.set_resolution(value);}
};

int main()
{
	Monitor m;

	// m �� �ػ󵵸� 1920���� �����ϰ� �ʹ�.

	// ��� #1. ��� �Լ��� ���� ȣ��
	m.set_resolution(1920);


	// ��� #2. Command ������ ���
	ResolutionCommand cmd(n, 1920);
	cmd.execute();
}