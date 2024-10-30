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
	// 실제 MP3 관련 모든 기능을 "구현층"을 사용하게 됩니다.
	// => 실제 음악 기능구현은 아주 복잡한 코드!!
	void play() { impl->play(); }
	void stop() { impl->stop(); }

	// 사용자 들에게 새로운 서비스(인터페이스 변경)를 제공하지만
	// 구현층은 수정될 필요 없다.
	// => 구현과, 인터페이스(추상층)의 독립된 업데이트
	void play_one_minute()
	{
		impl->play();

		// 1분타이머 설치후 
		impl->stop();
	}
};
// 실제 사용자는 "구현이 아닌 추상층(간접층)" 을 사용하게 합니다.

class People
{
public:
//	void use(IPod* p)	// 강한 결합, 한가지 제품만 사용가능. 교체 안됨.
//	void use(IMP3* p)	// 약한 결합, 교체 가능. 다른 제품 사용가능
	void use(MP3* p)	// 실제 구현이 아닌 간접층.
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


