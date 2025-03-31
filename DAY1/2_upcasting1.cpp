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


	// 핵심 #3. p3 를 사용해서는 Animal 로 부터 상속받는 멤버만 접근
	// 가능. Dog 가 추가한 멤버는 접근 안됨
	// 이유는 "컴파일 시간에 타입을 체크" 하기 때문에
	// => 컴파일 시간에는 p3가 "Animal*" 라는 것만 알수있으므로!

	// C++, Java, C#, Rust : static type check(컴파일 시간 타입확인)
	// Python : dynamic type check(실행시간에 타입 확인)

	p3->age = 10; // ok
	p3->color = 10; // error


	// #4. p3를 사용해서 Dog 고유의 멤버에 접근하려면
	//     캐스팅 해야 합니다.(컴파일러에게 Dog 라고 알리는 작업)
	static_cast<Dog*>(p3)->color = 10;

	// ((Dog*)p3)->color = 10; 의 의미

	// 단, 이경우 p3가 가리키는 곳이 Dog라는 확신이 있어야 합니다
	// Dog 가 아닌 경우 "미정의 동작" 발생


	// #5. p3가 가리키는 곳이 Dog 인지 조사하려면
	// => dynamic_cast 를 사용하면 됩니다.
	// => 다음예제에서
}











