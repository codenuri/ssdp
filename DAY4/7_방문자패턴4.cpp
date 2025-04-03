#include <iostream>
#include <list>
#include <vector>

// �������� ������ ���Ͽ����� "�湮��3.cpp" ó��
// IVisitor �������̽��� ����� �˴ϴ�.

// �̹����� ���� ��Ÿ�Ϸ� ������ ���ô�.



template<typename T>
class MyList : public std::list<T>
{
public:
	using std::list<T>::list;   

	// �پ��� �湮�ڸ� �ޱ� ���ؼ� �������̽��� �ƴ� template ����
	template<typename V>
	void accept( V v )
	{
		for (auto& e : *this)
			v(e); // v �� �Լ� ó��()�� ȣ�Ⱑ���ؾ� �Ѵ�.
	}
};

int main()
{
	MyList<int> s = { 1,2,3,4,5,6,7,8,9,10 };

	s.accept( [](int& e) { e *= 2; } );

	s.accept([](int e) { std::cout << e << std::endl; });
	

	// �� �ڵ尡 �ڹٿ� �ֽ��ϴ�.
	// => �ڹٿ����� accept �� �ƴϰ� forEach �Դϴ�.
//	s.forEach( ���� ǥ���� )
}





