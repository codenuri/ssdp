// 6_Bridge1 - 90 page
#include <iostream>

class MediaPlayer 
{
public:
	void play() { std::cout << "using FFmpeg\n"; }
};

class People
{
public:
	void use(MediaPlayer* p)
	{
		p->play();
	}
};
int main()
{
	People p;
	MediaPlayer player;
	p.use(&player);
}


