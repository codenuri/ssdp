// protected 생성자의 의미(의도)
// => 자신은 객체를 만들수 없지만(추상적 의미의 타입)
//    파생 클래스는 객체를 만들수 있게(구체적, concrete 타입) 하겠다는 의도

class Animal
{
//public:			// A, B 모두 에러 아님
//private:			// A, B 모두 에러
protected:			// A 는 에러, B는 에러 아님
	Animal() {}
};
class Dog : public Animal
{
public:
	Dog() {} // call Animal::Animal()
};
int main()
{
	// 다음중 에러를 모두 골라 보세요
//	Animal a;	// A. error
	Dog    d;	// B. ok 
}



