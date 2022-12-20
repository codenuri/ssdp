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


// 객체지향 프로그램에서 "프로그램이란 ?"

// 1. 객체를 생성하고
// 2. 객체간의 관계를 설정하고
// 3. 객체간의 메세지를 주고 받는 과정이다(멤버 함수를 호출한다는 의미)

// 4. 프로그램의 기본 단위는 "함수" 가 아닌 "클래스" 이다.

// Composite 패턴
// => 객체의 포함 관계를 나타내는 패턴

// => 복합객체(PopupMenu, Folder)는 개별객체(MenuItem, File) 뿐 아니라 
//    복합객체 자신도 보관한다.
//		=> 복합객체와 개별객체의 공통의 기반 클래스가 필요 하다.


// => 복합객체와 개별객체는 사용법이 동일하다.(command(), get_size())
//		=> 동일시 하는 함수는 "기반 클래스"에 있어야 한다.


// => 객체의 포함 관계가 "tree 구조"로 구현 되는 패턴










