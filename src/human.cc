#include "human.h"

Human::Human(): Character{'H', true, 140, Stats{140, 20, 20, 0}} {}

Human::~Human() {}

void Human::checkIfDead() {
		if (status.HP <= 0) {
				setState(State::CharacterDied);
				notifyObservers();
		}
}

int Human::defend(Character &attacker) {
		double damage = attacker.attack(*this);
		if (damage != Character::MISSED && damage != Character::NO_ATTACK) {
				status.HP -= damage;
				if (status.HP < 0) status.HP = 0;
		}
		return damage;
}
