#include <iostream>
#include <vector>

struct IGraph
{
	virtual void update(int data) = 0;
	virtual ~IGraph() {}
};

// 관찰자 패턴의 기본 로직은
// 관찰의 대상이 다루는 데이터 종류에 상관없이 항상 동일합니다.
// 관찰자 패턴의 기본 로직을 제공하는 기반 클래스를 설계 합니다.

class Subject
{
	std::vector<IGraph*> v;
public:
	void attach(IGraph* p) { v.push_back(p);	}
	void detach(IGraph* p) {v.erase(std::remove(v.begin(), v.end(), p), v.end());	}
	void notify(int data)  
	{
		for (auto p : v)
			p->update(data);
	}
};
// Subject 클래스 : 관찰자 패턴의 기본 로직을 제공하는 기반 클래스
// Table   클래스 : 관찰의 대상이 다루는 데이터 관리

// 라이브러리 내부 : Subject, IGraph 제공
// 라이브러리 사용자 : Table, BarGraph 등을 작성

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
	Table table;

	BarGraph bg;
	PieGraph pg;

	table.attach(&bg);
	table.attach(&pg);

	table.edit();
}





