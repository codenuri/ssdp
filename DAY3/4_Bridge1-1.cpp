#include <iostream>

struct IMP3
{
	virtual void Play() = 0;
	virtual void Stop() = 0;
	virtual ~IMP3() {}
};

class IPod : public IMP3
{
public:
	void Play() { std::cout << "Play MP3 with IPod" << std::endl; }
	void Stop() { std::cout << "Stop" << std::endl; }
};

// 구현을 담은 계층과(IMP3, IPod등)
// 실제 클라이언트가 사용하는 클래스(MP3, Brdge)를 분리해서
// 상호 독립적인 update 가 가능하게 한다.

class MP3
{
	IMP3* engine;
public:
	MP3(IMP3* p = nullptr) : engine(p)
	{
		if (engine == nullptr)
			engine = new IPod;
	}
	
	// 실제 기능의 구현은 구현계층에 의존합니다.
	void Play() { engine->Play(); }
	void Stop() { engine->Stop(); }

	void PlayOneMinute()
	{
		Play();
		// 1분 있다가
		Stop();
	}
};
//==================================
// 이제 사용자는 "MP3" 만 사용해야 합니다.
class People
{
public:
	void Use(MP3* p) 
	{
		p->Play();
		p->Stop();

		// 그런데, 사용자가 요구사항이 자주 변경된다.
		// "1분미리듣기" 기능을 요구 한다.
	}
};





int main()
{
	People p;
	IPod pod;
	p.Use(&pod);
}


