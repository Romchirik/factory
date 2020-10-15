#include "sigetank.h"
#include <iostream>
#include "factory.h"
namespace {
    Unit* createSiegeTank(){
        return new SiegeTank;
    }

    bool g(){
        Factory<Unit, std::string, Unit*(*)()>::getInstance()->addCreator("siegetank", createSiegeTank);
        return true;
    }

    static bool b = g();
}
void SiegeTank::move(int x, int y){
    std::cout << "SiegeTank move" << std::endl;
}