// 디자인 패턴의 핵심 #1. 변하지 않은 코드에서 변하는 것을 분리하는 것!!!

// 방법 #1. 변하는 것을 가상함수로 분리
// => 파생 클래스를 만들어서 가상함수 override 를 통한 변경
// => template method 패턴

// => NumEdit 가 "Edit 기능 및 Validation 기능 모두 포함"

// => 다른 입력도구에서 Validation 기능을 사용할수 없다.

// NumEdit e; // e 가진 정책은 실행할때 변경할수 없다.
// AddressEdit e2; // e의 정책이 변경된것이 아니라
				   // 다른 정책을 가진 새로운 edit



// 방법 #2. 변하는 것을 다른 클래스로 분리
// => validation 정책을 다른 클래스로
// => 인터페이스를 먼저 설계하고 validation 클래스 작성
// => "strategy" 패턴

// => Edit 와 Validation 정책이 분리됨.
// => 다른 입력도구에서도 Validation 정책 사용가능
// => Validation 정책을 실행시간 교체도 가능

// LimitDigitValidator v1(5);
// e.set_validator(&v1);

// LimitDigitValidator v2(10);
// e.set_validator(&v2);


// 결론 : Edit 예제는 template method 보다 strategy 가 좋습니다.

// 그런데, 도형 편집기의 draw/draw_imp 관계는

// Rect를 어떻게 그릴지는 
// => 실행할때 변경될 필요 없습니다.
// => 다른 클래스에서 사용할 필요 없습니다.

// => Rect가 그리는 방법을 소유(멤버함수)하는 것이 좋습니다.
// => 멤버 함수는 "private 멤버 데이타 접근"을 할수 있습니다.

// 그래서 "도형편집기"는  "strategy" 보다는 "template method"가 좋습니다.