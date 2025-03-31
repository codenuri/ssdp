// ������1.cpp - 3page
#include <iostream>

// �Ʒ� �ڵ忡�� ������ ��� ã�� ������
// �ٽ� : Base Ŭ������ ����Ʈ �����ڰ� �����ϴ�.
class Base
{
public:
	Base(int a) {  }
};
class Derived : public Base
{
public:
	// #1. Base ����Ʈ �����ڰ� ���� ��� �Ʒ� ó�� ����� ������
	//     �߻��ϴ� ������ ��Ȯ�� �˾ƾ� �մϴ�.
	/*
	Derived()      
	{ 
		// call Base::Base()
	}

	Derived(int a) 
	{
		// call Base::Base()
	}
	*/
	
	// #2. �ذ�å. ����ڰ� ��� Ŭ������ ����Ʈ�� �ƴ� �ٸ� �����ڸ�
	//     ȣ���ϵ����ؾ� �մϴ�.
	// => �ʱ�ȭ ����Ʈ �������� ǥ��
	Derived() : Base(0)
	{
		// call Base::Base(0)
	}

	Derived(int a) : Base(a)
	{
		// call Base::Base(a)
	}

};
int main()
{
}
