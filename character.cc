include "character.h"
#include "stats.h"
using namespace std;

Character::Character(char name): name{name} {}

void Character::notifyObservers(Stats s) {
   //for (auto &ob : observers) { ob->notify(*this);}
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
 float damage1 = ((100/(100+defender.getStats().Def))*attacker.getStats().Atk);
 int damage2 = ((100/(100+defender.getStats().Def))*attacker.getStats().Atk);
 if(damage1 > damage2) {
  return damage2 + 1;
 }
 return damage2;
}


void Character::defend(Character &attacker) {
 attacker.attack(*this);
}

void attack() {}

Character::~Character() {}
