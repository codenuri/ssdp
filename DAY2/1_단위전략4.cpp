#include <iostream>

// ��� #3. policy base design (�������� ������ ���)
// => ���ϴ� ��(��å, �˰���)�� �ٸ� Ŭ������ �и��ϴµ�

// => ��ü �Ҷ� �������̽� ����� �ƴ϶� ���ø� ���ڷ� �����ϴ� ��
// => �����Լ��� ������尡 ����, �ζ��� ġȯ���� Ư¡�� Ȱ���Ҽ��ִ�

// => �̶� �������̽��� �����Ƿ� �Լ��̸�(allocate, deallocate) ��
//    ����ȭ�ؼ� ��ӵǾ�� �Ѵ�.



// std::allocator<T>  : C++ ǥ���� �����ϴ� �޸� �Ҵ��
//						allocate/deallocate �� �̹� �ְ�
//						new, delete ����մϴ�.

template<typename T, typename Allocator = std::allocator<T> >
class vector
{
	T* ptr;
	std::size_t size;

	Allocator ax;

public:
	vector(std::size_t  size) : size(size)
	{
		ptr = ax.allocate(size);	
	}
	~vector()
	{
		ax.deallocate(ptr, size);
	}
};
template<typename T>
class MallocAllocator 
{
public:
	inline T* allocate(std::size_t sz) 
	{
		return static_cast<T*>(malloc(sizeof(T) * sz));
	}
	inline void deallocate(T* p, std::size_t sz)
	{
		free(p);
	}
};
int main()
{
//	vector<int, MallocAllocator<int> > v(4);

	vector<int > v(4);
}
