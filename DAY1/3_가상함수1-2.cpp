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
	Animal a;
	Dog d;
	Animal* p = &d;

	p->f2();	// 가상함수 이므로 
				// 실행시간에 p의 대상체 조사후
				// 어느 함수를 호출 할지 결정
				// 1. 어떻게 조사할까 ?
				// 2. 대상체 타입을 알았다고 해서 f2 를 어떻게 호출할수 있을까 ?
}














