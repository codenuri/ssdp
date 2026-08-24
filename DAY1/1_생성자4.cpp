// 생성자를 protected 에 만드는 이유
// => 자신의 객체는 만들수 없지만(추상적인 개념을 클래스로 설계 한것)
// => 파생 클래스의 객체는 만들수 있게 하겠다(구체적인 개념을 설계 한것)

// 디자인 패턴에서 추상(abstract) 의 반대말은 "구체(concrete)"

class Animal
{
//public:			// main 의 a, d 모두 에러 아님
//private:			// main 의 a, d 모두 에러 

protected:			// a 생성은 error,  d 는 에러 아님.
	Animal() {}
};
class Dog : public Animal
{
public:
	Dog() {}	// Dog() : Animal() {}
};
int main()
{
	// 다음중 에러를 모두 골라 보세요
	Animal a;	// error
	Dog    d;	// ok
}



