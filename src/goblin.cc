#include "goblin.h"

int Goblin::defend(Character &attacker) {
		double damage = attacker.attack(*this);
		if (damage != Character::MISSED && damage != Character::NO_ATTACK) {
				status.HP -= damage;
				if (status.HP < 0) status.HP = 0;
				setState(State::UpdateTextdisplay);
				notifyObservers();
		}
		return damage;
}

double Goblin::generalAttack(Character &defender) {
		double damage = (100.0 / (100 + defender.getStats().Def)) * status.Atk;
		int trunc = damage;
		damage = (damage > trunc)? trunc + 1 : trunc;

		if (damage >= defender.getStats().HP) {
				status.Gold += 5;
				setState(State::UpdateTextdisplay);
				notifyObservers();
		}
		return damage;
}

Goblin::Goblin(): Player{110, Stats{110, 15, 20, 0}} {}

Goblin::~Goblin() {}
