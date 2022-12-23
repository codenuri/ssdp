#include <iostream>
#include <vector>

class Subject;

struct IGraph
{
	virtual void Update(int data) = 0;
	virtual ~IGraph() {}

	// 관찰자들(Graph) 도 자신이 누구를 관찰중인지 알아야 합니다.
	Subject* subject = nullptr;
};



class Subject
{
	std::vector<IGraph*> v;
public:
	void attach(IGraph* p) 
	{
		v.push_back(p); 

		p->subject = this;
	}

	void detach(IGraph* p) {}
	void notify(int data)
	{
		for (auto p : v)
			p->Update(data);
	}
};

// 핵심 : 관찰의 대상(Table)이 다루는 데이타가 복잡하게 있는 경우.
class Table : public Subject
{
	int value;

	int income[12] = { 1,3,5,7,9,2,4,6,8,10,11,12 }; // 월별 매출
public:

	int* get_income() { return income; }


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
	// 관찰의 대상이 변경되면 아래 함수가 호출됩니다.
	void Update(int n) override
	{
		// 이제 Table 에 접근해서 변경된 데이타를 다시 읽어서
		// 화면에 출력하면 됩니다.

//		int* income = subject->get_income(); // error
											// subject 는 "Subject*" 이므로
											// 캐스팅 필요
		int* income = static_cast<Table*>(subject)->get_income();

		std::cout << "Bar Graph : ";

		for (int i = 0; i < 12; i++)
			std::cout << income[i] << ", ";

		std::cout << std::endl;
	}
};






class PieGraph : public IGraph
{
public:
	void Update(int n) override
	{
		int* income = static_cast<Table*>(subject)->get_income();

		std::cout << "Pie Graph : ";

		for (int i = 0; i < 12; i++)
			std::cout << income[i] << ", ";

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





