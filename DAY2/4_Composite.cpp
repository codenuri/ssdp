#include <iostream>
#include <vector>
#include <string>

// 아래 main 이 실행될수 있도록,
// => File, Folder 를 완성해 보세요
// => 공통의 기반 클래스 이름은 Component.
// => get_size() 구현이 핵심


class Component
{
	std::string name; // 폴더와 파일 모두 이름이 있습니다
public:
	Component(const std::string& name) : name(name) {}
	
	virtual ~Component() {}

	// 파일 : 자신만의 크기 있음
	// 폴더 : 자신만의 크기는 없음. 하지만 크기를 구할수는 있음
	virtual int get_size() = 0;
};

class File : public Component
{
	int size;
public:
	File(const std::string& name, int sz) : Component(name), size(sz) {}

	int get_size() override
	{
		return size;
	}
};

class Folder : public Component
{
	std::vector<Component*> v;
public:
	Folder(const std::string& name) : Component(name) {}

	void add(Component* c) { v.push_back(c); }


	int get_size() override
	{
		int sz = 0;
		for (auto c : v)
			sz += c->get_size();

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


