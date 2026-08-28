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
// => 각 빌더는 부품만 만들수 있고, 자동차 전체를 만드는 공정을 없습니다.
class SportCarBuilder : public CarBuilder
{
    Car c;
public:
    virtual void make_engine() { c.engine = "Sport Car Engine"; }
    virtual void make_tire() { c.tire = "Sport Car Tire"; }
    virtual void make_interior() { c.interior = "Sport Car interior"; }
    virtual Car  get_car()
    {
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

    Director d;
    d.construct(b1); // b1 으로 자동차 만들어 달라
    d.construct(b2); // b2 으로 자동차 만들어 달라

    Car c1 = b1.get_car();
    Car c2 = b2.get_car();

    c1.show();
    c2.show();
}

// 복잡한 객체를 만드는데.
// => 각 부품을 만드는 클래스와
// => 부품을 가지고 전체 공정을 가진 클래스를 분리한것
// => "동일한 공정으로 만드는데, 사용하는 부품이 다른 객체" 만들때 사용

// 주의 
// GoF's 패턴의 빌더 : 위 내용
// Java 에서 이야기하는 빌더 : 아래 처럼 메소드 체이닝으로 객체를 만드는 것을 표현
/*
People p;
p.set_name("Kim")
    .set_age(20)
    .set_height(180);
    */






