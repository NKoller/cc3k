#include "troll.h"
  
int Troll::defend(Character &attacker) {
    double damage = attacker.attack(*this);
	if (damage != Character::MISSED && damage != Character::NO_ATTACK) {
    	status.HP -= damage;
    	checkIfDead();
    	setState(State::UpdateTextdisplay);
	    notifyObservers();
	}
    return damage;
}

Troll::Troll(Observer* myTD): Player{120, Stats{120, 25, 15, 0}, myTD} {
    this->attach(myTD);
    setState(State::UpdateTextdisplay);
    notifyObservers();
}

/*void finishTurn() {

}*/

Troll::~Troll() {}
