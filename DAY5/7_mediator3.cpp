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

// "움직임이 감지되고 & 밤이면" 전등을 켜기로 했다
// => 아래 처럼 만들면 "여러 센서들이 서로를 알아야 합니다" A 처럼
// => 디자인패턴에서는 현재 코드의 센서들을 "협력자라고표현" 합니다.

// => 각 협력자가 "다른 협력자를 알아야 하고"
// => 아래와같이 전등 켜기 결정을 여러 센서의 코드에 중복이 있을수 있습니다.
// => 이걸 해결하는 것이 "중재자(Mediator)" 패턴 입니다.

class MyMotionSensor : public MotionSensor
{
	LightSensor* light_sensor; // <=== A
public:
	MyMotionSensor(LightSensor* s) : light_sensor(s) {}

	void changed() override
	{
		if (get_motion() == true && light_sensor->get_dark() == true )
			std::cout << "전등켜기\n";
		else
			std::cout << "전등끄기\n";
	}
};


int main()
{
	LightSensor ls;
	ls.set_dark(true);
//	ls.set_dark(false);

	MyMotionSensor ms(&ls);
	ms.set_motion(true);	// 움직임이 포착
	ms.set_motion(false);	// 움직임이 없다
}