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
	Dog* p1 = &d;		// ok..
	int* p2 = &d;		// error.

	// 핵심 1. 기반 클래스 포인터로 파생클래스 주소를 담을수 있다.
	Animal* p3 = &d;	// ok.. upcasting
	Animal& r = d;      // ok.


	// 핵심 2. 기반 클래스 포인터로는 기반 클래스 멤버만 접근할수 있다.
	// => 이유 : 멤버 접근시, 컴파일러는 항상 객체(포인터)의 타입만으로 
	//           접근 가능여부를 판단하므로
	//			 p3가 Animal* 이면 p3로는 Animal 멤버가 접근 가능.
	//			(성능과 안전성을 위해 컴파일 시간에 에러 확인하는 하기 때문
	//			 static type check 언어)
	p3->age = 10;   // ok
//	p3->color = 10; // error

	// 핵심 3. Animal* 인 p3로 파생 클래스 고유 멤버에 접근하려면
	//        => 캐스팅 하면 됩니다.
	static_cast<Dog*>(p3)->color = 10;
	// => 단, 이 경우 p3가 가리키는 곳이 Dog라는 확신이 있어야 합니다.
	// => 없다면, dynamic_cast로 조사는 가능


}












