#include <iostream>
#include <conio.h>


struct IMediator
{
	virtual void changed() = 0;
	virtual ~IMediator() {}
};



// 모든 협력자(센서)는 서로를 알필요 없지만
// 중재자(Mediator)는 알아야 합니다

class Device
{
protected:
	IMediator* mediator;
public:
	void set_mediator(IMediator* m) { mediator = m; }
	virtual void changed() {}
};

class LightSensor : public Device
{
	bool dark = false;
public:
	using Device::Device; // 생성자 상속

	bool get_dark() const { return dark; }

	void set_dark(bool dark)
	{
		std::cout << "Environment: " << (dark ? "dark" : "bright") << '\n';
		this->dark = dark;

		// 자신의 상태가 변경되면 반드시 중재자에게 알려 줍니다.
		// => 다른 협력자(센서)에게 알릴 필요없고, 다른 센서를 조사할필요도 없습니다
		// => 오직 중재자에게만 알리면 됩니다.
		mediator->changed();

		changed();
	}
};

class MotionSensor : public Device
{
	bool detected = false;
public:
	using Device::Device;

	bool get_motion() const { return detected; }
	void set_motion(bool detected)
	{
		std::cout << "Motion: " << (detected ? "detected" : "none") << '\n';
		this->detected = detected;

		mediator->changed();
		changed();
	}
};

// 가정집의 센서와 전기제품을 관리하는 중재자
// 모든 센서와 전기 제품을 알고 있어야 한다.
class HomeMediator : public IMediator
{
	LightSensor* ls;
	MotionSensor* ms;
public:
	HomeMediator(LightSensor* s1, MotionSensor* s2) : ls(s1), ms(s2) 
	{
		s1->set_mediator(this);
		s2->set_mediator(this);
	}

	// 모든 센서는 변화가 생기면 아래 함수를 호출합니다.
	// => 여기서 센서에 따른 전기제품을 컨트롤 합니다.
	void changed() override
	{
		if (ls->get_dark() == true && ms->get_motion())
		{
			std::cout << "전등켜기\n";
		}
		else
		{
			std::cout << "전등끄기\n";
		}
	}
};


int main()
{
	LightSensor ls;
	MotionSensor ms;

	// 이제 모든 센서들의 중재자 생성
	HomeMediator hm(&ls, &ms);


	ls.set_dark(true);	// 전등 끄기. 아직움직임 없음
//	ls.set_dark(false);

	ms.set_motion(true);	// 움직임이 포착 - 전등 켜짐
	ls.set_dark(false);	    // 다시 밝아짐 - 전등 꺼짐

	ms.set_motion(false);	// 움직임이 없다
}

// A, B, C, D 객체가 있고, 서로의 상태를 조사해서 어떤일을 해야 한다면
// 1. 중재자가 없으면
// => 서로가 서로를 직접 알아야 합니다 - N:M 의 관계. 
// => 너무 복잡해 지고, 필연적으로 코드 중복 발생

// 2. 중재자가 있다면
// => A, B, C, D 는 서로을 알필요 없고, 오직 중재자만 알면 됩니다. - 1:N 의 관계
// => 중재자만 A,B, C,D 를 알면되고
// => 이벤트에 따른 작업은 오직 중재자에서 모두 이루어집니다.
// => 작업규칙을 변경시 편리합니다.
