#include "halfling.h"

Halfling::Halfling(): Character{'L', true, Stats{100, 15, 20, 0}} {}

Halfling::~Halfling() {}

void Halfling::defend(Character &attacker) {
	// 50% chance to do nothing

	double damage = attacker.attack(*this);
	status.HP -= damage;
	std::cout << "Owie! " << name << " took " << damage << " damage! ";
	std::cout << status.HP << " wittle HPs left..." << std::endl;
	checkIfDead();
}
