#include <iostream>

// Bridge 패턴
// => 구현과 추상을 분리해서
// => "서로 독립적인 업데이트/확장 이 가능하게 한다"
// 아래 인터페이스과 2개 클래스가 "구현계층"
struct IAudioBackend
{
	virtual void play() = 0;
	virtual ~IAudioBackend() {}
};
class FFmpegBackend : public IAudioBackend
{
public:
	void play() { std::cout << "using FFmpeg\n"; }
};
class HardwareBackend : public IAudioBackend
{
public:
	void play() { std::cout << "using Hardware Codec\n"; }
};
//-------------------------------------
// 사용자는 위의 구현을 직접 사용하지 않습니다.
// 아래 추상 층을 사용합니다.
class MediaPlayer
{
	IAudioBackend* engine;
public:
	MediaPlayer(IAudioBackend* e) : engine(e) {}

	void change_engine(IAudioBackend* e) { engine = e; }

	// 실제 음악 기능은 구현 계층에 의존합니다.
	void play() { engine->play(); }
};

// 이제 MediaPlayer 라는 추상층은 구현과 상관없이 마음대로 update, 확장 가능합니다
// => 구현과 상관없이..
// => "추상적인 계층" 을 계속 확장(상속등)해 나갈수 있다.
// => bridge2.cpp 는 다양한 구현 클래스별로 상속하므로 클래스 가 많아진다
// => 하지만 이 코드는 한개의 추상에서만 상속
class StreamMediaPlayer    : public MediaPlayer 
{ 
public:
	using MediaPlayer::MediaPlayer;
};
class RecordingMediaPlayer : public MediaPlayer 
{
public:
	using MediaPlayer::MediaPlayer;
};

class People
{
public:
	// 추상층을 사용
	void use(MediaPlayer* p)
	{
		p->play();
	}
};
int main()
{
	People p;
	FFmpegBackend ffmpeg;
	MediaPlayer player(&ffmpeg);

	p.use(&player);
}


