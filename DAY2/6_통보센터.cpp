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
	// IOS 개발에 사용되는 "cocoa" 라이브러리에는 통보센터가 있습니다.
	NotificationCenter nc;

	nc.add_observer("LOWBATTERY", &foo);
	nc.add_observer("LOWBATTERY", std::bind(&goo, _1, 0) );

	// 배터리 모듈쪽에서 배터리가 부족해지면
	nc.post_notification_with_name("LOWBATTERY", (void*)30);


	// 도전 과제 : poco 라는 C++ 네트워크 오픈소스 가 아래 같은 기능이 있습니다.
	// 
	// 1. 우선순위 부여해 보세요
	/*
	nc.add_observer("DISCONNECT_WIFI", &f1, PRIORITY_1);
	nc.add_observer("DISCONNECT_WIFI", &f2, PRIORITY_3);
	nc.add_observer("DISCONNECT_WIFI", &f3, PRIORITY_2);

	// 2. 멀티 스레도 도입해 보세요
	nc.add_observer("DISCONNECT_WIFI", &f4, PRIORITY_1, NEW_THREAD);
	nc.add_observer("DISCONNECT_WIFI", &f5, PRIORITY_2);
	*/
}




