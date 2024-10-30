#include <iostream>
#include <mutex>


// CRTP : Curiously Recurring Template Pattern
// => 기반 클래스에서 미래에 만들어질 파생 클래스 이름을
//    사용할수 있게 하는 패턴

// => 원리 : 파생 클래스 만들때 자신의 이름을
//			기반 클래스의 템플릿 인자로 전달

// 요즘.. 너무나 유행하는 기술
// C++20의 Ranges 라는 표준 라이브러리가 이 기술로 작성됨. 


template<typename T>
class Singleton
{
protected:
	Singleton() {}
	Singleton(const Singleton&) = delete;
	Singleton& operator=(const Singleton&) = delete;

	static T* sinstance;
	static std::mutex mtx;
public:

	static T& get_instance()
	{
		std::lock_guard<std::mutex> g(mtx);

		if (sinstance == nullptr)
			sinstance = new T;

		return *sinstance;
	}
};
template<typename T> T* Singleton<T>::sinstance = nullptr;
template<typename T> std::mutex Singleton<T>::mtx;

// Mouse 클래스도 위처럼 힙에 만드는 싱글톤으로 하고 싶다.
class Mouse : public Singleton< Mouse  >
{

};

int main()
{
	Mouse& c1 = Mouse::get_instance();

}


// github.com/aosp-mirror  에 접속해 보세요
//						(aosp : android open source project)

// system platform core  레포지토리 선택

// libutils/include/utils 에서 Singleton.h 열어 보세요



