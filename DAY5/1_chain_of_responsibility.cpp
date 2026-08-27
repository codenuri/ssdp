#include <iostream>

// chain of responsibility - 166
// => 책임의 고리(전가) 등으로 번역되는 디자인 패턴

// => 어떤 문제(이벤트)등에 대한 처리를 고리에 따라 연결된 여러객체들이 처리할수 있는 
//    기회를 제공하는 패턴


struct Handler
{
	Handler* next = nullptr;

	Handler* set_next(Handler* n) 
	{ 
		next = n; 
		return next; 
	}


	// 이 예제의 핵심
	void handle(int problem)
	{
		// #1. 자신의 resolve() 함수에서 문제 해결시도
		if (resolve(problem) == true)	// 문제 해결시 
			return;						// 종료

		// #2. 자신이 해결하지 못한 경우
		//     next 객체가 있다면 "전달" 하고 없으면 종료
		if (next != 0)
			next->handle(problem);
	}

	virtual bool resolve(int problem) = 0;
};
//------------------------------------
// 위 Handler : 책임의 전가 패턴의 기본 로직을 제공
// 파생 클래스에서 다양한 문제 해결방식을 제공

class Team1 : public Handler
{
public:
	bool resolve(int problem) override
	{
		std::cout << "start Team1\n";

		if (problem == 7)
		{
			std::cout << "Team1 : Resolve the Problem\n";
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
		std::cout << "start Team2\n";

		if (problem % 2 == 1)
		{
			std::cout << "Team2 : Resolve the Problem\n";
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
		std::cout << "start Team3\n";

		if (problem > 10)
		{
			std::cout << "Team3 : Resolve the Problem\n";
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

	// Team1 -> Team2 -> Team3 순서
	t1.set_next(&t2)->set_next(&t3);

	// 이제 문제(이벤트)를 1번째 객체에 전달하면
	// 고리에 따라 이동하면서 문제를 해결합니다.
	t1.handle(7);
}
