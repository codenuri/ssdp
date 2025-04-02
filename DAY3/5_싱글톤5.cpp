#include <iostream>
#include <mutex>

// RAII IDioms
// �ڿ��� ȹ��� �ݳ��� "������/�Ҹ���" �� ���ؼ� �ڵ����� �ǵ��� �ؾ� �Ѵ�!!

// => Resource Acquision Is Initialization
// => �ڿ��� �Ҵ�Ǵ� ���� (�ڿ�������ü��) �ʱ�ȭ �����̴�.
//    ��� �ǹ�...



template<typename T>
class lock_guard
{
	T& mtx;
public:
	lock_guard(T& m) : mtx(m) { mtx.lock(); }
	~lock_guard()             { mtx.unlock(); }
};




class Cursor
{
private:
	Cursor() {}
	Cursor(const Cursor&) = delete;
	Cursor& operator=(const Cursor&) = delete;


	static Cursor* sinstance;
	static std::mutex mtx;
public:

	static Cursor& get_instance()
	{
	
		std::lock_guard<std::mutex> g(mtx);  // C++ ǥ�ؿ� �̹� �ֽ��ϴ�.

//		lock_guard<std::mutex> g(mtx);
				// #1. g�� �����ڿ��� lock
				// #2. g�ı��� �Ҹ��ڿ��� unlock
				// #3. �Լ� �߰��� return ���� �ְų� ���ܰ� ���͵�
				//	   g�� �����ϰ� �ı� �ȴ� - �Ҹ��� ȣ��ǰ� unlock
				// #4. �Լ� �߰����� unlock �Ϸ��� {} �� ����ϼ���
				
//		mtx.lock();

		if (sinstance == nullptr)
			sinstance = new Cursor;
		
//		mtx.unlock();

		return *sinstance;
	}


};
Cursor* Cursor::sinstance = nullptr;
std::mutex Cursor::mtx;




int main()
{
	Cursor& c1 = Cursor::get_instance();

}






