#include "character.h"
#include "stats.h"
using namespace std;

Character::Character(char name): name{name} {}

void Character::notifyObservers() {
    for (auto &ob : observers) { ob->notify(*this);}
}

Stats Character::getStats() {
 return Stats{status.HP, status.Atk, status.Def, status.Gold};
}

void Character::setStats(Stats s) {
    status.HP = s.HP;
    status.Atk = s.Atk;
    status.Def = s.Def;
    status.Gold = s.Gold;
}

bool Character::move() {
 return canMove;
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
 if(damage1 > damage2) {
  return damage2 + 1;
 }
 return damage2;
}


void defend(Character &attacker) {
 attacker.attack(*this);
}

Character::~Character() {}

