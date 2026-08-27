#include <iostream>

// factory4.cpp 에서는 "클래스 생성자" 를 만들기위해
// Rect, Circle 안에 "AutoRegister 타입의 static 데이타" 사용
// => 따라서 모두 "공장등록" 이라는 동일 작업 수행

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

}