// 2_Builder
#include <iostream>
#include <string>

// 축구게임 캐릭터를 생각해 봅시다.
// 모자, 유니폼, 신발등을 변경할수 있습니다.
typedef std::string Hat;			// class Hat{}
typedef std::string Uniform;	    // class Uniform{}
typedef std::string Shoes;			// class Shoes{}
typedef std::string Character;		// class Character{}라고 가정

// 복잡한 형태의 객체를 만들때
// 필요한 부품을 만드는 인터페이스
struct IBuilder
{
	virtual Hat     make_hat() = 0;
	virtual Uniform make_uniform() = 0;
	virtual Shoes   make_shoes() = 0;
	virtual ~IBuilder() {}
};


// 캐릭터를 만드는 클래스
class Director
{
	IBuilder* builder = nullptr;
public:
	void set_builder(IBuilder* b) { builder = b; }

	Character construct()
	{
		// 캐릭터를 만드는 공정은 동일 합니다.
		Character c;
		c = c + builder->make_hat();
		c = c + builder->make_uniform();
		c = c + builder->make_shoes();
		return c;
	}
};

// 이제 국가별 빌더를 제공합니다.
class Korean : public IBuilder
{
public:
	Hat     make_hat()     override { return Hat("갓\n"); }
	Uniform make_uniform() override { return Uniform("한복\n"); }
	Shoes   make_shoes() override   { return Shoes("짚신\n"); }
};
class American : public IBuilder
{
public:
	Hat     make_hat()     override { return Hat("야구모자\n"); }
	Uniform make_uniform() override { return Uniform("양복\n"); }
	Shoes   make_shoes()   override { return Shoes("구두\n"); }
};
int main()
{
	American a;
	Korean k;

	Director d;

	d.set_builder(&k); // <<=== 국가선택을 변경하면 빌더를 변경하면됩니다.

	Character c = d.construct();
	std::cout << c << std::endl;

}
