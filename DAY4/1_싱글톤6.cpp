#include <iostream>
#include <mutex>

template<typename T>
class Singleton
{
private:
	Singleton() {}
	Singleton(const Singleton&) = delete;
	Singleton& operator=(const Singleton&) = delete;

	static Singleton* pinstance;
	static std::mutex mtx;
public:

	static Singleton& getInstance()
	{
		std::lock_guard<std::mutex> g(mtx); 

		if (pinstance == nullptr)
			pinstance = new Mouse;

		return *pinstance;
	}
};
std::mutex Singleton::mtx;
Singleton* Singleton::pinstance = nullptr;


// Mouse 도 힙에 만드는 싱글톤을 사용하고 싶다.
class Mouse : public Singleton
{
public:
};



int main()
{
	Cursor& c1 = Cursor::getInstance();
}









