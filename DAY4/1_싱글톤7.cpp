#include <iostream>
#include <thread>
#include <chrono>
using namespace std::literals; // "10s" 를 위해

class Cursor
{
private:
	Cursor() 
	{
		std::cout << "Cursor() start" << std::endl;

		std::this_thread::sleep_for(10s); // 10초 대기

		std::cout << "Cursor() end" << std::endl;
	}





	Cursor(const Cursor&) = delete;

	Cursor& operator=(const Cursor&) = delete;
public:

	static Cursor& getInstance()
	{
		std::cout << std::this_thread::get_id()
			      << " : start getInstance" << std::endl;
		
		static Cursor instance;


		std::cout << std::this_thread::get_id()
			      << " : finish getInstance" << std::endl;

		return instance;
	}
};


int main()
{
	std::thread t1(&Cursor::getInstance);
	std::thread t2(&Cursor::getInstance);

	t1.join();
	t2.join();

}









