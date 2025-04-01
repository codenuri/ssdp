#include <iostream>
#include <functional>
using namespace std::placeholders;

void f1(int a) { printf("f1, %d\n", a); }
void f2(int a, int b) { printf("f2, %d, %d\n", a, b); }
void f4(int a, int b, int c, int d) 
{
	printf("f4, %d, %d, %d, %d\n", a, b, c, d);
}

class Dialog 
{
public:
	void close(int a, int b) {printf("Dialog::close, %d, %d\n", a, b)}
};

int main()
{
	// C 함수 포인터 : 
	void(*f)(int);
	f = &f1; // ok
	f = &f2; // error 
}
