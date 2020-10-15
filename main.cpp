#include <iostream>
#include <memory>
#include "factory.h"
#include "zergling.h"
#include "battlecruiser.h"
#include "sigetank.h"

///
enum class Type {
  kZergling,
  kSiegeTank,
  kBattleCruiser,
};

Unit *makeUnit(const std::string& name){
    Unit* u = nullptr;
    if(std::string("zerling") == name){
        u = new Zergling();
    }
    else if(std::string("siegetank") == name){
        u = new SiegeTank();
    }
    else if(std::string("battlecruser") == name){
        u = new BattleCruiser();
    }
    return u;
}

int main(int argc, char* argv[]) {
    argc = 3;
    argv[1] = "zergling";
    if(argc < 2) return -1;


    //f.addCreator ("siegetank", createSiegeTank);
    //f.addCreator ("battlecruiser", createBattleCruiser);

    std::unique_ptr<Unit> u(Factory<Unit, std::string, Unit*(*)()>::getInstance()->makeUnit(argv[1]));
    u->move(100, 500); //динамическое связывание
}
//динамический и статический полиморфизм?
//виртуальные деструкторы!!!

