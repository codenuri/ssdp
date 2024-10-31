#include <iostream>
#include <vector>


class Subject; // 클래스 전방선언
				// 완전한 선언이 없어도 포인터 변수는 사용가능

struct IGraph
{
	virtual void update(int data) = 0;
	virtual ~IGraph() {}

	// 모든 관찰자(그래프)는 관찰의 대상(Table)을 알게 하게 위해서
	Subject* subject = nullptr;
};

class Subject
{
	std::vector<IGraph*> v;
public:
	virtual ~Subject() {}

	void attach(IGraph* p) 
	{ 
		v.push_back(p); 

		p->subject = this;
	}

	void detach(IGraph* p) { }
	void notify(int data)
	{
		for (auto p : v)
			p->update(data);
	}
};

class Table : public Subject
{
	int value;

	int data[5] = { 1,2,3,4,5 };
public:

	int* get_data() { return data; }

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
		// Table 이 변경되었다고 통보가 왔으므로
		// 다시 Table에 접근해서 Data 를 가져 온다

//		int* data = subject->get_data(); // error
										// subject 는 Table을 가리키지만
										// "Subject*" 이므로 error

		Table* table = static_cast<Table*>(subject);

		int* data = table->get_data();

		// 이제 data 배열을 사용해서 그래프를 update 하면 됩니다.


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





