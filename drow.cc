#include "drow.h"
#include "potion.h"

int Drow::defend(Character &attacker) {
		double damage = attacker.attack(*this);
		if (damage != Character::MISSED && damage != Character::NO_ATTACK) {
				status.HP -= damage;
				if (status.HP < 0) status.HP = 0;
				setState(State::UpdateTextdisplay);
				notifyObservers();
		}
		return damage;
}

Drow::Drow(): Player{150, Stats{150, 25, 15, 0}} {}

void Drow::use(Potion &p) {
		reverse += p.reverse() * 1.5;
		status += p.getEffect() * 1.5;
		if (status.HP > maxHP) status.HP = maxHP;
		else if (status.HP < 0) status.HP = 0;
		if (status.Atk < 0) status.Atk = 0;
		if (status.Def < 0) status.Def = 0;
		if (status.Gold < 0) status.Gold = 0;
		setState(State::UpdateTextdisplay);
		notifyObservers();
		checkIfDead();
}

Drow::~Drow() {}
