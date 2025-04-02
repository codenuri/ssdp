#include <iostream>
#include <mutex>

// CRTP
// => ��� Ŭ�������� "�Ļ� Ŭ������ Ŭ�����̸�" �� ����Ҽ� �ְ� �ϴ� ���

template<typename T>
class Singleton
{
private:
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
T* Singleton::sinstance = nullptr;
std::mutex Singleton::mtx;


// Mouse Ŭ������ ���� ���� �̱������� �ϰ� �ʹ�.
class Mouse : public Singleton< Mouse  >
{
public:
};


int main()
{
	Mouse& m = Mouse::get_instance();

}






