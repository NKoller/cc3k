#include "shade.h"

void Shade::defend(Character &attacker) {
	double damage = attacker.attack(*this);
	status.HP -= damage;
	std::cout << "Owie! " << name << " took " << damage << " damage! ";
	std::cout << status.HP << " wittle HPs left..." << std::endl;
	checkIfDead();
}

Shade::Shade(): Player{Stats{125, 25, 25, 0}} {}

Shade::~Shade() {}
