#include "elf.h"
#include "drow.h"
#include "character.h"

Elf::Elf(): Character{'E', true, Stats{140, 30, 10, 1}} {} // make gold random

int Elf::defend(Character &attacker) {
 double damage = attacker.attack(*this);
 status.HP -= damage;
  std::cout << "Owie! " << name << " took " << damage << " damage! ";
  std::cout << status.HP << " wittle HPs left..." << std::endl;
 checkIfDead();
 return damage;
}

double Elf::generalAttack(Character &defender) {
	double damage = (100.0 / (100 + defender.getStats().Def)) * status.Atk;
	int trunc = damage;
	damage = (damage > trunc)? trunc + 1 : trunc;
	/*if(damage > defender.getStats().HP) { // might not be necessary if we throw exception
		return damage;
	}*/
	if (!attacking) {
		attacking = true;
		defender.defend(*this);
	} else {
		attacking = false;
	}
	return damage;
}

double Elf::attack(Drow &defender) {
	attacking = true;
	return generalAttack(defender);
}
