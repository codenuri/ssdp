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

//-----------------------------------------
// Bridge 패턴
// => 기능을 구현하는 계층과 서비스 하는 계층을 분리하자는 것

class MP3
{
	IMP3* engine;
public:
	MP3(IMP3* p = nullptr) : engine(p)
	{
		if (engine != nullptr)
			engine = new IPod;
	}
	void play() { engine->play(); }
	void stop() { engine->stop(); }

	// 추상층에서 사용자 요청을 처리
	void play_one_minute()
	{
		engine->play();

		// 타이머 설치해서 1분후에
		engine->stop();
	}
};

class People
{
public:
//	void use(IMP3* p)	// 구현계층을 직접 사용하는 코드
	void use(MP3* p)	// 서비스 계층을 사용하는 코드
	{
		p->play();
		p->stop();


		p->play_one_minute();
	}
};

int main()
{
	People p;
	IPod pod;
	p.Use(&pod);
}


