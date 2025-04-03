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


int main()
{
}
