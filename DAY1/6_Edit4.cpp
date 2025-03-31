// edit 정리

// #1. edit2.cpp
// => 변하는 것을 가상함수로
// => template method 패턴
// => 파생 클래스를 만들어서 약속된 가상함수를 override

// 특징 
// => NumEdit 는 Edit 의 기능과 Validation 의 기능을 모두 소유 한다.
// => Validation 정책을 NumEdit 가 독점. 다른 입력도구에서는 사용할수 없다.
// => Validation 정책은 실행시간에 교체 불가능하다.
// => Validation 함수가 멤버 함수이다. 멤버데이타 접근 가능.


// #2. edit3.cpp
// => 변하는 것을 다른 클래스로
// => strategy pattern

// 특징
// => Edit 와 Validation 정책이 다른 클래스로 분리 되어 있다
// => 다른 입력도구에서도 Validation 정책 사용가능
// => Validation 정책은 실행시간에 교체 가능하다.
// => Validation 함수가 Edit 멤버 함수는 아니다.
//    Validation 이 필요한 데이타를 인자로 전달 받아야 한다.


// Edit 예제는
// => template method 보다는 strategy(edit3.cpp)가 더 좋은 디자인 입니다.

// 그런데,
// 도형편집기에서 "draw/draw_imp" 는
// => 사각형을 그리는 방법은 "Rect" 클래스만 사용하면 되고(다른 클래스에서는
//										필요 없다.)
// => 사각형을 그리는 방법은 실행시간에 변해야 할 필요 없다.
// => 사각형을 그리려면 "멤버 데이타" 접근이 필요 하다.

// strategy 패턴 보다는 template method 가 좋다.
