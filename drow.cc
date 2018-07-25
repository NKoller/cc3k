#include "drow.h"
#include "potion.h"
  
int Drow::defend(Character &attacker) {
	double damage = attacker.attack(*this);
	if (damage != Character::MISSED && damage != Character::NO_ATTACK) {
	  	status.HP -= damage;
		checkIfDead();
		setState(State::UpdateTextdisplay);
		notifyObservers();
	}
	return damage;
}

Drow::Drow(Observer* myTD): Player{150, Stats{150, 25, 15, 0}, myTD} {
    this->attach(myTD);
    setState(State::UpdateTextdisplay);
    notifyObservers();
}

void Drow::use(Potion &p) {
	status += p.getEffect() * 1.5;
}

Drow::~Drow() {}
