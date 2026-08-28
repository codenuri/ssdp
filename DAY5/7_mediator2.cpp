#include <iostream>
#include <conio.h>

// 움직임을 포착하는 센서
// 빛을 감지해서 점심/저녁을 구별하는 센서 

// 모든 센서 클래스의 기반 클래스
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

		// 센서 상태가 변경되면 약속된 가상함수 호출
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

		// 상태가 변경되면 약속된 가상함수 호출
		changed();
	}
};

// 움직임이 감지되면 전등을 켜기로 했다
class MyMotionSensor : public MotionSensor
{
public:
	void changed() override
	{
		if (get_motion() == true)
			std::cout << "전등켜기\n";
		else
			std::cout << "전등끄기\n";
	}
};


int main()
{
	LightSensor ls;
	ls.set_dark(true);	

	MyMotionSensor ms;
	ms.set_motion(true);	// 움직임이 포착
	ms.set_motion(false);	// 움직임이 없다
}