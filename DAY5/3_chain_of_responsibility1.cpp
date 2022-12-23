// 3_chain_of_responsibility.cpp			- 179 page

#include <iostream>

struct Handler
{
	Handler* next = nullptr;

	void Handle(int problem)
	{
		// 1. 자신이 가진 가상함수를 호출해서 처리를 시도
		if (HandleRequest(problem) == true)
			return;

		// 2. 자신이 처리하지 못한 경우 고리에 따라 요청을 다른 객체에 전달
		if (next != 0)
			next->Handle(problem);
	}

	virtual bool HandleRequest(int problem) = 0;
};
// 위 Handler 가 책임의 전가 패턴의 기본 로직을 구현한것
// 이제 요청을 처리하는 다양한 클래스를 설계 하면 됩니다.

class TenHandler : public Handler
{
public:
	virtual bool HandleRequest(int problem) override
	{
		std::cout << "Start TenHandler" << std::endl;

		if (problem == 10)
		{
			std::cout << "Resolve!!! Problem" << std::endl;
			return true;
		}
		std::cout << "Finish TenHandler" << std::endl;
		return false;
	}
};

class OddHandler : public Handler
{
public:
	virtual bool HandleRequest(int problem) override
	{
		std::cout << "Start OddHandler" << std::endl;

		if (problem % 2 == 1)
		{
			std::cout << "Resolve!!! Problem" << std::endl;
			return true;
		}
		std::cout << "Finish OddHandler" << std::endl;
		return false;
	}
};

class More100Handler : public Handler
{
public:
	virtual bool HandleRequest(int problem) override
	{
		std::cout << "Start More100Handler" << std::endl;

		if (problem >= 100)
		{
			std::cout << "Resolve!!! Problem" << std::endl;
			return true;
		}
		std::cout << "Finish More100Handler" << std::endl;
		return false;
	}
};

int main()
{
	TenHandler h1;
	OddHandler h2;
	More100Handler h3;

	h1.next = &h2;
	h2.next = &h3;

	h1.Handle(10);
}