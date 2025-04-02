#include <iostream>
#include <vector>

class Subject;	// 클래스 전방 선언
				// 다른 파일에 있거나, 선언이 아래 부분에 있는 클래스의
				// 포인터만 먼저 만들때 사용

struct IGraph
{
	virtual void update(int data) = 0;
	virtual ~IGraph() {}

	// 관찰자들도 자신이 누구를 관찰하는지 알아야 합니다
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
	int data[4] = { 1,2,3,4 };
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

		// Table 이 수정되었다고 통보가 왔으므로
		// Table 에 접근해서 data 를 얻어온후..
		// 그래프를 그리면 됩니다.

//		int* data = subject->get_data();
						// error.
						// subject 는 Subject* 타입이기 때문에
						// Table 고유 함수 접근 안됩니다. 캐스팅 필요

		int* data = static_cast<Table*>(subject)->get_data();

		// 이제 data 의 내용으로 그래프를 그리면 됩니다.

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






