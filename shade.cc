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

Shade::Shade(Observer* myTD): Player{125, Stats{125, 1000, 25, 0}, myTD} {
    this->attach(myTD);
    setState(State::UpdateTextdisplay);
    notifyObservers();
}

Shade::~Shade() {}
