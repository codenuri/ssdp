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
public:
	Character construct()
	{
		Character c;
		c = c + Hat("야구모자");
		c = c + Uniform("파란색티셔츠");
		c = c + Shoes("운동화");
		return c;
	}
};



int main()
{
	Director d;
	Character c = d.construct();
	std::cout << c << std::endl;

}
