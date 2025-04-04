// Builder - 154
#include <iostream>
#include <string>

// �౸���� ĳ���͸� ������ ���ô�.
// ����, ������, �Źߵ��� �����Ҽ� �ֽ��ϴ�.
typedef std::string Hat;			// class Hat{}
typedef std::string Uniform;	    // class Uniform{}
typedef std::string Shoes;			// class Shoes{}
typedef std::string Character;		// class Character{}��� ����

//---------------------------------------------------

struct IBuilder
{
	virtual void make_hat() = 0;
	virtual void make_uniform() = 0;
	virtual void make_shoes() = 0;
	virtual Character get_result() = 0;

	virtual ~IBuilder() {}
};

class Director
{
	IBuilder* builder = nullptr;
public:
	void set_builder(IBuilder* b) { builder = b; }

	Character construct()
	{
		// �� Ŭ������ ������ ���� ����� ����(����)�� ������ �ֽ��ϴ�
		builder->make_hat();
		builder->make_uniform();
		builder->make_shoes();
		return builder->get_result();
	}
};

// ������ ������ ����� ����(���� ��ǰ�� ������ Ŭ����)
class Korean : public IBuilder
{
	Character c;
public:
	void make_hat() override        { c += Hat("��\n"); }
	void make_uniform() override    { c += Uniform("�Ѻ�\n"); }
	void make_shoes() override      { c += Shoes("¤��\n"); }
	Character get_result() override { return c; }
};

class American : public IBuilder
{
	Character c;
public:
	void make_hat() override { c += Hat("�߱�����\n"); }
	void make_uniform() override { c += Uniform("�纹\n"); }
	void make_shoes() override { c += Shoes("����\n"); }
	Character get_result() override { return c; }
};

int main()
{
	Korean k;
	American a;
	
	Director d;
	d.set_builder(&k);  //<== ���� ������ �����ϸ� �̰��� ����
//	d.set_builder(&a);

	Character c = d.construct();
	std::cout << c << std::endl;

}
