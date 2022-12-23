#include <iostream>
#include <string>
#include <map>
#include <functional>
#include <vector>
using namespace std::placeholders;


class NotificationCenter
{
	using HANDLER = std::function<void(void*)>;

	std::map< std::string, std::vector<HANDLER> > notif_map;
public:

	void add_observer(const std::string& key, HANDLER h)
	{
		notif_map[key].push_back(h);
	}

	void post_notification_with_name(const std::string& key, void* hint)
	{
		for (auto h : notif_map[key])  // notif_map[key] 는 결국 vector
		{
			h(hint);
		}
	}

};



void foo(void* p)        { std::cout << "foo : " << (int)p << std::endl; }
void goo(void* p, int a) { std::cout << "goo : " << (int)p << std::endl; }


int main()
{
	NotificationCenter nc;

	nc.add_observer("LOWBATTERY", &foo);
	nc.add_observer("LOWBATTERY", std::bind(&goo, _1, 0) );

	// 배터리 모듈쪽에서 배터리가 부족해지면
	nc.post_notification_with_name("LOWBATTERY", (void*)30);
}




