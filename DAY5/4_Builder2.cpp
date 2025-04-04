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



int main()
{
	Director d;
	Character c = d.construct();
	std::cout << c << std::endl;

}
