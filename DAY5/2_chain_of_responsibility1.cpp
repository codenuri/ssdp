#include <iostream>

// chain of responsibility
// => 책임의 고리(연쇄, 전달) 으로 번역!
// => 다양하게 활용되는데, 잘 알려지지 않은 패턴.


// 핵심 
// 문제가 발생하면
// 1. 객체가 처리를 시도하고
// 2. 처리하지 못하고 next 가 있다면 옆으로 전달.
// 3. 옆의 객체가 1번을 반복


// 아래 코드가 "책임의 전가 패턴의 핵심" 입니다.
struct Handler
{
	Handler* next = nullptr;

	// 이 부분이 핵심
	void Handle(int problem)
	{
		// #1. 자신이 처리를 시도, 처리했으면 종료
		if (HandleRequest(problem) == true)
			return;

		// #2. 자신이 처리하지 못하고, 옆팀이 있으면 전달
		if (next != 0)
			next->Handle(problem);
	}

	virtual bool HandleRequest(int problem) = 0;
};

class Team1 : public Handler
{
public:
	bool HandleRequest(int problem) override
	{
		std::cout << "Start Team1\n";

		if (problem == 7)
		{
			std::cout << "Resolved by Team1\n";
			return true;
		}
		return false;
	}
};

class Team2 : public Handler
{
public:
	bool HandleRequest(int problem) override
	{
		std::cout << "Start Team2\n";

		if (problem % 2 == 0)
		{
			std::cout << "Resolved by Team2\n";
			return true;
		}
		return false;
	}
};

class Team3 : public Handler
{
public:
	bool HandleRequest(int problem) override
	{
		std::cout << "Start Team3\n";

		if ( problem < 10)
		{
			std::cout << "Resolved by Team3\n";
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

	t1.next = &t2;
	t2.next = &t3;
	t3.next = 0;

	// 문제가 발생하면 1번팀에 전달
//	t1.Handle(7); // Team1 이 해결
//	t1.Handle(20); // Team2 가 해결

//	t1.Handle(5);	// Team3 이 해결
	t1.Handle(15);	// 해결 안됨
}
