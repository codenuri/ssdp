#include <string>
#include <string_view> // C++17

// 함수 인자로 문자열을 받고 있습니다.(읽기만 하기 위해서)
// => 최선의 코드를 찾아 봅시다.

// void f1(std::string s) {} // worst!!! 절대 사용금지

void f2(const std::string& s) {} // good 하지만 best 는 아님.!


void f3(std::string_view  sv) {}


int main()
{
	std::string s = "abcd";
	
	// 아래 코드는 큰 차이가 없습니다
	f2(s);
	f3(s);

	// 아래 코드가 핵심 입니다
	// => 인자로 literal 을 직접 보내는 경우.
	f2("hello");
	f3("hello");
}

// C++17 이후 함수가 읽기 전용 문자열을 받을때는
// const std::string& 보다는 std::string_view 가 좋습니다

// RUST       C++
// str    : std::string_view
// String : std::string
