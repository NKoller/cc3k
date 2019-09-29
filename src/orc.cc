#include "orc.h"
#include "goblin.h"

Orc::Orc(): Character{'O', true, 180, Stats{180, 30, 25, 0}} {}

Orc::~Orc() {}

int Orc::defend(Character &attacker) {
		double damage = attacker.attack(*this);
		if (damage != Character::MISSED && damage != Character::NO_ATTACK) {
				status.HP -= damage;
				if (status.HP < 0) status.HP = 0;
		}
		return damage;
}

double Orc::attack(Goblin &defender) {
		double damage = generalAttack(defender);
		if (damage == Character::MISSED || damage == Character::NO_ATTACK) {
				return damage;
		} else {
				return generalAttack(defender) * 1.5;
		}
}
