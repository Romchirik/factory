#pragma once
#include "unit.h"
class SiegeTank : public Unit {
public:
    void move(int x, int y) override;
};
Unit* createSiegeTank();