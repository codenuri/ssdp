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
// Bridge ����
// => ����� �����ϴ� ������ ���� �ϴ� ������ �и����ڴ� ��

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

	// �߻������� ����� ��û�� ó��
	void play_one_minute()
	{
		engine->play();

		// Ÿ�̸� ��ġ�ؼ� 1���Ŀ�
		engine->stop();
	}
};

class People
{
public:
//	void use(IMP3* p)	// ���������� ���� ����ϴ� �ڵ�
	void use(MP3* p)	// ���� ������ ����ϴ� �ڵ�
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


