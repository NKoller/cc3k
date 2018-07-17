#include "character.h"

Character::Character(const int hp, const int atk, const int def, const int gold, char name):
Stats{hp, atk, def, gold} , name{name} {}




void Character::notifyObservers() {
    for (auto &ob : observers) { ob->notify(*this);}
}

Stats getStats() {
    
}

void Character::setStats(Stats s){
    this->HP += s.HP;
    this->Atk += s.Atk;
    this->Def += s.Def;
    this->Gold += s.Gold;
}

Character::~Character() {}

