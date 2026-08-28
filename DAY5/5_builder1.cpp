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

int main()
{
    // 비싼차
    Car c1;
    c1.engine = "best engine";
    c1.tire   = "best tire";
    c1.interior = "best interior";

    // 중형차
    Car c2;
    c2.engine = "good engine";
    c2.tire = "good tire";
    c2.interior = "good interior";

}