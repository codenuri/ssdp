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
public:
	Character construct()
	{
		Character c;
		c = c + Hat("�߱�����");
		c = c + Uniform("�Ķ���Ƽ����");
		c = c + Shoes("�ȭ");
		return c;
	}
};



int main()
{
	Director d;
	Character c = d.construct();
	std::cout << c << std::endl;

}
