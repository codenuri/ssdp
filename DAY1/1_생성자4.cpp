// protected 생성자 의도
// => 자신은 만들수 없지만(추상적 존재, 개념)
// => 파생 클래스는 만들수 있도록(구체적 존재, 개념)

// => 동물 객체는 현실세계에는 존재 하지 않습니다. (추상적인 개념)
// => 하지만, "강아지" 는 현실 세계에 존재(구체적 개념)
// => "Animal 생성자를 protected 에 놓는 것은 좋은 코드!!"

class Animal
{
// public:			// 1, 2 모두 에러 아님. 
// private:			// 1, 2 모두 에러!
protected:
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
	Animal a;	// 1 error
	Dog    d;	// 2 ok
}



