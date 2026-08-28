#include <iostream>
#include <string>

class Car
{
public:
    std::string engine;
    std::string tire;
    std::string interior;

    void show() const
    {
        std::cout << engine << '\n'
            << tire << '\n'
            << interior << '\n';
    }
};

// 자동차 만들때 필요한 작업을 약속한 인터페이스
struct CarBuilder
{
    virtual void make_engine() = 0;
    virtual void make_tire() = 0;
    virtual void make_interior() = 0;
    virtual Car  get_car() = 0;

    virtual ~CarBuilder() { }
};

// 다양한 자동차를 만드는 클래스들
class SportCarBuilder : public CarBuilder
{
    Car c;
public:
    virtual void make_engine() { c.engine = "Sport Car Engine"; }
    virtual void make_tire()   { c.tire = "Sport Car Tire"; }
    virtual void make_interior() { c.interior = "Sport Car interior"; }
    virtual Car  get_car()
    {
        // 자동차를 만드는 공정대로 생산해서 반환
        make_engine();
        make_tire();
        make_interior();
        return c;
    }
};

class EcoCarBuilder : public CarBuilder
{
    Car c;
public:
    virtual void make_engine() { c.engine = "Eco Car Engine"; }
    virtual void make_tire() { c.tire = "Eco Car Tire"; }
    virtual void make_interior() { c.interior = "Eco Car interior"; }
    virtual Car  get_car()
    {
        // 자동차를 만드는 공정대로 생산해서 반환
        make_engine();
        make_tire();
        make_interior();
        return c;
    }
};

int main()
{
    // 이제 다양한 빌더로 자동차를 생산합니다
    SportCarBuilder b1;
    EcoCarBuilder b2;
    Car c1 = b1.get_car();
    Car c2 = b2.get_car();
  
    c1.show();
    c2.show();
}