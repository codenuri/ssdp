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

	// 핵심 #2. 컴파일러는 p3가 실제 어떤 객체를 가리키는지는 알수 없다.
	// => 실행시 변경될수 있으므로(아래 코드 같이)
	// => 컴파일러가 아는 것은 "p3" 자체의 타입 (Animal*) 만 알수있다
//	if (사용자 입력 == 1) p3 = &animal;

}











