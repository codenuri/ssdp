// 7_싱글톤1 - 123 page
#include <iostream>

// 싱글톤 : 오직 한개의 객체만 존재하는 것.
//		   그리고, 어디에서도 동일한 방법으로 객체에 접근 할수 있다

// 결국 "전역변수" 특징과 동일
// => 그런데, 전역변수는 나쁘다고 합니다
// => 그래서, 싱글톤도 비판이 많은 패턴.


// 아래 코드가 C++ 에서 "가장 좋다고 알려진 모델"
// => effective-C++ 책의 저자인 scott mayer 가 처음 제안한 코드
// => "mayer's singleton" 이라고 합니다
// => 특징 : 오직 한개의 객체가 static 지역변수로 구현

// 가장 신기하고 복잡하고 어려운 책 - "modern c++ design" "안드레이 알렉산드레스큐"
//									=> policy base design 을 처음 소개한책

class Cursor
{
	// 규칙 #1. 생성자를 private 에
private:
	Cursor() {}

	// 규칙 #2. 복사 생성자와 대입연산자를 컴파일러가 만들지 않도록
	Cursor(const Cursor&) = delete;
	Cursor operator=(const Cursor&) = delete;


	// 규칙 #3. 오직 한개의 객체를 만들어서 반환하는 static 멤버 함수
public:
	static Cursor& get_instance()
	{
		static Cursor instance;
		return instance;
	}
};
int main()
{
	Cursor& c1 = Cursor::get_instance();
	Cursor& c2 = Cursor::get_instance();

//	Cursor c3 = c1; // 일반 생성자가 아닌 복사 생성자
					// 사용자가 만들지 않으면 컴파일러 제공
}








