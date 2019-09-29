#include "halfling.h"

Halfling::Halfling(): Character{'L', true, 100, Stats{100, 15, 20, 0}} {}

Halfling::~Halfling() {}

int Halfling::defend(Character &attacker) {
		int missed = rand() % 2;
		if (missed) return Character::MISSED;
		else {
				double damage = attacker.attack(*this);
				if (damage != Character::MISSED && damage != Character::NO_ATTACK) {
						status.HP -= damage;
						if (status.HP < 0) status.HP = 0;
				}
				return damage;
		}
}
