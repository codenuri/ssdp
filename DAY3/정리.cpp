// 객체지향 디자인 패턴의 핵심원리 #1. 공통성과 가변성의 분리
// => 변하지 않은 코드에서 변하는 것을 분리하는 것

// 변하는 것을 분리하는 2가지 기술
// 1. 변하는 것을 가상함수로 분리
//    => template method 패턴
//    => 도형편집기 예제  draw()/draw_imp() 
//    => 변하는 것을 소유!
// 
// 2. 변하는 것을 다른 클래스로 분리
//    => 변하는 것을 완전히 다른 클래스로 분리하므로서
//       다양한 클래스에서 "정책(알고리즘)"을 사용가능

//    정책 클래스를 어떻게 교체 할것인가 ?
//    => 인터페이스를 만들어서 교체 : strategy 패턴
//									Edit/Validator 예제
//									
//    => template 인자로 교체      : policy base design
//									vector<int, debug_alloc<int>>


//				strategy				policy base design
// 성능			가상함수기반(느리다)		인라인 치환도 가능(빠르다)
// 
// 유연성		실행시간교체가능			vector<int, debug_alloc<int>> v
//				e.set_validator(&v1);	객체 생성시만 교체 가능
//				e.set_validator(&v2);	실행시 교체는 안됨
//				유연성 좋음.				유연성 부족. 

// 디자인 패턴 : 대부분의 객체지향 언어에서 공통적으로 사용가능한 디자인기술
//				template method, strategy 등 23개의 대표적 기술
//					
// IDioms : 각 언어에 특징을 고려한 디자인 기술
//			(C++ IDioms, Java IDioms, C# IDioms 등)
//			Policy Base Design
// 

// Policy Base Design
// => C#, Java, python 등에서는 거의 사용안함, strategy 로 대부분 설계
// => RUST : 아주 널리 사용, C++ 개념이 거의 유사, 성능 향상
// => 이외 Haskell, TypeScript, D 등의 언어에서 볼수있습니다. 
// => C++에서는 STL 에서 아주 널리 사용됩니다.

//==========================================================
// 객체지향 디자인의 핵심 개념 #2
// => 재귀적인 포함을 위해 공통의 기반 클래스를 설계하는 경우가 많습니다.

// Folder 는 File 을 보관하지만 Folder 자신 도 보관가능하다.
// => File 과 Folder 는 공통의 기반 클래스 필요

// 객체에 포장(기능추가)을 할수 있는데 포장된 객체를 다시 포장(기능추가)할수있다.
// => 객체와 포장지는  공통의 기반 클래스가 필요 하다.

// 왜 ?? 어떤 이유로 공통의 기반 클래스를 사용한 재귀적 포함을 사용하는가 ??

// Composite : 재귀적 포함으로 복합객체를 만들기 위해
// Decorator : 재귀적 포함으로 객체의 중첩해서 기능을 추가

//==============================================
// 객체지향 디자인의 핵심 개념 #3.
// 다양한 문제를 해결하기 위해서 간접층(중간층)을 만들어서 해결

// 왜 ?? 어떤 문제를 해결하기 위해서 간접층을 도입했느냐에 따라 패턴의 종류가다름.

// 사용자 ============= stack =================> list
//								// 인터페이스(함수이름)을 변경하기 위한 중간층
//								// adapter 패턴

// 사용자 ============= MP3 ===================> IMP3 인터페이스 사용
//								// 구현계층 과 추상계층의 독립적 update
//								// bridge 패턴

// 사용자 ============= TCPServer =============> Socket, IPAddress, NetworkInit
//								// 복잡한 절차를 단순화 하기 위해
//								// facade 패턴

// 사용자 ============= Calc ==================> CalcServer
//								// 다양한 의도를 가지는 "대신" 사용하는용도
//								// proxy 패턴

// 사용자 ============= ZipDecorator ===========> FileStream
//								// 기능을 추가를 위한 중간층
//								// decorator 패턴
