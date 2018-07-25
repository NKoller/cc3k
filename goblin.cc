#include "goblin.h"
  
int Goblin::defend(Character &attacker) {
    double damage = attacker.attack(*this);
	if (damage != Character::MISSED && damage != Character::NO_ATTACK) {
    	status.HP -= damage;
    	checkIfDead();
   		setState(State::UpdateTextdisplay);
    	notifyObservers();
	}
    return damage;
}

Goblin::Goblin(Observer* myTD): Player{110, Stats{110, 15, 20, 0}, myTD} {
    this->attach(myTD);
    setState(State::UpdateTextdisplay);
    notifyObservers();
}

Goblin::~Goblin() {}
