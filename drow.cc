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
	status += p.getEffect() * 1.5;
	setState(State::UpdateTextdisplay);
	notifyObservers();
}

void Drow::reversePotions() {
	while (used.size()) {
		status += used[used.size()-1]->reverse() * 1.5;
		delete used[used.size()-1];
		used.pop_back();
	}
}

Drow::~Drow() {}
