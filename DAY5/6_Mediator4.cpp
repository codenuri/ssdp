#include <iostream>
#include <string>
#include <map>
#include <functional>
#include <vector>
using namespace std::placeholders;


class NotificationCenter
{
	using HANDLER = std::function<void(void*)>;

	std::map<std::string, std::vector<HANDLER> > notif_map;
public:
	void addObserver(const std::string& key, HANDLER h)
	{
		notif_map[key].push_back(h);
	}

	void postNotificationWithName(const std::string& key, void* hint)
	{
		for (auto f : notif_map[key])	// notif_map[key] 데이타인데
		{								// 현재 데이타는 vector

			f(hint);	
		}
	}
};

void foo(void* p)        { std::cout << "foo : " << (int)p << std::endl; }
void goo(void* p, int a) { std::cout << "goo : " << (int)p << std::endl; }

int main()
{
	// IOS 통보 센터를 만들어 봅시다. - 중재자 입니다.
	NotificationCenter nc;

	nc.addObserver("LOWBATTERY", &foo);
	nc.addObserver("LOWBATTERY",      std::bind(&goo, _1, 1) );
	nc.addObserver("DISCONNECT_WIFI", std::bind(&goo, _1, 2) );

	// 배터리 모듈쪽에서 배터리가 부족해지면
	nc.postNotificationWithName("LOWBATTERY", (void*)30);

	// 복습시 아래 처럼 발전시켜 보세요
	// => 우선순위를 부여 할수 있고
	// => 스레드로 호출될수 있도록 해보세요
	// Poco 라는 C++ 오픈소스 네트워크 라이브러리가 아래 처럼되어 있습니다.
//	nc.addObserver("LOWBATTERY", &f1, 우선순위_10);
//	nc.addObserver("LOWBATTERY", &f2, 우선순위_20);
//	nc.addObserver("LOWBATTERY", &f3, 우선순위_30, NEW_THREAD);
}




