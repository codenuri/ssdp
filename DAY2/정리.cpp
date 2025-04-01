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
// 구글에서 "C++ IDIoms" 검색후 1번째 링크,