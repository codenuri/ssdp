#include <iostream>
#include "monitor.h"

// � �۾��� �����ϸ�
// => �ش��ϴ� �۾��� �Ҽ� �ֽ��ϴ�.
// => ��� �ϱ� ���� ����Ÿ�� �ʿ��ϸ� �ܺο��� ������ ����Ÿ�� �����ؾ� �մϴ�.

// � �۾��� �����ϱ� ���� Ŭ������ �����ϸ�
// => �� �۾��� �����Ҽ��� �ְ�
// => ����ϴ� ����� ����� �ְ�
// => ��ҿ� �ʿ��� ����Ÿ�� �����Ҽ� �ְ�
// => �ش� ����� ���� ���� ��������(N/W ���� ����� ����Ÿ ���� �ȵ�)
//    �� ���������մϴ�.

// command : ����� Ŭ������ ����.
// => undo ���� �����ϰ� �Ѵ�.


class ResolutionCommand
{
	Monitor& m;
	int value;
	int old_value = 0;
public:
	ResolutionCommand(Monitor& m, int v) : m(m), value(v) {}

	void execute() 
	{ 
		old_value = m.get_resolution();
		m.set_resolution(value); 
	}
	void undo()
	{
		m.set_resolution(old_value);
	}
};

int main()
{
	Monitor m;

	int old_value = m.get_resolution();
	m.set_resolution(1920);

	// ���⼭ �� ����� ���(����Ǳ� �������·�) �غ�����
	m.set_resolution(old_value);


	ResolutionCommand cmd(m, 1920);
	cmd.execute();
	cmd.undo();
}