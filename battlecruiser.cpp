#include "battlecruiser.h"
#include "factory.h"
#include <iostream>
namespace {
    Unit* createBattleCruiser(){
        return new BattleCruiser;
    }
    bool g(){
        Factory<Unit, std::string, Unit*(*)()>::getInstance()->addCreator("battlecruiser", createBattleCruiser);
        return true;
    }
    static bool b = g();
}
void BattleCruiser::move(int x, int y){
    std::cout << "BattleCruiser move" << std::endl;
}
