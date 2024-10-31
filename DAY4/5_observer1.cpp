//1_관찰자패턴1 - 94 page
#include <iostream>
#include <vector>


// 챠트(그래프, 관찰자)의 인터페이스
struct IGraph
{
	virtual void update(int data) = 0;
	virtual ~IGraph() {}
};


// 관찰의 대상(엑셀의 테이블)
class Table
{
	std::vector<IGraph*> v;

	int value; // table 의 data 값

public:
	void attach(IGraph* p) { v.push_back(p); }
	void detach(IGraph* p) { }
	void notify(int data)
	{
		// 등록된 모든 그래프에 알려준다.
		for (auto p : v)
			p->update(data);
	}

	// 테이블 편집함수
	void edit()
	{
		while (1)
		{
			std::cout << "Data >>";
			std::cin >> value;	// 데이타 변경되면
			notify(value);		// 등록된 모든 관찰자(그래프)에 통보
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
	PieGraph pg; t.attach(&pg);
	BarGraph bg; t.attach(&bg);
	t.edit();
}





