#include "unit.h"
#include <iostream>

struct A{
    A(){std::cout << "Ctor" << std::endl;}
    ~A(){std::cout << "Dtor" << std::endl;}
};
class Zergling : public Unit {
public:
    void move (int x, int y) override;
    ~Zergling() override{ delete a;}
private:
    A* a = new A;
};

Unit *createZergling ();