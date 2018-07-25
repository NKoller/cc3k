#include "vampire.h"
#include "dwarf.h"
#include <limits>

int Vampire::defend(Character &attacker) {
		double damage = attacker.attack(*this);
		if (damage != Character::MISSED && damage != Character::NO_ATTACK) {
				status.HP -= damage;
				if (status.HP < 0) status.HP = 0;
				setState(State::UpdateTextdisplay);
				notifyObservers();
		}
		return damage;
}

double Vampire::generalAttack(Character &defender) {
		double damage = (100.0 / (100 + defender.getStats().Def)) * status.Atk;
		int trunc = damage;
		damage = (damage > trunc)? trunc + 1 : trunc;

		status.HP += 5;
		setState(State::UpdateTextdisplay);
		notifyObservers();
		return damage;
}

double Vampire::attack(Dwarf &defender) {
		double damage = (100.0 / (100 + defender.getStats().Def)) * status.Atk;
		int trunc = damage;
		damage = (damage > trunc)? trunc + 1 : trunc;

		status.HP -= 5;
		setState(State::UpdateTextdisplay);
		notifyObservers();
		return damage;
}

Vampire::Vampire():	Player{std::numeric_limits<int>::max(), Stats{50, 25, 25, 0}} {}

Vampire::~Vampire() {}
