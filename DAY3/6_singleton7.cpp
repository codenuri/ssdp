#include <iostream>
#include <mutex>

// CRTP
// => 기반 클래스 만들때 미래에 만들어질 파생 클래스의 이름을 
// => 기반 클래스 내부에서 사용하는 기술

template<typename T>
class Singleton
{
private:
	Singleton() {}
	Singleton(const Singleton&) = delete;
	Singleton operator=(const Singleton&) = delete;

	// inline static 문법 : static 멤버 데이타의 외부 선언이 없어도 됩니다 - C++17 부터
	inline static std::mutex mtx;
	inline static T* sinstance;
public:
	static T& get_instance()
	{
		std::lock_guard<std::mutex> g(mtx);

		if (sinstance == nullptr)
		{
			sinstance = new T;
		}

		return *sinstance;
	}
};
// Keyboard 클래스도 위와 같은 Singleton 기술을 사용하고 싶다
class Keyboard : public Singleton< Keyboard >
{

};


int main()
{
	Keyboard& k1 = Keyboard::get_instance();
	Keyboard& k2 = Keyboard::get_instance();

	std::cout << &k1 << std::endl;
	std::cout << &k2 << std::endl;

}












