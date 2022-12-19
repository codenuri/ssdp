// protected 생성자의 의도 : 자신은 객체를 만들수 없지만(추상적인 존재)
//						파생 클래스의 객체는 만들수 있도록(구체적인 존재)
//						하겠다는 의도를 가진 코드

// 구체(concrete) : 디자인 패턴에서 추상(abstract)의 반대말로 사용됩니다.

class Animal
{
//public:
//private:
protected:
	Animal() {}
};
class Dog : public Animal
{
public:
	Dog() {}
};
int main()
{
	// 다음중 에러를 모두 골라 보세요
	Animal a;	// error
	Dog    d;	// ok
}



