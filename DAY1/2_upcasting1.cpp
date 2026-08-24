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

	// 핵심 #1. 기반클래스 포인터로 파생 클래스 주소를 담을수 있다
	// => upcasting 이라고 합니다.
	// => 가능한 이유는 "메모리 그림" 을 생각해 보세요
	Animal* p3 = &d; 

	// 핵심 #2. 컴파일러는 컴파일 시간에는 p3 가 가리키는 곳에 어떤 객체가 있는지
	//			알수 없다
	// => 아래 코드를 생각해 보세요
	// => 실행시 입력 값에 따라 p3의 대상체가 변경될수 있습니다.
	// => 따라서, 컴파일 시간에는 p3의 대상체의 타입을 알수가 없습니다.
	// => 컴파일 시간에 알수 있는 것은 p3 자체의 타입(Animal*) 만 알수 있다
//	std::cin >> n;
//	if (n == 1) p3 = new Animal;

	// 핵심 #3. Animal* 인 p3를 가지고는 Animal 의 멤버만 접근 가능하다

	p3->age   = 10; // ok
	p3->color = 10; // error

}











