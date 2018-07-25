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
    Stats test = (p.getEffect() * 1.5);
	status += p.getEffect() * 1.5;
	setState(State::UpdateTextdisplay);
	notifyObservers();
}

void Drow::reversePotions() {
	status += reverse * 1.5;
}

Drow::~Drow() {}
