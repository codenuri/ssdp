﻿#include <iostream>
#include <vector>
#include <string>








// 아래 주석의 내용을 보고, main 함수가 실행될수 있도록, File/Folder 클래스를 완성해 보세요

// 1. Folder 는 File 을 보관하지만 Folder 자신도 보관할수 있습니다.
// 2. Folder 는 이름만 있습니다. ( std::string name )
// 3. File 은   이름과 크기가 있습니다. ( std::string name, int size)
// 4. File, Folder 모두 크기를 구할수 있습니다. ( get_size() )



class Component
{
	std::string name;
public:
	Component(const std::string& name) : name(name) {}

	virtual ~Component() {}

	// File Folder 모두 크기를 구할수 있습니다.
	virtual int get_size() = 0;
};

class File  : public Component
{
	int size;
public:
	File(const std::string& name, int size)
		: Component(name), size(size) {}

	int get_size() override { return size; }
};

class Folder : public Component
{
	std::vector<Component*> v; // "Composite" 패턴의 핵심
public:
	Folder(const std::string& name) : Component(name) {}

	void add(Component* c) { v.push_back(c); }

	int get_size() override 
	{
		int sz = 0;

		for (auto f : v)
			sz += f->get_size();

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

