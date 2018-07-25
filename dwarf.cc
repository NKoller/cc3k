#include "dwarf.h"
  
Dwarf::Dwarf(): Character{'W', true, 100, Stats{100, 20, 30, 1}} {} //small pile for now

int Dwarf::defend(Character &attacker) {
	double damage = attacker.attack(*this);	
	if (damage != Character::MISSED && damage != Character::NO_ATTACK) {
		status.HP -= damage;
		if (status.HP < 0) status.HP = 0;
	}
    return damage;
}

Dwarf::~Dwarf() {}
