#include <iostream>
#include <list>
#include <vector>

// �湮���� �������̽�
template<typename T> 
struct IVisitor
{
	virtual void visit(T& e) = 0;
	virtual ~IVisitor() {}
};

// �湮�� �ٽ� : ��� �Ѱ��� ���� ������ ���� �Ѱ�
template<typename T>
class TwiceVisitor : public IVisitor<T>
{
public:
	void visit(T& e) { e *= 2; }
};

template<typename T>
class ShowVisitor : public IVisitor<T>
{
public:
	void visit(T& e) { std::cout << e << std::endl; }
};



// std::list �� ���� ��ӹ޾Ƽ� "�湮�����ϱ��" �߰�
template<typename T>
class MyList : public std::list<T>
{
public:
	// ������ ��� ���� : ��� Ŭ���� ��� �����ڸ� MyList ��
	//					����Ҽ� �ְ� �ش޶�� ��
	using std::list<T>::list;   // std::list<T> Ÿ���̸�,
								// list �»������̸�

	void accept(IVisitor<T>* v) 
	{
		// �ڽ��� ��� ��Ҹ� �湮�ڿ� ������ �˴ϴ�
		for (auto& e : *this)
			v->visit(e);
	}
};

int main()
{
	MyList<int> s = { 1,2,3,4,5,6,7,8,9,10 };

	TwiceVisitor<int> tv;
	s.accept(&tv);			

	ShowVisitor<int> sv;	
	s.accept(&sv);


	ZeroVisitor<int> zv; // �湮�ϴ� ��Ҹ� 0���� 
	s.accept(&zv);


	s.accept(&sv); // �ٽ� ���
}





