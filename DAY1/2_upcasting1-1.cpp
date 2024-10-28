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
	Animal a;
	Dog    d;

//	Animal* p = &d;
	Animal* p = &a;
	
//	p->age = 10;   // ok
//	p->color = 10; // error

	// Animal* 인 p 를 가지고 Dog 고유 멤버에 접근하려면
	// Dog* 로 캐스팅해야 합니다.
	 
	// static_cast : 컴파일 시간 캐스팅.! 실행시 오버헤드 없음
	//				 컴파일 시간에는 p가 가리키는 곳을 조사할수 없음.
	//				 실행할때 변경될수 있으므로!!
	//				 그래서 아래코드는 무조건 성공
	Dog* dog = static_cast<Dog*>(p);

	std::cout << dog << std::endl;

}











