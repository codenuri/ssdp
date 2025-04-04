#define USING_GUI
#include "cppmaster.h"


#include <map>

// C ����� Ÿ�̸� ������ ������ Ŭ������ ����� ���ô�.
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
	Clock c("AAA"); // AAA �� �̸�

	c.Start(1000); // 1 �ʿ� �ѹ��� �ڽ��� �̸��� ����ؾ� �մϴ�.

	ec_process_message();
}