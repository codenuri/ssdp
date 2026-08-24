#include <iostream>

// 가상함수의 호출의 정확한 원리

// #1. 컴파일러가 Animal 의 모든 가상함수의 주소를 담은 배열을 생성합니다.
void* animal_vtable[] = { Animal_타입정보, &Animal::f1,
										  &Animal::f2,
										  &Animal::f3 };


// #2. 클래스 멤버로 자신의 가상함수 테이블 주소를 보관할 멤버 변수 생성
class Animal
{
	void* vtptr = animal_vtable; // <= 컴파일러가 추가
	int age;
public:
	virtual void f1() {}
	virtual void f2() {}
	virtual void f3() {}
	void f4() {}
};
//-------------------------------------------------
// Dog 용 가상함수 테이블(가상함수의 주소를 담은 배열)도 생성
// => Animal 에 가상함수가 100개 있는데, Dog 가 한개만 override 해도
// => Dog 용 테이블은 100개 항목(타입정보까지 101개) 이 필요 합니다
void* dog_vtable[] = { Dog_타입정보, &Animal::f1,
									&Dog::f2,
									&Animal::f3 };

class Dog : public Animal
{
	void* vtptr = dog_vtable;	// <= 컴파일러가 추가
	int color;
public:
	virtual void f2() {}
};
//------------------------------------------
int main()
{
	Animal a1, a2;
	Dog d;
	Animal* p = &d;

	p->f2(); 	

	// 컴파일 할때
	// => p 는 Animal* 타입이므로
	//    Animal 클래스 선언을 보고 f2가 virtual 인지 조사

	// 1. virtual 이 아니면 static binding
	//    "call Animal::f2" 기계어 코드 생성하고 컴파일 종료

	// 2. virtual 이면 아래 의미의 기계어 코드 생성
	//	  "p->vtptr[2]()" 라는 의미의 기계어 생성 
}














