#define USING_GUI
#include "cppmaster.h"


#include <map>

// C 언어의 타이머 개념을 가지고 클래스를 만들어 봅시다.
class Clock
{
	inline static std::map<int, Clock*> this_map;

	std::string name;
public:
	Clock(const std::string& name) : name(name) {}

	void Start(int ms)
	{
		int id = ec_set_timer(ms, handler);

		this_map[id] = this;
	}

	static void handler(int id)
	{
		Clock* self = this_map[id];

		std::cout << self->name << std::endl;
	}
};

int main()
{
	Clock c("AAA"); // AAA 는 이름

	c.Start(1000); // 1 초에 한번씩 자신의 이름을 출력해야 합니다.

	ec_process_message();
}