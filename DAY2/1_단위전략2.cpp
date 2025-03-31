#include <iostream>

// ��� #1. template method ���� ���
// => ���ؾ� �ϴ� �κ��� �����Լ��� ����
// => �Ļ� Ŭ�������� �����Ҽ� �ְ�

// Ư¡(����)
// => �Ʒ� �ڵ忡�� �޸� �Ҵ�/���� ����� MallocVector �� �����ϰ� �ȴ�.
// => set, map, list ���� �ٸ� �����̳� �� �޸� ���� ����� �����ϰ� �ʹٸ�
//    �ٽ� �Ļ� Ŭ������ ������ �Ѵ�!!

// => �޸� �Ҵ�/���� ����� �پ��� �����̳ʰ� �����ϰ� �Ҽ� ������?


template<typename T>
class vector
{
	T* ptr;
	std::size_t size;
public:
	vector(std::size_t  size) : size(size)
	{
		ptr = allocate(size);
	}
	~vector()
	{
		deallocate(ptr, size);
	}

	virtual T* allocate(std::size_t sz) { return new T[sz]; }
	virtual void deallocate(T* p, std::size_t sz) { delete[] p; }
};
//---------------------
template<typename T>
class MallocVector : public vector<T>
{
public:
	MallocVector(std::size_t size) : vector<T>(size) {}

	T* allocate(std::size_t sz) override 
	{ 
		return static_cast<T*>(malloc(sizeof(T) * sz));
	}
	void deallocate(T* p, std::size_t sz) override 
	{ 
		free(p);
	}
};

int main()
{
//	vector<int> v(4);
	MallocVector<int> v(4);
}
