#include "merchant.h"

bool Merchant::hostile = false;

Merchant::Merchant(): Character{'M', true, 30, Stats{30, 70, 5, 0}} {}

Merchant::~Merchant() {}

void Merchant::checkIfDead() {
		if (status.HP <= 0) {
				setState(State::CharacterDied);
				notifyObservers();
		}
}

int Merchant::defend(Character &attacker) {
		double damage = attacker.attack(*this);
		if (damage != Character::MISSED && damage != Character::NO_ATTACK) {
				status.HP -= damage;
				Merchant::hostile = true;
				if (status.HP < 0) status.HP = 0;
		}
		return damage;
}

double Merchant::generalAttack(Character &defender) {
		if (Merchant::hostile) {
				double damage = (100.0 / (100 + defender.getStats().Def)) * status.Atk;
				int trunc = damage;
				damage = (damage > trunc)? trunc + 1 : trunc;		
				int missed = rand() % 2;
				if (missed) return Character::MISSED;
				return damage;
		} else return Character::NO_ATTACK;
}
