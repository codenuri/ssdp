#include <iostream>
#include <conio.h>

class Device
{
public:
	virtual void changed() {}
};

class LightSensor : public Device
{
	bool dark = false;
public:
	bool get_dark() const { return dark; }
	void set_dark(bool dark)
	{
		std::cout << "Environment: " << (dark ? "dark" : "bright") << '\n';
		this->dark = dark;
		changed();
	}
};

class MotionSensor : public Device
{
	bool detected = false;
public:
	bool get_motion() const { return detected; }
	void set_motion(bool detected)
	{
		std::cout << "Motion: " << (detected ? "detected" : "none") << '\n';
		this->detected = detected;
		changed();
	}
};

int main()
{
	LightSensor ls;
	MotionSensor ms;

	ls.set_dark(true);		// 어두워 졌다
	ms.set_motion(true);	// 움직임이 포착
}