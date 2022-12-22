//1_관찰자패턴1 - 94 page
#include <iostream>
#include <vector>

// 모든 그래프는 공통의 기반 클래스(인터페이스)가 필요 한다.
struct IGraph
{
	virtual void Update(int data) = 0;
	virtual ~IGraph() {}
};






class Table
{
	std::vector<IGraph*> v;
	int value; // table 의 data 값
public:
	void attach(IGraph* p) { v.push_back(p); }
	void detach(IGraph* p) {}
	void notify(int data)
	{
		// 등록된 모든 그래프에 알려준다.
		for (auto p : v)
			p->Update(data);
	}
	void edit()
	{
		while (1)
		{
			std::cout << "Data >>";
			std::cin >> value;
			notify(value);	// data 가 수정되면 등록된 모든
							// Graph 에 통보한다.
		}
	}
};

//----------------------
class BarGraph : public IGraph
{
public:
	void Update(int n) override
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
	void Update(int n) override
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





