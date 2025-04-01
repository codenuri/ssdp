#include <iostream>
#include <vector>
#include <string>

// 탐색기를 객체지향 프로그램으로 만들어 봅시다.

class Component
{
	std::string name;
public:
	Component(const std::string& name) : name(name) {}

	virtual ~Component() {}

	// File, Folder 모두 크기는 구할수 있다.
	virtual int get_size() = 0;
};

class File : public Component
{
	int size;
public:
	File(const std::string& name, int size)
		: Component(name), size(size) {
	}
	int get_size() override { return size; }
};

// main 이 실행되도록 아래 폴더 완성해 보세요. 
class Folder : public Component
{
	std::vector< Component* > v;
public:
	Folder(const std::string& name) : Component(name) {}

	void add(Component* c) { v.push_back(c); }

	int get_size() override
	{
		int sz = 0;
		for (auto p : v)
			sz += p->get_size();

		return sz;

	}
};

int main()
{
	Folder* root = new Folder("ROOT");
	Folder* fo1  = new Folder("A");
	Folder* fo2  = new Folder("B");
	
	root->add(fo1);
	root->add(fo2);

	File* f1 = new File("a.txt", 10);
	File* f2 = new File("b.txt", 20);

	fo1->add(f1);
	root->add(f2);

	// 파일은 자신만의 크기는 있습니다.
	// 폴더는 자신만의 크기는 없지만 크기를 구할수 있습니다.
	std::cout << f2->get_size() << std::endl; // 20
	std::cout << fo1->get_size() << std::endl; // 10
	std::cout << root->get_size() << std::endl; // 30
}

