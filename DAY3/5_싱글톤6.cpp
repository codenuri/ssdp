#include <iostream>
#include <mutex>

// CRTP
// => Curiously Recurring Template Pattern
// => ��� Ŭ�������� "�Ļ� Ŭ������ Ŭ�����̸�" �� ����Ҽ� �ְ� �ϴ� ���
// => ��� Ŭ������ ���ø� ���ڷ� �Ļ� Ŭ���� �̸��� �����ϴ� ���

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


// Mouse Ŭ������ ���� ���� �̱������� �ϰ� �ʹ�.
class Mouse : public Singleton< Mouse  >
{
public:
};


int main()
{
	Mouse& m = Mouse::get_instance();

}






