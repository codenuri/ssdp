#include <iostream>
#include <vector>
#include <string>

// main 함수가 에러나지 않도록 File/Folder 완성해 보세요
// 공통의 기반클래스는 "Item" 으로 하세요.

class Item
{
	std::string name;
public:
	Item(const std::string& name) 
		: name(name) {}

	virtual ~Item() {}

	// 파일/폴더 모두 크기는 구할수 있다
	virtual int get_size() = 0;
};

class File : public Item 
{
	int size;
public:
	File(const std::string& name, int size)
		: Item(name), size(size) {}

	virtual int get_size() override { return size; }
};

class Folder : public Item
{
	std::vector<Item*> v; // 핵심
public:
	Folder(const std::string& name) 
		: Item(name) {}

	void add_item(Item* p) { v.push_back(p); }

	virtual int get_size() override
	{
		int size = 0;
		for (auto p : v)
			size += p->get_size();

		return size;
	}
};



int main()
{
	Folder* root = new Folder("ROOT");
	Folder* fo1  = new Folder("A");
	Folder* fo2  = new Folder("B");
	
	root->add_item(fo1);
	root->add_item(fo2);

	File* f1 = new File("a.txt", 10);
	File* f2 = new File("b.txt", 20);

	fo1->add_item(f1);
	root->add_item(f2);

	// 파일은 자신만의 크기는 있습니다.
	// 폴더는 자신만의 크기는 없지만 크기를 구할수 있습니다.
	std::cout << f2->get_size() << std::endl; // 20
	std::cout << fo1->get_size() << std::endl; // 10
	std::cout << root->get_size() << std::endl; // 30
}

