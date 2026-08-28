//1_관찰자패턴1 - 97 page
#include <iostream>
#include <vector>

// 모든 그래프(챠트)의 인터페이스
struct IGraph
{
	virtual void update(int data) = 0;
	virtual ~IGraph() {}
};

// 엑셀의 표를 클래스로 만든것
class Table
{
	int value; // table 의 data 값

	// 엑셀의 표는 여러개의 그래프(관찰자, Observer)와 연결
	std::vector<IGraph*> v;	
public:
	void attach(IGraph* p) 
	{ 
		v.push_back(p); 
	}
	void detach(IGraph* p) 
	{
		v.erase( std::remove( v.begin(), v.end(), p), v.end() );
	}
	void notify(int data)
	{
		// 등록된 모든 그래프에 알려준다.
		for (auto p : v)
			p->update(data);
	}
	void edit()
	{
		while (1)
		{
			// 데이타를 새롭게 입력
			std::cout << "Data >>";
			std::cin >> value;

			// 데이타가 변경되었으므로 모든 관찰자에 통보
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

	// 관찰의 대상(table) 에 여러개의 관찰자(graph) 연결
	table.attach(&bg);
	table.attach(&pg);

	// table 편집모드로 변경
	table.edit();
}





