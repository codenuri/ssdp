#include "monitor.h"

// ������� ��⸦ �����Ϸ���
// 1. ��⸦ �����ϴ� ��� �Լ��� ���� ȣ��
// 2. ������� ��⸦ �����ϴ� ���� �ϴ� ��ü ��� - command ����


int main()
{
	Monitor m;
	m.info();

	m.set_brightness(90);
	m.info();
}