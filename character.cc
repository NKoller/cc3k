#include "character.h"
#include "stats.h"
using namespace std;

Character::Character(char name): name{name} {}

void Character::notifyObservers() {
    for (auto &ob : observers) { ob->notify(*this);}
}

Stats Character::getStats() {
 return {HP, Atk, Def, Gold};
}

void Character::setStats(Stats s) {
    this->HP = s.HP;
    this->Atk = s.Atk;
    this->Def = s.Def;
    this->Gold = s.Gold;
}

bool Character::move() {
 return (!(name == "D"));
}

//helper
void change(int &type, const int amt) { 
 type += amt;
 if(type < 0) {
   type = 0;
 }
}

//helper
int calcDamage(Character &defender,Character &attacker) {
 float damage1 = ((100/(100+defender.Def))*Attacker.Atk);
 int damage2 = ((100/(100+defender.Def))*Attacker.Atk);
 if(damage1 > damange 2) {
  return damage +1;
 }
 return damage 2;
}


void defend(Character &attacker) {
 attacker.attack(*this);
}

Character::~Character() {}

