#include <iostream>
#include <mutex>

class Singleton
{
private:
	Singleton() {}
	Singleton(const Singleton&) = delete;
	Singleton operator=(const Singleton&) = delete;

	// inline static 문법 : static 멤버 데이타의 외부 선언이 없어도 됩니다 - C++17 부터
	inline static std::mutex mtx;
	inline static Singleton* sinstance;
public:
	static Singleton& get_instance()
	{
		std::lock_guard<std::mutex> g(mtx);

		if (sinstance == nullptr)
		{
			sinstance = new Singleton;
		}

		return *sinstance;
	}
};


// Keyboard 클래스도 위와 같은 Singleton 기술을 사용하고 싶다

class Keybooard : public Singleton
{

};


int main()
{
	Cursor& c1 = Cursor::get_instance();
	Cursor& c2 = Cursor::get_instance();
}












