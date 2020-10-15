#pragma once
#include "unit.h"
class BattleCruiser : public Unit {
public:
    void move(int x, int y) override;
};
Unit* createBattleCruiser();
