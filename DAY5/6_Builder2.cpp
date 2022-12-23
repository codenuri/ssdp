// 2_Builder
#include <iostream>
#include <string>

// 축구게임 캐릭터를 생각해 봅시다.
// 모자, 유니폼, 신발등을 변경할수 있습니다.
typedef std::string Hat;			// class Hat{}
typedef std::string Uniform;	    // class Uniform{}
typedef std::string Shoes;			// class Shoes{}
typedef std::string Character;		// class Character{}라고 가정

// 축구 게임에서 어떤 나라를 선택해도, 캐릭터라는 복잡한 객체를 만드는
// "공정은 동일"합니다. 하지만 각 "공정"의 결과는 다릅니다.

struct IBuilder
{
	virtual void makeHat() = 0;
	virtual void makeUniform() = 0;
	virtual void makeShoes() = 0;
	virtual Character getResult() = 0;

	virtual ~IBuilder() {}
};

// 캐릭터를 만드는 클래스
class Director
{
	IBuilder* builder = nullptr;
public:
	void setBuilder(IBuilder* p) { builder = p; }

	Character construct()
	{		
		// 캐릭터를 만드는 공정은 "동일" 합니다.
		builder->makeHat();
		builder->makeUniform();
		builder->makeShoes();

		return builder->getResult();
	}
};

// 국가별 캐릭터 빌더
class Korean : public IBuilder
{
	Character c;
public:
	virtual void makeHat() override     { c += Hat("갓\n"); }
	virtual void makeUniform() override { c += Uniform("한복\n"); }
	virtual void makeShoes() override   { c += Hat("짚신\n"); }
	virtual Character getResult() override { return c; }
};

class American : public IBuilder
{
	Character c;
public:
	virtual void makeHat() override { c += Hat("야구모자\n"); }
	virtual void makeUniform() override { c += Uniform("양복\n"); }
	virtual void makeShoes() override { c += Hat("구두\n"); }
	virtual Character getResult() override { return c; }
};

int main()
{
	American a;
	Korean k;

	Director d;
//	d.setBuilder(&k);  // <== 국가 선택 변경시, 빌더를 변경!!!
	d.setBuilder(&a);

	Character c = d.construct();
	std::cout << c << std::endl;

}