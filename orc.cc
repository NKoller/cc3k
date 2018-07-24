#include "orc.h"
#include "goblin.h"

Orc::Orc(): Character{'O', true, 180, Stats{180, 30, 25, 1}} {} // make gold random

Orc::~Orc() {}

int Orc::defend(Character &attacker) {
	double damage = attacker.attack(*this);
	status.HP -= damage;
	if (status.HP < 0) status.HP = 0;
    return damage;
}

double Orc::attack(Goblin &defender) {
	return generalAttack(defender) * 1.5;
}
