#include <iostream>
#include <vector>
// factory4.cpp 에서는 "클래스 생성자" 를 만들기위해
// Rect, Circle 안에 "AutoRegister 타입의 static 데이타" 사용
// => 따라서 모두 "공장등록" 이라는 동일 작업 수행

// 2016 년 C++ 표준 위원회에 "클래스 생성자 문법" 도입하자는 제안 나옴
/*
class Car
{
	static Car() {}
};
*/
// 하지만 아래 기술로 가능하므로, 잠정 보류 되었습니다.
class Car
{
	struct Initializer
	{
		Initializer()
		{
			std::cout << "Car 의 클래스 생성자\n";
		}
	};

	inline static Initializer static_ctor;
};

int main()
{
	// C++26 부터 클래스 자체를 컨테이너에 보관하는 기술이 도입됩니다.
	// => C++26 Reflection 이라는 문법
	// => C++ 창시자가 말하길 "C++26 Reflection" 은 C++ 을 전혀 다른 언어로
	//	  만들게 될것이다

	std::vector<meta::info> v = { ^^Rect, ^^Circle, ^^Triangle };
}