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

    c1.show();
    c2.show();

    // 자동차를 만드는 공정은 매우 복잡합니다.
    // => 모든 종류의 자동차 자체를 만드는 공정은 유사합니다 - 변하지 않는것
    // => 하지만 자동차 종류에 따라서 각 부품은 변경됩니다 - 변하는 것

    // 이처럼
    // => 동일한 공정을 사용하는데
    // => 각 단계의 결과가 다른 것을 만들때 사용하는 패턴이 "빌더"
}