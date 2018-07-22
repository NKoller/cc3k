#include "dwarf.h"
  
Dwarf::Dwarf(): Character{'W', true ,Stats{100, 20, 30, 1}} {} //small pile for now

int Dwarf::returnGold() const {
	return 2 * this->getStats().Gold;
}

void Dwarf::defend(Character &attacker) {
	double damage = attacker.attack(*this);
	status.HP -= damage;
	std::cout << "Owie! " << name << " took " << damage << " damage! ";
	std::cout << status.HP << " wittle HPs left..." << std::endl;
	checkIfDead();
}

Dwarf::~Dwarf() {}
