#include <iostream>
#include <mutex>

// CRTP : Curiously Recurring Template Pattern
// => 기반 클래스에서 미래에 만들어질 파생 클래스의 이름을 사용할수
//    있게 하는 패턴
// => 기반 클래스를 템플릿으로 만들고
//    파생 클래스 만들때 상속받으면서 자신의 클래스 이름을
//    기반 클래스 템플릿 인자로 전달하는 기술

// class Mouse : public Singleton< Mouse >


template<typename T>
class Singleton
{
protected:
	Singleton() {}

	Singleton(const Singleton&) = delete;
	Singleton& operator=(const Singleton&) = delete;

	static T* pinstance;    //<==== T
	static std::mutex mtx;
public:

	static T& getInstance()   //<==== T
	{
		std::lock_guard<std::mutex> g(mtx); 

		if (pinstance == nullptr)
			pinstance = new T;  // <==== T

		return *pinstance;
	}
};
template<typename T> std::mutex Singleton<T>::mtx;
template<typename T> T* Singleton<T>::pinstance = nullptr;


// Mouse 도 힙에 만드는 싱글톤을 사용하고 싶다.
class Mouse : public Singleton< Mouse  >
{
public:
};

int main()
{
	Mouse& c1 = Mouse::getInstance();
}









