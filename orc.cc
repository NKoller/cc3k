#include "orc.h"

Orc::Orc(): Character{'O', true, Stats{180, 30, 25, 1}} {} // make gold random

Orc::~Orc() {}

int Orc::defend(Character &attacker) {
	double damage = attacker.attack(*this);
	status.HP -= damage;
	std::cout << "Owie! " << name << " took " << damage << " damage! ";
	std::cout << status.HP << " wittle HPs left..." << std::endl;
	checkIfDead();
    return damage;
}

/*double Orc::attack(Goblin &defender) {
	return calcDamage(status.Atk, defender.getStates().def) * 1.5;
}*/
