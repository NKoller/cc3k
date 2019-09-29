#include "shade.h"

int Shade::defend(Character &attacker) {
		double damage = attacker.attack(*this);
		if (damage != Character::MISSED && damage != Character::NO_ATTACK) {
				status.HP -= damage;
				if (status.HP < 0) status.HP = 0;
				setState(State::UpdateTextdisplay);
				notifyObservers();
		}
		return damage;
}

int Shade::getScore() const {
		return status.Gold * 1.5;
}

Shade::Shade(): Player{125, Stats{125, 25, 25, 0}} {}

Shade::~Shade() {}
