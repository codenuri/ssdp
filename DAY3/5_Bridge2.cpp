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

// MediaPlayer 의 기능을 확장해서 StreamMediaPlayer, RecordingMediaPlayer 를 만들고 싶다
// => 아래처럼 생각하면
class FFmpegStreamMediaPlayer    : public FFmpegMediaPlayer {};
class FFmpegRecordingMediaPlayer : public FFmpegMediaPlayer {};

class HardwareStreamMediaPlayer    : public HardwareMediaPlayer {};
class HardwareRecordingMediaPlayer : public HardwareMediaPlayer {};

// => 서로 다른 코덱으로 구현한 MediaPlayer 가 5개 이고 각각
// => StreamMediaPlayer, RecordingPlayer 를 모두 상속으로 만들면
// => 총 10개의 클래스가 된다!! 너무 클래스가 많고 계층도가 복잡해 진다!!
// => 이렇때 사용하는 패턴이 Bridge 패턴



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


