//1_관찰자패턴1 - 97 page
#include <iostream>
#include <vector>

struct IGraph
{
	virtual void update(int data) = 0;
	virtual ~IGraph() {}
};

// 관찰의 대상이 가진 데이타에 관련없이
// 관찰자 패턴의 로직은 동일합니다
// 기반 클래스로제공합니다.
// 관찰자 패턴에서 관찰의 대상을 "Subject" 라고 합니다.

class Subject
{
	std::vector<IGraph*> v;
public:
	virtual ~Subject() {}
	void attach(IGraph* p) { v.push_back(p); }
	void detach(IGraph* p) {}
	void notify(int data)
	{
		for (auto p : v)
			p->update(data);
	}
};

class Table : public Subject
{
	int value; 
public:
	void edit()
	{
		while (1)
		{
			std::cout << "Data >>";
			std::cin >> value;
			notify(value);
		}
	}
};
//----------------------
class BarGraph : public IGraph
{
public:
	void update(int n) override
	{
		std::cout << "Bar Graph : ";

		for (int i = 0; i < n; i++)
			std::cout << "*";

		std::cout << std::endl;
	}
};

class PieGraph : public IGraph
{
public:
	void update(int n) override
	{
		std::cout << "Pie Graph : ";

		for (int i = 0; i < n; i++)
			std::cout << ")";

		std::cout << std::endl;
	}
};

int main()
{
	Table t;

	BarGraph bg;
	PieGraph pg;

	t.attach(&bg);
	t.attach(&pg);

	t.edit(); 
}






