class Animal
{
public:
	int age;
};

class Dog : public Animal
{
public:
	int color;
};

int main()
{
	Dog d;
	Dog* p1 = &d;		// ok

//	int* p2 = &d;		// error
	
	// 핵심 #1. 기반 클래스타입의 포인터로 파생 클래스 객체를 가리킬수 있다.
	// => upcasting 이라고 합니다.
	// => 가능한 이유는 메모리그림을 생각해 보세요
	Animal* p3 = &d;	// ok.

}











