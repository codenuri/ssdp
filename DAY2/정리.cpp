// 객체지향 디자인 패턴의 핵심원리 #1. 공통성과 가변성의 분리
// => 변하지 않은 코드에서 변하는 것을 분리하는 것

// 변하는 것을 분리하는 2가지 기술
// 1. 변하는 것을 가상함수로 분리
//	  => template method 패턴
//	  => 파생 클래스를 만들어서 약속된 가상함수 override
//    => 상속 기반의 패턴
// 
// 2. 변하는 것을 다른 클래스로 분리 (강의에서는 "정책 클래스" 라는 용어 사용)
//	  => 정책 클래스를 어떻게 교체 시킬 것인가 ?

//    strategy 패턴      : 인터페이스를 사용해서 정책 클래스를 교체(Edit 예제)
//    Policy Base Design : template 인자로 정책 클래스를 교체(vector 예제)

//							성능						유연성
// strategy					가상함수기반				실행시간 교체
//							약간의 오버헤드			e.set_validator(&v)
// 
// Policy Base Design		가상함수 아님				실행시간 교체 안됨
//							인라인 치환도 가능		vector<int, debug_alloc> v
//							빠르다					v 에 할당기 교체 못함

// 디자인 패턴 : C++ 뿐 아니라 대부분의 객체지향 언어로 구현 가능한 디자인 기술
//				23개가 있습니다.
//				template method, strategy, prototype.... 배웠습니다

// IDioms : 각 언어의 특징을 고려한 디자인 기술
//			C++ IDioms, C# IDioms, Java IDioms
//			Policy Base Design 은 C++ IDioms 로 분류!!
//			구글 "C++ IDioms 검색"


