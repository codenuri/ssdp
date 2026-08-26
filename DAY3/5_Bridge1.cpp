// 6_Bridge1 - 90 page
#include <iostream>
// 다양한 Codec 을 활용가능하도록 인터페이스를 먼저 설계
struct IMediaPlayer
{
	virtual void play() = 0;
	virtual ~IMediaPlayer() {}
};

// 음악을 play 하는 클래스
class FFmpegMediaPlayer : public IMediaPlayer
{
public:
	void play() { std::cout << "using FFmpeg\n"; }
};
class HardwareMediaPlayer : public IMediaPlayer
{
public:
	void play() { std::cout << "using Hardware Codec\n"; }
};



class People
{
public:
	void use(IMediaPlayer* p)
	{
		p->play();
	}
};
int main()
{
	People p;
	FFmpegMediaPlayer player;
	p.use(&player);
}


