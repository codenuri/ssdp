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
		for (auto f : notif_map[key])	// notif_map[key] ����Ÿ�ε�
		{								// ���� ����Ÿ�� vector

			f(hint);	
		}
	}
};

void foo(void* p)        { std::cout << "foo : " << (int)p << std::endl; }
void goo(void* p, int a) { std::cout << "goo : " << (int)p << std::endl; }

int main()
{
	// IOS �뺸 ���͸� ����� ���ô�. - ������ �Դϴ�.
	NotificationCenter nc;

	nc.addObserver("LOWBATTERY", &foo);
	nc.addObserver("LOWBATTERY",      std::bind(&goo, _1, 1) );
	nc.addObserver("DISCONNECT_WIFI", std::bind(&goo, _1, 2) );

	// ���͸� ����ʿ��� ���͸��� ����������
	nc.postNotificationWithName("LOWBATTERY", (void*)30);

	// ������ �Ʒ� ó�� �������� ������
	// => �켱������ �ο� �Ҽ� �ְ�
	// => ������� ȣ��ɼ� �ֵ��� �غ�����
	// Poco ��� C++ ���¼ҽ� ��Ʈ��ũ ���̺귯���� �Ʒ� ó���Ǿ� �ֽ��ϴ�.
//	nc.addObserver("LOWBATTERY", &f1, �켱����_10);
//	nc.addObserver("LOWBATTERY", &f2, �켱����_20);
//	nc.addObserver("LOWBATTERY", &f3, �켱����_30, NEW_THREAD);
}




