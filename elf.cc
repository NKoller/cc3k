#include "elf.h"

Elf::Elf(): Character{'E', true, Stats{140, 30, 10, 1}} {} // make gold random

Elf::~Elf() {}

void Elf::defend(Character &attacker) {
	double damage = attacker.attack(*this);
	status.HP -= damage;
	std::cout << "Owie! " << name << " took " << damage << " damage! ";
	std::cout << status.HP << " wittle HPs left..." << std::endl;
	checkIfDead();
}

//make attack twice

/*double Elf::attack(Drow &defender) {
	return calcDamage(status.Atk, defender.getStates().def);
	// make only attack once
}*/
