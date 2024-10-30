// Point.h
class Point
{
	int debug;  // <= 나중에 추가
				// 이헤더를 포함하는 모든 소스는 다시 컴파일 되어야 한다.
				// 1000개의 소스에서 #include 했다면
				// 모두 다시 컴파일!!
				// 화재(불)(변화가 생김) 발생했는데, 모든 곳으로 옮겨 붙었다.
				// 방화벽이 없다.
	int x, y;
public:
	void print();
};

// Point.cpp
#include "Point.h"

void Point::print() { } // 구현 생략






// main.cpp
#include "Point.h"
int main()
{
	Point p;
	p.print();
}


