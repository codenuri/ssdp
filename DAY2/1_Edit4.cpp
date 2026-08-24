// Edit2.cpp
// => 변하는 것을 가상함수로, 상속을 통해서 변경
// => template method 패턴

// 특징 #1. NumEdit 가 "Edit 기능 + Validation 정책" 을 모두 포함
//       => 다른 입력도구(PasswordEdit등)에서 Validation 정책 재사용 안됨


// 특징 #2. 실행시간 교체 안됨
//		=> NumEdit 는 "edit 기능에 validation 기능도 고정된 상태"

// 특징 #3. 변하는 것을 가상함수로 했는데, 결국 멤버 함수 이므로
//		=> private 멤버 데이타 접근하기 쉽다.


// Edit3.cpp
// => 변하는 것을 다른 클래스로 
// => strategy(전략) 패턴

// 특징 #1. Edit 기능과 Validation 기능을 완전히 분리
//		    => LimitDigitValidator 는 Validation 기능만 있다
//			=> 다른 입력도구에서도 Validation 기능 사용가능

// 특징 #2. 실행시간 교체 가능

// 특징 #3. 변하는 것을 다른 클래스로
//		=> private 멤버 데이타 접근하기 어렵다

// 결론
// "도형편집기" 에서 각 도형을 그리는 방법(draw/draw_imp)
// => template method 가 좋은 디자인

// "Edit" 예제에서 Validation 정책의 교체
// => strategy 가 더 좋은 디자인


