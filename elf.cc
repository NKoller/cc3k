#include "elf.h"
#include "drow.h"
#include "character.h"

Elf::Elf(): Character{'E', true, Stats{140, 30, 10, 1}} {} // make gold random

Elf::~Elf() {}

int Elf::defend(Character &attacker) {
 double damage = attacker.attack(*this);
 status.HP -= damage;
  std::cout << "Owie! " << name << " took " << damage << " damage! ";
  std::cout << status.HP << " wittle HPs left..." << std::endl;
 checkIfDead();
 return damage;
}

int times = 0;
double damage1 = 0 ,damage = 0;
double Elf::attack(Drow &defender) {
  if(times == 2) {
    return damage1 + damage;
  }
  double damage = (100.0 / (100 + defender.getStats().Def)) * status.Atk;
  int trunc = damage;
  damage1 = (damage > trunc)? trunc + 1 : trunc;
  ++times;
  if(damage > defender.getStats().HP) {
   return damage;
  }
  return generalAtk(defender);
}       

/*double Elf::attack(Drow &defender) {
	return calcDamage(status.Atk, defender.getStates().def);
	// make only attack once
}*/
