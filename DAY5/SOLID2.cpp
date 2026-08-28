#include <iostream>

// LSP 위반 예제
class Rectangle 
{
protected:
    int width, height;
public:
    // 핵심 : 너비, 높이는 "각각 변경" 됩니다.
    virtual void setWidth(int w)  { width = w; }
    virtual void setHeight(int h) { height = h; }

    int getWidth() const  { return width; }
    int getHeight() const { return height; }

    int area() const { return width * height; }
};

// 정사각형도 "사각형"의 종류이다.
class Square : public Rectangle 
{
public:
    // 핵심 : 너비 높이가 같이 변경됨..
    // => 부모가 가졌던 의미를 변경했음. 
    // => 이 코드가 LSP 위반
    // => 해결책 : Square 를 Rectangle 에서 상속받으면 안됩니다.
    // 복습 할때 구글, AI 등으로 "LPS 위반 사례" 를 더 찾아 보세요..
    void setWidth(int w) override 
	{
        width = height = w;  
    }

    void setHeight(int h) override {
        width = height = h;
    }
};

// process 의 요구사항은 Rectangle 입니다.
// => LSP 에 따르면 파생 클래스인 Square 를 보낼수 있어야 합니다.
void process(Rectangle& r)
{
    r.setWidth(5);
    r.setHeight(10);

    std::cout << "Expected area = 50, actual area = " << r.area() << std::endl;
    // => 결과는 50을 예상합니다.
    // => 하지만 Square 전달시 결과는 100 입니다.
    // => LSP 을 위반한 사례 입니다.
}

int main()
{
    Rectangle rect;
    Square sq;

    process(rect); 
    process(sq);   
}