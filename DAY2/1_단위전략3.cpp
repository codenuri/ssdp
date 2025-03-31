#include <iostream>

// ��� #2. strategy ���� ���
// => ���ϴ� ��(��å, �˰���)�� �ٸ� Ŭ������ �и�.

// �޸� �Ҵ���� �������̽�
template<typename T> struct IAllocator
{
	virtual T* allocate(std::size_t sz) = 0;
	virtual void deallocate(T* p, std::size_t sz) = 0;

	virtual ~IAllocator() {}
};

template<typename T>
class vector
{
	T* ptr;
	std::size_t size;

	IAllocator<T>* ax = nullptr;
public:
	vector(std::size_t  size, IAllocator<T>* p ) 
		: size(size), ax(p)
	{
		ptr = ax->allocate(size);	// �޸� �Ҵ�/������
									// allocator ��ü�� ����
	}
	~vector()
	{
		ax->deallocate(ptr, size);
	}
};
// ���� �پ��� �޸� �Ҵ�⸦ �����˴ϴ�.
// => �޸��� �Ҵ�/������ å������ Ŭ����
template<typename T>
class MallocAllocator : public IAllocator<T>
{
public:
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
	MallocAllocator<int> ma;
	vector<int> v(4, &ma);
}
