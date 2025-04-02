#include <iostream>
#include <mutex>

// CRTP
// => Curiously Recurring Template Pattern
// => 기반 클래스에서 "파생 클래스의 클래스이름" 을 사용할수 있게 하는 기술
// => 기반 클래스의 템플릿 인자로 파생 클래스 이름을 전달하는 기술

template<typename T>
class Singleton
{
protected:
	Singleton() {}

	Singleton(const Singleton&) = delete;
	Singleton& operator=(const Singleton&) = delete;

	static T* sinstance;			// <===
	static std::mutex mtx;
public:

	static T& get_instance()		// <===
	{
		std::lock_guard<std::mutex> g(mtx);  

		if (sinstance == nullptr)
			sinstance = new T;		// <==

		return *sinstance;
	}
};
template<typename T> T* Singleton<T>::sinstance = nullptr;
template<typename T> std::mutex Singleton<T>::mtx;


// Mouse 클래스도 위와 같은 싱글톤으로 하고 싶다.
class Mouse : public Singleton< Mouse  >
{
public:
};


int main()
{
	Mouse& m = Mouse::get_instance();

}






