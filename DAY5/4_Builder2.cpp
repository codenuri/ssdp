// Builder - 154
#include <iostream>
#include <string>

// 축구게임 캐릭터를 생각해 봅시다.
// 모자, 유니폼, 신발등을 변경할수 있습니다.
typedef std::string Hat;			// class Hat{}
typedef std::string Uniform;	    // class Uniform{}
typedef std::string Shoes;			// class Shoes{}
typedef std::string Character;		// class Character{}라고 가정

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
		// 이 클래스는 변하지 않은 만드는 공정(순서)만 가지고 있습니다
		builder->make_hat();
		builder->make_uniform();
		builder->make_shoes();
		return builder->get_result();
	}
};

// 각각의 공정을 만드는 빌더(세부 부품을 만들어내는 클래스)
class Korean : public IBuilder
{
	Character c;
public:
	void make_hat() override        { c += Hat("갓\n"); }
	void make_uniform() override    { c += Uniform("한복\n"); }
	void make_shoes() override      { c += Shoes("짚신\n"); }
	Character get_result() override { return c; }
};

class American : public IBuilder
{
	Character c;
public:
	void make_hat() override { c += Hat("야구모자\n"); }
	void make_uniform() override { c += Uniform("양복\n"); }
	void make_shoes() override { c += Shoes("구두\n"); }
	Character get_result() override { return c; }
};

int main()
{
	Korean k;
	American a;
	
	Director d;
	d.set_builder(&k);  //<== 국가 선택을 변경하면 이곳을 변경
//	d.set_builder(&a);

	Character c = d.construct();
	std::cout << c << std::endl;

}
