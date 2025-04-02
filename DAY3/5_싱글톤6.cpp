#include <iostream>
#include <mutex>


class Singleton
{
private:
	Singleton() {}
	Singleton(const Singleton&) = delete;
	Singleton& operator=(const Singleton&) = delete;

	static Singleton* sinstance;
	static std::mutex mtx;
public:

	static Singleton& get_instance()
	{
		std::lock_guard<std::mutex> g(mtx);  

		if (sinstance == nullptr)
			sinstance = new Singleton;

		return *sinstance;
	}
};
Singleton* Singleton::sinstance = nullptr;
std::mutex Singleton::mtx;

// Mouse 클래스도 위와 같은 싱글톤으로 하고 싶다.
class Mouse : public Singleton
{
public:
};

int main()
{
	Mouse& m = Mouse::get_instance();

}






