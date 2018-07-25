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
    reverse += p.reverse();
	status += p.getEffect() * 1.5;
    if (status.HP > maxHP) status.HP = maxHP;
	setState(State::UpdateTextdisplay);
	notifyObservers();
}

void Drow::reversePotions() {
	status += reverse * 1.5;
}

Drow::~Drow() {}
