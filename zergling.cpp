#include "zergling.h"
#include "factory.h"
#include <iostream>

namespace {


    Unit* createZergling(){
        return new Zergling;
    }
    bool g(){
        Factory<Unit, std::string, Unit*(*)()>::getInstance()->addCreator("zergling", createZergling);
        return true;
    }

    static bool b = g();
}

void Zergling::move(int x, int y){
    std::cout << "Zergling move" << std::endl;
}
