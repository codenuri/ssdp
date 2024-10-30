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

// 
// IMP3 를 직접 사용하게 되면
// => 요구사항이 자주 발생하게되면 IMP3 자체가 수정되어야 합니다.
// => 인터페이스의 변경은 아주 어려운 작업입니다.

// 사용자들이 IMP3 가 아닌 중간층을 사용하게 합니다.
class MP3
{
	IMP3* impl;
public:
	MP3(IMP3* p = nullptr) : impl(p) 
	{
		if (impl == nullptr)
			impl = new IPod;
	}

};



class People
{
public:
//	void use(IPod* p)	// 강한 결합, 한가지 제품만 사용가능. 교체 안됨.
	void use(IMP3* p)	// 약한 결합, 교체 가능. 다른 제품 사용가능
	{
		p->play();
		p->stop();

		// 요구조건이 생겼다.(1분 미리 듣기)
		p->play_one_minute();
	}
};

int main()
{
	People p;
	IPod pod;
	p.Use(&pod);
}


