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

    virtual ~CarBuilder() {}
};

// 다양한 자동차를 만드는 클래스들
class SportCarBuilder : public CarBuilder
{
    Car c;
public:
    virtual void make_engine() { c.engine = "Sport Car Engine"; }
    virtual void make_tire() { c.tire = "Sport Car Tire"; }
    virtual void make_interior() { c.interior = "Sport Car interior"; }
    virtual Car  get_car()
    {
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
        make_engine();
        make_tire();
        make_interior();
        return c;
    }
};

// 모든 자동차는 만드는 공정이 동일합니다.
// 만드는 공정만 책임지는 클래스를 별도로 구현
// 디자인 패턴에서는 "Director" 라고 합니다.
// => 자동차를 만드는 방법은 여기에서 구현합니다.
class Director
{
public:
    void construct(CarBuilder& builder)
    {
        builder.make_engine();
        builder.make_tire();
        builder.make_interior();
    }
};



int main()
{
    SportCarBuilder b1;
    EcoCarBuilder b2;
    Car c1 = b1.get_car();
    Car c2 = b2.get_car();

    c1.show();
    c2.show();
}