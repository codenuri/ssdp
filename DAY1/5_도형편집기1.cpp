#include <iostream>
#include <vector>

// 파워 포인트 값은 "도형을 편집"하는 프로그램을 만들어 봅시다.

// 핵심 #1. 모든 도형을 타입으로 설계 합니다.

class Rect
{
	// x, y, w, h 생성자등은 생략
public:
	void draw() { std::cout << "draw Rect\n"; }
};

int main()
{
	std::vector<Rect*> v;
}

