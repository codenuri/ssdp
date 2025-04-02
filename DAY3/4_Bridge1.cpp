// 6_Bridge1 - 90 page
#include <iostream>

struct IMP3
{
	virtual void play() = 0;
	virtual void stop() = 0;
	virtual ~IMP3() {}
};

class IPod : public IMP3
{
public:
	void play() { std::cout << "Play MP3 with IPod" << std::endl; }
	void stop() { std::cout << "Stop" << std::endl; }
};

class People
{
public:
//	void use(IPod* p)	// 강한 결합 : 교체 불가능한 디자인
	void use(IMP3* p)	// 약한 결합 : 교체 가능한 유연한 디자인
	{
		p->play();
		p->stop();

		// 사용자가 1분 미리 듣기 기능을 요구한다.
		// => 약한 결합은 교체는 가능하지만 요청에 대한 처리는 어렵다
		// => 해결은 다음소스에서
		p->play_one_minute();
	}
};

int main()
{
	People p;
	IPod pod;
	p.Use(&pod);
}


