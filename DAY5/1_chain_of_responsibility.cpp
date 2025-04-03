#include <iostream>

// chain of responsibility - 166

// 아래 코드가 "chain of responsibility" 의 핵심 입니다.
struct Handler
{
	Handler* next = nullptr;

	Handler* set_next(Handler* n) 
	{ 
		next = n; 
		return next; 
	}

	// 아래 함수가 핵심
	void handle(int problem)
	{
		// #1. 자신이 먼저 처리를 시도
		if (resolve(problem) == true)
			return;

		// #2. 자신이 처리하지 못한경우 고리에 따라 옆으로 전달
		if (next != nullptr )
			next->handle(problem);
	}

	virtual bool resolve(int problem) = 0;
};

class Team1 : public Handler
{
public:
	bool resolve(int problem) override
	{
		std::cout << "Start Team1\n";

		if (problem == 7)
		{
			std::cout << "Team1이 해결\n";
			return true;
		}
		return false;
	}
};
class Team2 : public Handler
{
public:
	bool resolve(int problem) override
	{
		std::cout << "Start Team2\n";

		if (problem % 2 == 0)
		{
			std::cout << "Team2이 해결\n";
			return true;
		}
		return false;
	}
};

class Team3 : public Handler
{
public:
	bool resolve(int problem) override
	{
		std::cout << "Start Team3\n";

		if (problem < 10)
		{
			std::cout << "Team3이 해결\n";
			return true;
		}
		return false;
	}
};
int main()
{
	Team1 t1;
	Team2 t2;
	Team3 t3;

	// t1 => t2 => t3 로 연결
	t1.set_next(&t2)->set_next(&t3);
				// method chaining 
				// 메소드(함수)를 연속적으로 호출하는 기술

	t1.handle(7); // Team1 이 해결
//	t1.handle(2);
//	t1.handle(3);
//	t1.handle(13);
}
