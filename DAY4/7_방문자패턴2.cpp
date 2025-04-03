#include <iostream>
#include <list>
#include <vector>

// visitor ����
// 
// �ݺ���(iterator) : ���հ�ü�� ��� ��Ҹ� ������ ������� ����
// �湮��(visitor)  : ���հ�ü�� ��� ��Ҹ� ������ ������� �������
//					=> ��� �Ѱ��� ���� ������ ���� �ϴ� ��ü.

int main()
{
	std::list<int> s = { 1,2,3,4,5,6,7,8,9,10 };

	// s�� ��� ��Ҹ� 2��� �ϰ� �ʹ�.
	// ��� #1. �ܺο��� ��� ��Ҹ� ������ 2��� �Ѵ�.
	for (auto& e : s)
	{
		e *= 2;
	}
	
	// ��� #2. �湮�� ������ ����մϴ�.
	TwiceVisitor<int> tv;
	s.Accept(&tv);			// tv �� s�� ��� ��Ҹ� 2��� �մϴ�.


	ShowVisitor<int> sv;	// �湮�ϴ� ��Ҹ� ����ϴ� �湮��
	s.Accept(&sv);


}





