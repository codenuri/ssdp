#include <iostream>


class Animal
{
	int age;
public:
	virtual void f1() {}
	virtual void f2() {}
	virtual void f3() {}
	void f4() {}
};

class Dog : public Animal
{
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


}

// 1-3 의 코드를 godbolt.org 에 넣으세요


// 결론
// 가상함수
// 장점 : 실행시간 다형성(실제 객체에 맞게 호출) 
//		 => 다형성이란 의미는 오늘 오후 내내 배우게 됩니다.

// 단점
// 1. 가상함수 테이블이 "클래스당 한개" 씩 생성
//    => 가상함수가 1000개 있고, 64bit 환경 이면 클래스당 "8K"
//	  => 상속시 파생클래드도 동일 크기 사용 

// 2. "객체당 한개씩" vtptr 생성

// 3. 함수 호출시, 직접 호출이 아닌
//   => 몇번(보통 2~3회)의 메모리를 참조해서 호출
//   => 약간의 지연
//   => 루프 안에서 호출시는 고려 대상
//   => 단, 루프밖에서 단순한 호출이면 고려할 필요 없음

//------------------------------
// 참고
// g++ 사용시
// C++ 코드 ---------> g++내부의 중간언어 생성후 다시 컴파일 ------------> 기계어 생성

// clang++ 
// C++ 코드 -----> LLVM IR 이라는 언어로 변경 ---------> LLVM 컴파일러가 기계어로 생성
// swift    -----> LLVM IR 언어
// Rust     -----> LLVM IR
// 그외에 Python 등 많은 언어도
// LLVM 으로 변경하는 컴파일러있음

// front end compiler : C++ -> IR 로 변경
// back end compiler  : IR -> 기계어로 변경













