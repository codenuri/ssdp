#include <iostream>
#include <vector>
class Subject;

struct IGraph
{
	virtual void update(int data) = 0;
	virtual ~IGraph() {}
	
	// 대부분의 활용에서 "관찰자" 들은 "관찰의 대상의 주소"를 보관하게 됩니다.
	// => 그래야 변경된 데이터를 얻어올수 있습니다.
	Subject* subject = nullptr;
};


class Subject
{
	std::vector<IGraph*> v;
public:
	void attach(IGraph* p) 
	{ 
		p->subject = this;

		v.push_back(p); 
	}
	void detach(IGraph* p) { v.erase(std::remove(v.begin(), v.end(), p), v.end()); }
	void notify(int data)
	{
		for (auto p : v)
			p->update(data);
	}
};

class Table : public Subject
{
	int value;

	// 관찰의 대상에는 많은 데이터가 있을수 있다
	int data[10] = { 1,2,3,4,5,6,7,8,9,10 };
public:

	// 자신의 데이터를 관찰자가 읽어 갈수 있도록 함수 제공
	const int* get_data() const { return data; }


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
	void update(int hint) override
	{
		// 관찰의 대상이 변경되었다고 통보가 왔다
		// 1. 인자로 무엇이 변경되었는지 힌트가 같이 전달되었는데
		//    이 데이터로 충분하다면 그냥 사용

		// 2. 그런데, 힌트로 부족하면 Table 에 접근해서 data 읽어서 사용
		// 현재 subject : Subject* 타입
		// get_data     : Table 멤버 함수 
		// => 따라서 캐스팅 필요

		Table* table = static_cast<Table*>(subject);
		const int* data = table->get_data();

		// 이제 data 를 사용하면 됩니다.(챠트 그리기)


		std::cout << "Bar Graph : ";

		for (int i = 0; i < 10; i++)
			std::cout << data[i] << ", ";

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
