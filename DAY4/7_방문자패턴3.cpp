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

// std::list �� ���� ��ӹ޾Ƽ� "�湮�����ϱ��" �߰�
template<typename T>
class MyList : public std::list<T>
{
public:
	void accept(IVisitor<T>* v) override
	{
		// �ڽ��� ��� ��Ҹ� �湮�ڿ� ������ �˴ϴ�
		for (auto& e : *this)
			v->visit(e);
	}
};



int main()
{
	std::list<int> s = { 1,2,3,4,5,6,7,8,9,10 };

	TwiceVisitor<int> tv;
	s.accept(&tv);			

//	ShowVisitor<int> sv;	
//	s.accept(&sv);


}





