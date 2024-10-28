// 7 page

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
	Dog* p1 = &d;	// ok

	int* p2 = &d;	// error
	
	// 핵심 #1. 기반 클래스 포인터에 파생 클래스 주소를 담을수 있다
	// => upcasting 이라고 합니다.
	// => 가능한 이유는 메모리 그림을 생각하면 됩니다.
	Animal* p3 = &d;  // ok. 

	// 핵심 #2. 컴파일러는 p3 가 가리키는 곳에 실제 어떤 객체가 있는지
	//         알수 없다.
	// => 아래 주석 참고
	// => p3 가 가리키는 곳은 실행시간에 변경될수 있다.
	// => 따라서 컴파일러는 p3가 가리키는 곳에 어떤 객체가 있는지 알수없다
	// 	if (사용자 입력 == 1) p3 = &animal;


	// 핵심 #3. Animal* 인 p3로는 Animal 멤버만 접근 가능하고
	//			Dog 고유 멤버는 접근이 안됩니다.
	// => 이유는 "핵심 #2"
	p3->age = 10;	// ok
	p3->color = 10;	// error


	// 핵심 #4. p3로 Dog 고유 멤버에 접근 하려면
	// => 캐스팅 해야 합니다.
	static_cast<Dog*>(p3)->color = 10;
}











